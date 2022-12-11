#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;

long long cumul[200 * 1000 + 1];

int main() {
	int nbNombres, taille;
	cin >> nbNombres >> taille;
	
	for(int iNombre = 0;iNombre < nbNombres;iNombre++) {
		int nombre;
		cin >> nombre;
		cumul[iNombre + 1] = cumul[iNombre] + nombre;
	}
	
	long long somme = 0;
	for(int iNombre = 0;iNombre < nbNombres - taille + 1;iNombre++) {
		somme += cumul[iNombre + taille] - cumul[iNombre];
	}
	
	cout << fixed << setprecision(8);
	cout << somme / (double)(nbNombres - taille + 1) << endl;
	return 0;
}