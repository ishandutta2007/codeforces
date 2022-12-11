#include <iostream>
using namespace std;

int nombres[3000];

int pgcd(int a, int b) {
	if(a == 0)
		return b;
	return pgcd(b % a, a);
}

int main() {
	ios_base::sync_with_stdio(false);
	int nbNombres;
	cin >> nbNombres;
	
	int nbDiffs = 0;
	for(int iNombre = 0;iNombre < nbNombres;iNombre++) {
		cin >> nombres[iNombre];
		if(nombres[iNombre] != 1)
			nbDiffs++;
	}
	
	int minPourUn = 10000;
	
	for(int iDebut = 0;iDebut < nbNombres;iDebut++) {
		int pgcdInter = 0;
		for(int iFin = iDebut;iFin < nbNombres;iFin++) {
			pgcdInter = pgcd(pgcdInter, nombres[iFin]);
			if(pgcdInter == 1) {
				minPourUn = min(minPourUn, iFin - iDebut);
			}
		}
	}
	
	if(minPourUn >= 10000) {
		cout << -1 << endl;
	}
	else if(nbDiffs != nbNombres) {
		cout << nbDiffs << endl;
	}
	else {
		cout << nbDiffs + minPourUn - 1 << endl;
	}
	return 0;
}