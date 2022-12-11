#include <bits/stdc++.h>
using namespace std;

int sqfrs[1000 * 1000 + 1];

int sqfr(int a) {
	int p = 2;
	
	int res = 1;
	while(p * p <= a) {
		int nbFois = 0;
		while(a % p == 0) {
			a /= p;
			nbFois++;
		}
		
		if(nbFois % 2 == 1) {
			res *= p;
		}
		
		p++;
	}
	
	return res * a;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	for(int i = 0;i <= 1000 * 1000;i++) {
		sqfrs[i] = sqfr(i);
	}
	
	int nbTests;
	cin >> nbTests;
	
	for(int iTest = 0;iTest < nbTests;iTest++) {
		int nbNombres;
		cin >> nbNombres;
		
		int val0 = 0, val1 = 0;
		map<int, int> classes0, classes1;
		
		for(int iNombre = 0;iNombre < nbNombres;iNombre++) {
			int nombre;
			cin >> nombre;
			
			classes0[sqfrs[nombre]] += 1;
		}
		
		int nbReqs;
		cin >> nbReqs;
		
		for(pair<int, int> paire : classes0) {
			val0 = max(val0, paire.second);
			
			if(paire.second % 2 == 0) {
				classes1[1] += paire.second;
			}
			else {
				classes1[paire.first] += paire.second;
			}
		}
		
		for(pair<int, int> paire : classes1) {
			val1 = max(val1, paire.second);
		}
		
		for(int iReq = 0;iReq < nbReqs;iReq++) {
			long long temps;
			cin >> temps;
			
			if(temps == 0) {
				cout << val0 << endl;
			}
			else {
				cout << val1 << endl;
			}
		}
	}
	return 0;
}