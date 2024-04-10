#include <iostream>
#include <algorithm>
using namespace std;

const int INFINI = 2000 * 1000 * 1000;

int nbLigs, nbCols, carre, nbPixels;

int temps[501][501];
int m[10][501][501];

int main() {
	ios_base::sync_with_stdio(false);
	cin >> nbLigs >> nbCols >> carre >> nbPixels;
	
	for(int iLig = 0;iLig < nbLigs;iLig++) {
		for(int iCol = 0;iCol < nbCols;iCol++) {
			temps[iLig][iCol] = INFINI;
		}
	}
	
	for(int iPixel = 0;iPixel < nbPixels;iPixel++) {
		int lig, col, t;
		cin >> lig >> col >> t;
		temps[lig - 1][col - 1] = min(temps[lig - 1][col - 1], t);
	}
	
	for(int iLig = 0;iLig < nbLigs;iLig++) {
		for(int iCol = 0;iCol < nbCols;iCol++) {
			m[0][iLig][iCol] = temps[iLig][iCol];
		}
	}
	
	for(int iP = 1;iP < 10;iP++) {
		for(int iLig = 0;iLig <= nbLigs - (1 << iP);iLig++) {
			for(int iCol = 0;iCol <= nbCols - (1 << iP);iCol++) {
				m[iP][iLig][iCol] = 0;
				m[iP][iLig][iCol] = max(m[iP][iLig][iCol],
					m[iP-1][iLig][iCol]
				);
				m[iP][iLig][iCol] = max(m[iP][iLig][iCol],
					m[iP-1][iLig + (1 << iP)/2][iCol]
				);
				m[iP][iLig][iCol] = max(m[iP][iLig][iCol],
					m[iP-1][iLig][iCol + (1 << iP)/2]
				);
				m[iP][iLig][iCol] = max(m[iP][iLig][iCol],
					m[iP-1][iLig + (1 << iP)/2][iCol + (1 << iP)/2]
				);
			}
		}
	}
	
	int l = __builtin_log2(carre);
	int mini = INFINI;
	for(int iLig = 0;iLig <= nbLigs - carre;iLig++) {
		for(int iCol = 0;iCol <= nbCols - carre;iCol++) {
			int maxi = 0;
			maxi = max(maxi, m[l][iLig][iCol]);
			maxi = max(maxi, m[l][iLig][iCol + carre - (1 << l)]);
			maxi = max(maxi, m[l][iLig + carre - (1 << l)][iCol]);
			maxi = max(maxi, m[l][iLig + carre - (1 << l)][iCol + carre - (1 << l)]);
			
			mini = min(mini, maxi);
		}
	}
	
	if(mini == INFINI)
		cout << -1 << endl;
	else
		cout << mini << endl;
}