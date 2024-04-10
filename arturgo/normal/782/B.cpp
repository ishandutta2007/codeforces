#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;

int nbAmis;
int vitesses[100 * 1000];
int positions[100 * 1000];

bool estPossible(double dist) {
	vector<pair<double, int> > events;
	
	for(int iAmi = 0;iAmi < nbAmis;iAmi++) {
		events.push_back(make_pair(positions[iAmi] - dist * vitesses[iAmi], 1));
		events.push_back(make_pair(positions[iAmi] + dist * vitesses[iAmi], -1));
	}
	
	sort(events.begin(), events.end());
	
	int nbOuverts = 0;
	
	for(auto event : events) {
		if(nbOuverts == nbAmis)
			return true;
		nbOuverts += event.second;
	}
	
	return false;
}

int main() {
	cin >> nbAmis;
	
	for(int iAmi = 0;iAmi < nbAmis;iAmi++) {
		cin >> positions[iAmi];
	}
	
	for(int iAmi = 0;iAmi < nbAmis;iAmi++) {
		cin >> vitesses[iAmi];
	}
	
	double debut = 0, fin = 1000 * 1000 * 1000;
	while(debut + 0.0000001 < fin) {
		double mil = (debut + fin) / 2;
		
		if(!estPossible(mil)) {
			debut = mil;
		}
		else {
			fin = mil;
		}
	}
	
	cout << fixed << setprecision(18) << endl;
	cout << debut << endl;
	return 0;
}