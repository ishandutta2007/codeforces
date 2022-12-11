#include <iostream>
#include <queue>
#include <functional>
#include <algorithm>
#include <map>
#include <cctype>
#include <bitset>
using namespace std;

struct Resultat {
	bitset<1000> bits[2];
};

Resultat opAnd(Resultat a, Resultat b) {
	a.bits[0] &= b.bits[0];
	a.bits[1] &= b.bits[1];
	return a;
}

Resultat opOr(Resultat a, Resultat b) {
	a.bits[0] |= b.bits[0];
	a.bits[1] |= b.bits[1];
	return a;
}

Resultat opXor(Resultat a, Resultat b) {
	a.bits[0] ^= b.bits[0];
	a.bits[1] ^= b.bits[1];
	return a;
}

int vals[2][1000];
map<string, Resultat> results;

int main() {
	int nbVars, nbBits;
	cin >> nbVars >> nbBits;
	
	Resultat id;
	for(int iBit = 0;iBit < nbBits;iBit++) {
		id.bits[0].reset(iBit);
		id.bits[1].set(iBit);
	}
	results["?"] = id;
	
	for(int iVar = 0;iVar < nbVars;iVar++) {
		string var, eq, a, op, b;
		cin >> var >> eq >> a;
		
		Resultat res;
		if(isdigit(a[0])) {
			for(int iBit = 0;iBit < nbBits;iBit++) {
				res.bits[0][iBit] = res.bits[1][iBit] = a[iBit] - '0';
			}
		}
		else {
			cin >> op >> b;
		
			if(op == "AND")
				res = opAnd(results[a], results[b]);
			if(op == "OR")
				res = opOr(results[a], results[b]);
			if(op == "XOR")
				res = opXor(results[a], results[b]);
		}
		
		results[var] = res;
		
		for(int iBit = 0;iBit < nbBits;iBit++) {
			vals[0][iBit] += res.bits[0][iBit];
			vals[1][iBit] += res.bits[1][iBit];
		}
	}
	
	for(int iBit = 0;iBit < nbBits;iBit++) {
		if(vals[0][iBit] <= vals[1][iBit])
			cout << 0;
		else
			cout << 1;
	}
	cout << endl;
	
	for(int iBit = 0;iBit < nbBits;iBit++) {
		if(vals[0][iBit] >= vals[1][iBit])
			cout << 0;
		else
			cout << 1;
	}
	cout << endl;
	
	return 0;
}