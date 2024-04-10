#include <iostream>
#include <cmath>
#include <list>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;

int nbLigs, nbCols;

int debut = 0;
list<int> pos[100];

int solve(int lig, int cote) {
	if(pos[lig].empty())
		return solve(lig - 1, cote) + 1;
	
	if(lig == debut) {
		if(cote == 0)
			return pos[lig].back();
		else
			return nbCols - pos[lig].front() - 1;
	}
	
	if(cote == 0) {
		return min(
			solve(lig - 1, 0) + 2 * pos[lig].back() + 1,
			solve(lig - 1, 1) + nbCols
		);
	}
	else {
		return min(
			solve(lig - 1, 0) + nbCols,
			solve(lig - 1, 1) + 2 * (nbCols - pos[lig].front() - 1) + 1
		);
	}
}

int main() {
	cin >> nbLigs >> nbCols;
	nbCols += 2;
	
	for(int iLig = 0;iLig < nbLigs;iLig++) {
		for(int iCol = 0;iCol < nbCols;iCol++) {
			char car;
			cin >> car;
			if(car == '1')
				pos[iLig].push_back(iCol);
		}
	}
	
	while(debut < nbLigs && pos[debut].empty()) {
		debut++;
	}
	
	if(debut == nbLigs)
		cout << 0 << endl;
	else
		cout << solve(nbLigs - 1, 0) << endl;
}