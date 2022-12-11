#include <iostream>
using namespace std;

int tab[5][5];

void inverse(int l, int c) {
	tab[l][c] ^= 1;
	tab[l + 1][c] ^= 1;
	tab[l - 1][c] ^= 1;
	tab[l][c + 1] ^= 1;
	tab[l][c - 1] ^= 1;
}

int main() {
	for(int iLig = 1;iLig <= 3;iLig++) {
		for(int iCol = 1;iCol <= 3;iCol++) {
			int nbFois;
			cin >> nbFois;
			if(nbFois % 2)
				inverse(iLig, iCol);
		}
	}
	
	for(int iLig = 1;iLig <= 3;iLig++) {
		for(int iCol = 1;iCol <= 3;iCol++) {
			cout << !tab[iLig][iCol];
		}
		cout << endl;
	}
	
	return 0;
}