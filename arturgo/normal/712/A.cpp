#include <iostream>
using namespace std;

int main() {
	int nbNombres;
	cin >> nbNombres;
	
	int der = 0;
	cin >> der;
	for(int iNombre = 1;iNombre < nbNombres;iNombre++) {
		int cur;
		cin >> cur;
		cout << der + cur << " ";
		der = cur;
	}
	cout << der << endl;
	return 0;
}