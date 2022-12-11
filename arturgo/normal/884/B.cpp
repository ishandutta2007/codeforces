#include <iostream>
using namespace std;

int main() {
	int nbElems, taille;
	cin >> nbElems >> taille;
	
	int somme = -1;
	for(int iElem = 0;iElem < nbElems;iElem++) {
		int t;
		cin >> t;
		somme += t + 1;
	}
	
	if(somme == taille) {
		cout << "YES" << endl;
	}
	else {
		cout << "NO" << endl;
	}
	return 0;
}