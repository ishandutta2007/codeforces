#include <iostream>
using namespace std;

bool matrice[300][300];

int coudes(int a, int b) {
	int n = 0;
	for(int c = 0;c < 100;c++) {
		if(matrice[a][c] && matrice[c][b])
			n++;
	}
	return n;
}

int main() {
	int nbCycles;
	cin >> nbCycles;
	
	int iNoeud1 = 0;
	for(;iNoeud1 < 100;iNoeud1++) {
		for(int iNoeud2 = 0;iNoeud2 < iNoeud1;iNoeud2++) {
			int nbCoudes = coudes(iNoeud1, iNoeud2);
			if(nbCoudes <= nbCycles) {
				nbCycles -= nbCoudes;
				matrice[iNoeud1][iNoeud2] = true;
				matrice[iNoeud2][iNoeud1] = true;
			}
		}
		
		if(nbCycles == 0)
			break;
	}
	
	cout << iNoeud1 + 1 << endl;
	for(int iLig = 0;iLig <= iNoeud1;iLig++) {
		for(int iCol = 0;iCol <= iNoeud1;iCol++) {
			cout << matrice[iLig][iCol];
		}
		cout << endl;
	}
}