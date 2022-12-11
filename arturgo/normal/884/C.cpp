#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int suivs[100 * 1000];

int main() {
	int nbStations;
	cin >> nbStations;
	
	for(int iStation = 0;iStation < nbStations;iStation++) {
		cin >> suivs[iStation];
		suivs[iStation]--;
	}
	
	vector<long long> tailles;
	for(int iStation = 0;iStation < nbStations;iStation++) {
		int cur = iStation, taille = -1;
		while(cur != -1) {
			taille++;
			int nouv = suivs[cur];
			suivs[cur] = -1;
			cur = nouv;
		}
		
		tailles.push_back(taille);
	}
	
	sort(tailles.begin(), tailles.end());
	
	if(tailles.size() >= 2) {
		long long der = tailles.back();
		tailles.pop_back();
		tailles.back() += der;
	}
	
	long long somme = 0;
	
	for(long long taille : tailles) {
		somme += taille * taille;
	}
	
	cout << somme << endl;
	return 0;
}