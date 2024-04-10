#include <iostream>
#include <cmath>
#include <list>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;

const int MAX_NB_TOURS = 100 * 1000 + 1;

int nbTours, nbTypes; 
double expect[2][700];
double cumul[700];

int main() {
	cin >> nbTours >> nbTypes;

	for(int iTour = nbTours;iTour > 0;iTour--) {
		int c = iTour % 2;
		int n = 1 - c;
		
		for(int iPos = 1;iPos < 600;iPos++) {
			cumul[iPos] = cumul[iPos - 1] + expect[c][iPos];
		}
		
		
		for(int iLevel = 1;iLevel < min(600, iTour + 2);iLevel++) {
			expect[n][iLevel] = (nbTypes - 1) * expect[c][iLevel] / nbTypes;
			expect[n][iLevel] += iLevel * ((iLevel + 1.) / 2 + expect[c][iLevel]) / nbTypes / (iLevel + 1);
			expect[n][iLevel] += (iLevel + expect[c][iLevel + 1]) / nbTypes / (iLevel + 1);
		}
	}
	
	cout << fixed << setprecision(12);
	cout << nbTypes * expect[0][1] << endl;
}