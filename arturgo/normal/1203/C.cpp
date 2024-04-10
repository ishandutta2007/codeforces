#include <iostream>
#include <algorithm>
using namespace std;

int nbDiviseurs(long long nombre) {
	long long resultat = 0, diviseur = 1;
	for(;diviseur * diviseur < nombre;diviseur++) {
		if(nombre % diviseur == 0) {
			resultat += 2;
		}
	}

	if(diviseur * diviseur == nombre)
		resultat++;

	return resultat;
}

int main() {
	ios_base::sync_with_stdio(false);
	int nbNombres;
	cin >> nbNombres;

	long long pgcd = 0;
	for(int iNombre = 0;iNombre < nbNombres;iNombre++) {
		long long nombre;
		cin >> nombre;
		pgcd = __gcd(nombre, pgcd);
	}

	cout << nbDiviseurs(pgcd) << endl;
	return 0;
}