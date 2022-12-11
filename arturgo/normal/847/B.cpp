#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
using namespace std;

map<int, int> suivs;
set<int> ouverts;
vector<int> ns;

int main() {
	ios_base::sync_with_stdio(false);
	
	int nbNombres;
	cin >> nbNombres;
	
	for(int iNombre = 0;iNombre < nbNombres;iNombre++) {
		int n;
		cin >> n;
		
		ns.push_back(n);
		
		auto pg = ouverts.lower_bound(n);
		if(pg == ouverts.begin()) {
			ouverts.insert(n);
			suivs[n] = -1;
		}
		else {
			pg--;
			suivs[*pg] = n;
			ouverts.erase(pg);
			ouverts.insert(n);
		}
	}
	
	for(int iNombre = 0;iNombre < nbNombres;iNombre++) {
		int it = ns[iNombre];
		
		if(suivs.find(ns[iNombre]) == suivs.end()) {
			continue;
		}
		
		while(it != -1) {
			cout << it << " ";
			if(suivs.find(it) == suivs.end())
				break;
			int s = suivs[it];
			suivs.erase(it);
			it = s;
		}
		
		cout << endl;
	}
	return 0;
}