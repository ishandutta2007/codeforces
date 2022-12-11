#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	int nbNombres;
	cin >> nbNombres;
	
	vector<long long> entiers;
	
	for(int iN = 0;iN < nbNombres;iN++) {
		long long a;
		cin >> a;
		entiers.push_back(a);
	}
	
	sort(entiers.begin(), entiers.end());
	
	vector<long long> diffs;
	
	for(int iN = 0;iN < nbNombres;iN++) {
		if(diffs.empty()) {
			diffs.push_back(entiers[iN]);
		}
		else if(diffs.back() != entiers[iN]) {
			diffs.push_back(entiers[iN]);
		}
	}
	
	if(diffs.size() > 3)
		cout << "NO" << endl;
	else if(diffs.size() == 3) {
		if(diffs[1] - diffs[0] == diffs[2] - diffs[1])
			cout << "YES" << endl;
		else 
			cout << "NO" << endl;
	}
	else {
		cout << "YES" << endl;
	}
	return 0;
}