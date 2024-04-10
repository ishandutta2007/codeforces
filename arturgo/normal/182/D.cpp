#include <iostream>
#include <cstdio>
#include <algorithm>
#include <list>
using namespace std;

int pgcd(int a, int b) {
	if(a == 0)
		return b;
	return pgcd(b % a, a);
}

vector<int> kmp(string a) {
	vector<int> res;
	
	res.push_back(-1);
	
	for(int iCar = 0;iCar < (int)a.size();iCar++) {
		int cur = res.back();
		while(cur != -1 && a[iCar] != a[cur]) {
			cur = res[cur];
		}
		
		res.push_back(cur + 1);
	}
	
	return res;
}

bool estDiviseur(string a, string b) {
	vector<int> res = kmp(a + "$" + b);
	
	for(int iPos = 2 * a.size() + 1;iPos < (int)res.size();iPos += a.size()) {
		if(res[iPos] != (int)a.size())
			return false;
	}
	
	return true;
}

int main() {
	string a, b;
	cin >> a >> b;
	
	int pg = pgcd(a.size(), b.size());
	
	int nbDivs = 0;
	for(int iDiv = 1;iDiv <= pg;iDiv++) {
		if(pg % iDiv == 0) {
			if(estDiviseur(a.substr(0, iDiv), a) && estDiviseur(a.substr(0, iDiv), b)) {
				nbDivs++;
			}
		}
	} 
	
	cout << nbDivs << endl;
	return 0;
}