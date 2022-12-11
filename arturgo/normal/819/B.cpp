#include <iostream>
using namespace std;

int nombres[1000 * 1000];
int valChange[1000 * 1000];

int main() {
	int nbNombres;
	cin >> nbNombres;
	
	long long cur = 0;
	
	int nbChange = 0;
	for(int iNombre = 0;iNombre < nbNombres;iNombre++) {
		cin >> nombres[iNombre];
		nombres[iNombre]--;
		
		cur += abs(nombres[iNombre] - iNombre);
		
		if(nombres[iNombre] < iNombre) {
			nbChange++;
			valChange[nbNombres + nombres[iNombre] - iNombre] += 2;
		}
		else {
			nbChange--;
			valChange[nombres[iNombre] - iNombre] += 2;
		}
	}
	
	long long mini = cur;
	int posMini = 0;
	
	for(int iFois = 0;iFois < nbNombres;iFois++) {
		if(cur < mini) {
			mini = cur;
			posMini = iFois;
		}
		
		nbChange += valChange[iFois];
		
		cur -= abs(nombres[nbNombres - iFois - 1] - (nbNombres - 1));
		cur += abs(nombres[nbNombres - iFois - 1]);
		
		nbChange--;
		
		cur += nbChange;
		
		nbChange--;
	}
	
	cout << mini << " " << posMini << endl;
	return 0;
}