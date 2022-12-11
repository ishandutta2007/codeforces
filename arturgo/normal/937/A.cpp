#include <iostream>
using namespace std;

bool presents[1000 * 1000];

int main() {
	int nbNombres;
	cin >> nbNombres;
	
	for(int iNombre = 0;iNombre < nbNombres;iNombre++) {
		int nombre;
		cin >> nombre;
		presents[nombre] = true;
	}
	
	int nbPresents = 0;
	
	for(int i = 1;i < 1000 * 1000;i++) {
		if(presents[i])
			nbPresents++;
	}
	
	cout << nbPresents << endl;
	return 0;
}