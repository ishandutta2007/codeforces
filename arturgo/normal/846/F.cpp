#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

int nbNombres;
int nombres[2000 * 1000 + 1];

vector<int> paliers[2000 * 1000 + 1];

int main() {
	ios_base::sync_with_stdio(false);
	cin >> nbNombres;
	
	for(int iNombre = 0;iNombre < nbNombres;iNombre++) {
		cin >> nombres[iNombre];
		paliers[nombres[iNombre]].push_back(iNombre);
	}
	
	long long nbInters = nbNombres * (long long)nbNombres;
	
	long long nbUniques = 0, nbDiffs = 0;
	
	for(int iVal = 0;iVal <= 2000 * 1000;iVal++) {
		if((int)paliers[iVal].size() == 0)
			continue;
		nbDiffs ++;
		nbUniques += paliers[iVal][0] * (long long)paliers[iVal][0];
		for(int iPos = 0;iPos < (int)paliers[iVal].size();iPos++) {
			long long cur = paliers[iVal][iPos] + 1;
			long long fin = nbNombres;
			if(iPos != (int)paliers[iVal].size() - 1)
				fin = paliers[iVal][iPos + 1];
			
			nbUniques += (fin - cur) * (fin - cur);
		}
	}
	
	cout << nbDiffs - (long double)nbUniques / nbInters << endl;
	return 0;
}