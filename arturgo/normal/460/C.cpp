#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <iomanip>
#include <queue>
using namespace std;

const int INFINI = 2000 * 1000 * 1000;

int nbNombres, nbInters, taille;
int nombres[100 * 1000];

bool estPossible(long long mini) {
	long long ajouts[500 * 1000];
	
	fill(ajouts, ajouts + 500 * 1000, 0);
	
	long long ut = 0;
	
	long long nbAjouts = 0;
	for(int iNombre = 0;iNombre < nbNombres;iNombre++) {
		nbAjouts -= ajouts[iNombre];
		if(nombres[iNombre] + nbAjouts < mini) {
			long long aj = mini - (nombres[iNombre] + nbAjouts);
			ut += aj;
			nbAjouts += aj;
			ajouts[iNombre + taille] += aj;
		}
	}
	
	return ut <= nbInters;
}

int main() {	
	cin >> nbNombres >> nbInters >> taille;
	
	for(int iNombre = 0;iNombre < nbNombres;iNombre++) {
		cin >> nombres[iNombre];
	}
	
	long long debut = 0, fin = INFINI;
	while(debut + 1 < fin) {
		long long mil = (debut + fin) / 2;
		if(estPossible(mil)) {
			debut = mil;
		}
		else {
			fin = mil;
		}
	}
	
	cout << debut << endl;
	return 0;
}