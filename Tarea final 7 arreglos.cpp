#include <iostream>
using namespace std;

int main() {
    // Constante para el máximo de estudiantes
    const int MAX_ESTUDIANTES = 20;
    const int NUM_CALIFICACIONES = 4;

    // Arreglos
    double calificaciones[MAX_ESTUDIANTES][NUM_CALIFICACIONES]; // Matriz para guardar 4 notas por estudiante
    double promedios[MAX_ESTUDIANTES]; // Arreglo para guardar el promedio de cada estudiante

    int numEstudiantes;

    // ===== 1. Solicitar cantidad de estudiantes =====
    cout << "=== GESTION DE CALIFICACIONES ===" << endl;
    cout << "Ingrese la cantidad de estudiantes (maximo " << MAX_ESTUDIANTES << "): ";
    cin >> numEstudiantes;

    // Validar que no exceda el máximo
    while (numEstudiantes <= 0 || numEstudiantes > MAX_ESTUDIANTES) {
        cout << "Cantidad invalida. Ingrese un numero entre 1 y " << MAX_ESTUDIANTES << ": ";
        cin >> numEstudiantes;
    }

    // ===== 2. Ingresar calificaciones =====
    cout << "\n--- Ingreso de calificaciones ---" << endl;
    for (int i = 0; i < numEstudiantes; i++) {
        cout << "\nEstudiante " << i + 1 << ":" << endl;

        double suma = 0; // Acumulador para las 4 notas

        for (int j = 0; j < NUM_CALIFICACIONES; j++) {
            do {
                cout << "  Calificacion " << j + 1 << " (0-100): ";
                cin >> calificaciones[i][j];

                // Validar rango
                if (calificaciones[i][j] < 0 || calificaciones[i][j] > 100) {
                    cout << "  Error: La calificacion debe estar entre 0 y 100." << endl;
                }
            } while (calificaciones[i][j] < 0 || calificaciones[i][j] > 100);

            suma += calificaciones[i][j]; // Acumular para el promedio
        }

        // Calcular promedio del estudiante
        promedios[i] = suma / NUM_CALIFICACIONES;
    }

    // ===== 3. Mostrar calificaciones y promedio de cada estudiante =====
    cout << "\n=== RESULTADOS INDIVIDUALES ===" << endl;
    for (int i = 0; i < numEstudiantes; i++) {
        cout << "\nEstudiante " << i + 1 << ":" << endl;
        cout << "  Calificaciones: ";

        for (int j = 0; j < NUM_CALIFICACIONES; j++) {
            cout << calificaciones[i][j];
            if (j < NUM_CALIFICACIONES - 1) cout << ", ";
        }

        cout << endl;
        cout << "  Promedio: " << promedios[i] << endl;
    }

    // ===== 4. Calcular estadísticas generales =====
    double sumaTotal = 0;
    double calificacionMasAlta = promedios[0];
    double calificacionMasBaja = promedios[0];
    int aprobados = 0;
    int reprobados = 0;

    for (int i = 0; i < numEstudiantes; i++) {
        // Sumar para promedio general
        sumaTotal += promedios[i];

        // Calificación más alta y más baja (basado en promedios)
        if (promedios[i] > calificacionMasAlta) {
            calificacionMasAlta = promedios[i];
        }
        if (promedios[i] < calificacionMasBaja) {
            calificacionMasBaja = promedios[i];
        }

        // Contar aprobados y reprobados (70 es la nota mínima aprobatoria)
        if (promedios[i] >= 70) {
            aprobados++;
        }
        else {
            reprobados++;
        }
    }

    double promedioGeneral = sumaTotal / numEstudiantes;

    // ===== 5. Mostrar resultados finales =====
    cout << "\n=== ESTADISTICAS GENERALES ===" << endl;
    cout << "Promedio general del grupo: " << promedioGeneral << endl;
    cout << "Calificacion mas alta (promedio): " << calificacionMasAlta << endl;
    cout << "Calificacion mas baja (promedio): " << calificacionMasBaja << endl;
    cout << "Estudiantes aprobados (>=70): " << aprobados << endl;
    cout << "Estudiantes reprobados (<70): " << reprobados << endl;

    cout << "\n=== FIN DEL PROGRAMA ===" << endl;

    return 0;
}