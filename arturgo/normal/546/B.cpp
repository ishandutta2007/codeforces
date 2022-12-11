#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <iomanip>
#include <queue>
using namespace std;

int occs[100 * 1000];

int main() {
	int nbBadges;
	cin >> nbBadges;
	
	for(int iBadge = 0;iBadge < nbBadges;iBadge++) {
		int val; cin >> val;
		occs[val]++;
	}
	
	int nbEtapes = 0;
	for(int iVal = 0;iVal < 100 * 1000;iVal++) {
		if(occs[iVal] >= 2) {
			nbEtapes += occs[iVal] - 1;
			occs[iVal + 1] += occs[iVal] - 1;
		}
	}
	
	cout << nbEtapes << endl;
	return 0;
}