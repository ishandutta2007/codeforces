#include <iostream>
using namespace std;

string etat[10];

int deps[4][2] = {
	{1, 0},
	{1, 1},
	{0, 1},
	{-1, 1}
};

bool estGagnant() {
	for(int iLig = 0;iLig < 10;iLig++) {
		for(int iCol = 0;iCol < 10;iCol++) {
			for(int iDep = 0;iDep < 4;iDep++) {
				bool estValide = true;
				for(int iFois = 0;iFois < 5;iFois++) {
					int lig = iLig + iFois * deps[iDep][0];
					int col = iCol + iFois * deps[iDep][1];
					
					if(lig < 0 || lig >= 10 || col < 0 || col >= 10) {
						estValide = false;
					}
					else if(etat[lig][col] != 'X') {
						estValide = false;
					}
				}
				
				if(estValide)
					return true;
			}
		}
	}
	return false;
}

int main() {
	for(int iLigne = 0;iLigne < 10;iLigne++) {
		cin >> etat[iLigne];
	}
	
	for(int iLigne = 0;iLigne < 10;iLigne++) {
		for(int iCol = 0;iCol < 10;iCol++) {
			if(etat[iLigne][iCol] == '.') {
				etat[iLigne][iCol] = 'X';
				
				if(estGagnant()) {
					cout << "YES" << endl;
					return 0;
				}
				
				etat[iLigne][iCol] = '.';
			}
		}
	}
	
	cout << "NO" << endl;
}