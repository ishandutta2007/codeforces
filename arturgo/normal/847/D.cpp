#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<pair<long long, long long>> events;
long long arbre[1 << 20];

void ajouter(long long pos, long long val) {
	pos += (1 << 19);
	
	while(pos != 0) {
		arbre[pos] += val;
		pos /= 2;
	}
}

long long somme(long long deb, long long fin) {
	deb += (1 << 19);
	fin += (1 << 19);
	
	long long s = 0;
	while(deb < fin) {
		if(deb % 2 == 1) {
			s += arbre[deb];
			deb++;
		}
		if(fin % 2 == 1) {
			fin--;
			s += arbre[fin];
		}
		deb /= 2;
		fin /= 2;
	}
	
	return s;
}


int main() {
	ios_base::sync_with_stdio(false);
	long long nbBols, temps;
	cin >> nbBols >> temps;
	
	for(long long iBol = 1;iBol <= nbBols;iBol++) {
		long long t;
		cin >> t;
		events.push_back({t - iBol, iBol});
	}
	
	sort(events.begin(), events.end());
	
	long long maxi = 0;
	
	long long iDebut = 0;
	while(iDebut < (long long)events.size() && events[iDebut].first <= 0) {
		ajouter(events[iDebut].second, 1);
		iDebut++;
	}
	
	maxi = max(maxi, somme(0, min(temps, nbBols + 1)));
	
	for(;iDebut < (long long)events.size();) {
		long long iFin = iDebut;
		
		while(events[iDebut].first == events[iFin].first) {
			ajouter(events[iFin].second, 1);
			iFin++;
		}
		
		maxi = max(maxi, somme(0, min(temps - events[iDebut].first, nbBols + 1)));
		
		iDebut = iFin;
	}
	
	cout << maxi << endl;
	return 0;
}