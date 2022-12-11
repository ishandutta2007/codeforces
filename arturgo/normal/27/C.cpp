#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <iomanip>
#include <queue>
using namespace std;

int nombres[100 * 1000];

int maxiDroite[100 * 1000];
int miniDroite[100 * 1000];
int maxiGauche[100 * 1000];
int miniGauche[100 * 1000];

int main() {
	int nbNombres;
	cin >> nbNombres;
	
	for(int iNombre = 0;iNombre < nbNombres;iNombre++) {
		cin >> nombres[iNombre];
		if(iNombre >= 1) {
			miniGauche[iNombre] = miniGauche[iNombre - 1];
			maxiGauche[iNombre] = maxiGauche[iNombre - 1];
			if(nombres[miniGauche[iNombre]] > nombres[iNombre])
				miniGauche[iNombre] = iNombre;
			if(nombres[maxiGauche[iNombre]] < nombres[iNombre])
				maxiGauche[iNombre] = iNombre;
		}
		else {
			miniGauche[iNombre] = maxiGauche[iNombre] = iNombre;
		}
	}
	
	for(int iNombre = nbNombres - 1;iNombre >= 0;iNombre--) {
		if(iNombre <= nbNombres - 2) {
			miniDroite[iNombre] = miniDroite[iNombre + 1];
			maxiDroite[iNombre] = maxiDroite[iNombre + 1];
			if(nombres[miniDroite[iNombre]] > nombres[iNombre])
				miniDroite[iNombre] = iNombre;
			if(nombres[maxiDroite[iNombre]] < nombres[iNombre])
				maxiDroite[iNombre] = iNombre;
		}
		else {
			miniDroite[iNombre] = maxiDroite[iNombre] = iNombre;
		}
	}
	
	for(int iNombre = 1;iNombre < nbNombres - 1;iNombre++) {
		if(nombres[maxiDroite[iNombre + 1]] > nombres[iNombre] && nombres[maxiGauche[iNombre - 1]] > nombres[iNombre]) {
			cout << 3 << endl;
			cout << 1 + maxiGauche[iNombre] << " " << 1 + iNombre << " " << 1 + maxiDroite[iNombre] << endl;
			return 0;
		}
		else if(nombres[miniDroite[iNombre + 1]] < nombres[iNombre] && nombres[miniGauche[iNombre - 1]] < nombres[iNombre]) {
			cout << 3 << endl;
			cout << 1 + miniGauche[iNombre] << " " << 1 + iNombre << " " << miniDroite[iNombre] + 1 << endl;
			return 0;
		}
	}
	
	cout << 0 << endl;
	return 0;
}