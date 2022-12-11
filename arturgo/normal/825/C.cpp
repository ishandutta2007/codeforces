#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> diffs;

int main() {
	int nbProblemes, minDiff;
	cin >> nbProblemes >> minDiff;
	
	for(int i = 0;i < nbProblemes;i++) {
		int diff;
		cin >> diff;
		
		if(diff > minDiff)
			diffs.push_back(diff);
	}
	
	sort(diffs.begin(), diffs.end());
	
	int nbFois = 0;
	for(int pb : diffs) {
		while(minDiff * 2 < pb) {
			minDiff *= 2;
			nbFois++;
		}
		minDiff = max(minDiff, pb);
	}
	
	cout << nbFois << endl;
	return 0;
}