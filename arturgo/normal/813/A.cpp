#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <iomanip>
#include <queue>
using namespace std;

const long long INFINI = (long long)1000 * 1000 * 1000 * 1000;

int main() {	
	long long nbProbs;
	cin >> nbProbs;
	
	long long maxTemps = 0;
	for(long long iProb = 0;iProb < nbProbs;iProb++) {
		long long temps;
		cin >> temps;
		
		maxTemps += temps;
	}
	
	long long nbPeriodes;
	cin >> nbPeriodes;
	
	long long minTemps = INFINI;
	
	for(long long iPeriode = 0;iPeriode < nbPeriodes;iPeriode++) {
		long long deb, fin;
		cin >> deb >> fin;
		if(maxTemps <= fin) {
			minTemps = min(minTemps, max(maxTemps, deb));
		}
	}
	
	if(minTemps == INFINI)
		cout << -1 << endl;
	else
		cout << minTemps << endl;
	
	return 0;
}