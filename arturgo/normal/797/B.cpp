#include <iostream>
using namespace std;

int main() {
	int nbElems;
	cin >> nbElems;
	
	int minPos = 1000 * 1000;
	int maxNeg = -1000 * 1000;
	
	long long somme = 0;
	
	for(int iElem = 0;iElem < nbElems;iElem++) {
		int val;
		cin >> val;
		
		if(val >= 0) {
			somme += val;
			if(val % 2 != 0) {
				minPos = min(minPos, val);
			}
		}
		else if( val % 2 != 0 ) {
			maxNeg = max(maxNeg, val);
		}
	}
	
	if(somme % 2 == 0) {
		somme = max(somme + maxNeg, somme - minPos);
	}
	
	cout << somme << endl;
}