#include <iostream>
#include <set>
#include <iomanip>
#include <algorithm>
#include <vector>
using namespace std;

vector<long double> probas;

int main() {
	int nbAmis;
	cin >> nbAmis;
	
	for(int iAmi = 0;iAmi < nbAmis;iAmi++) {
		long double proba;
		cin >> proba;
		probas.push_back(proba);
	}
	
	sort(probas.begin(), probas.end());
	
	long double maxP1 = 0;
	long double p0 = 1, p1 = 0;
	for(int iDebut = 0;iDebut < nbAmis;iDebut++) {
		long double cp1 = p1, cp0 = p0;
		for(int iFin = nbAmis - 1;iFin >= iDebut;iFin--) {
			maxP1 = max(maxP1, cp1);
			cp1 = (1 - probas[iFin]) * cp1 + probas[iFin] * cp0;
			cp0 = (1 - probas[iFin]) * cp0;
		}
		
		p1 = (1 - probas[iDebut]) * p1 + probas[iDebut] * p0;
		p0 = (1 - probas[iDebut]) * p0;
		maxP1 = max(maxP1, p1);
	}
	
	cout << fixed << setprecision(10);
	cout << maxP1 << endl;
	return 0;
}