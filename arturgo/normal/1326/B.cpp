#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);

	int nbNombres;
	cin >> nbNombres;

	int maxi = 0;
	for(int iNombre = 0;iNombre < nbNombres;iNombre++) {
		int nombre;
		cin >> nombre;

		cout << nombre + maxi << " ";
		maxi = max(maxi, nombre + maxi);
	}

	cout << endl;
	return 0;
}