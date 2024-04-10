#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int nbNombres;
vector<int> nombres;

int nbCoups() {
	int nbC = 0;
	for(int iPos = 1;iPos < nbNombres - 1;iPos++) {
		while(nombres[iPos - 1]%2 != 0) {
			nbC++;
			int tA = nombres[iPos - 1] - nombres[iPos];
			int tB = nombres[iPos - 1] + nombres[iPos];
			nombres[iPos - 1] = tA;
			nombres[iPos] = tB;
		}
	}
	
	while(nombres[nbNombres - 2]%2 != 0 || nombres[nbNombres - 1]%2 != 0) {
		nbC++;
		int tA = nombres[nbNombres - 2] - nombres[nbNombres - 1];
		int tB = nombres[nbNombres - 2] + nombres[nbNombres - 1];
		nombres[nbNombres - 2] = tA;
		nombres[nbNombres - 1] = tB;
	}
	
	return nbC;
}

int pgcd(int a, int b) {
	if(a == 0)
		return b;
	return pgcd(b % a, a);
}

int ppcm(int a, int b) {
	return a / pgcd(a, b) * b;
}

int get() {
	int pg = 0;
	for(int iVal = 0;iVal < nbNombres;iVal++) {
		pg = pgcd(pg, nombres[iVal]);
	}
	return pg;
}

int main() {
	cin >> nbNombres;
	
	for(int iNombre = 0;iNombre < nbNombres;iNombre++) {
		int n;
		cin >> n;
		nombres.push_back(n);
	}
	
	cout << "YES" << endl;
	if(get() > 1) {
		cout << 0 << endl;
		return 0;
	}
	
	cout << nbCoups() << endl;
	return 0;
}