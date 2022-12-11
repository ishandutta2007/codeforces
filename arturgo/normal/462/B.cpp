#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <iomanip>
#include <queue>
using namespace std;

int occs[26];
string cartes;

int main() {	
	int nbCartes, nbPrises;
	cin >> nbCartes >> nbPrises;
	
	cin >> cartes;
	
	for(char carte : cartes) {
		occs[carte - 'A']++;
	}
	
	sort(occs, occs + 26);
	
	long long val = 0;
	
	for(int i = 25;i >= 0;i--) {
		long long cur = min(nbPrises, occs[i]);
		val += cur * cur;
		nbPrises -= cur;
	}
	
	cout << val << endl;
	return 0;
}