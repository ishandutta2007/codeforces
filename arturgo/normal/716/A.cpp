#include <iostream>
using namespace std;

int main() {
	int nbMots, temps;
	cin >> nbMots >> temps;
	
	int nbEcran = 0;
	int derMot = 0;
	for(int iMot = 0;iMot < nbMots;iMot++) {
		int curMot;
		cin >> curMot;
		
		if(curMot - derMot > temps)
			nbEcran = 0;
		nbEcran++;
		
		derMot = curMot;
	}
	
	cout << nbEcran << endl;
}