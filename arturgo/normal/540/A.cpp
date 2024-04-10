#include <iostream>
using namespace std;

int main() {
	int nbRoues;
	cin >> nbRoues;
	
	string a, b;
	cin >> a >> b;
	
	int somme = 0;
	for(int iCar = 0;iCar < (int)a.size();iCar++) {
		int nbDeps = abs(a[iCar] - b[iCar]);
		nbDeps = min(nbDeps, 10 - nbDeps);
		
		somme += nbDeps;
	}
	
	cout << somme << endl;
	return 0;
}