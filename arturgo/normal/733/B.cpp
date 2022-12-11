#include <iostream>
using namespace std;

int gauches[100 * 1000 + 42];
int droites[100 * 1000 + 42];

int sommeGauche = 0, sommeDroite = 0;

int main() {
	int nbCols;
	cin >> nbCols;
	
	for(int iCol = 0;iCol < nbCols;iCol++) {
		cin >> gauches[iCol] >> droites[iCol];
		sommeGauche += gauches[iCol];
		sommeDroite += droites[iCol];
	}
	
	int maxBeaute = abs(sommeGauche - sommeDroite);
	int melMvt = 0;
	for(int iCol = 0;iCol < nbCols;iCol++) {
		int curBeaute = abs(sommeGauche - 2 * gauches[iCol] + 2 * droites[iCol] - sommeDroite);
		if(curBeaute > maxBeaute) {
			maxBeaute = curBeaute;
			melMvt = iCol + 1;
		}
	}
	
	cout << melMvt << endl;
	return 0;
}