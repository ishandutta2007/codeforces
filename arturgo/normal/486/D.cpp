#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <string>
using namespace std;

const int MOD = 1000 * 1000 * 1000 + 7;

int nbNoeuds;
int maxDiff;
int vals[2000];

vector<int> voisins[2000];

long long solve(int noeud, int parent, int pMini) {
	if(vals[noeud] < vals[pMini] || (vals[noeud] == vals[pMini] && noeud < pMini) || vals[noeud] > vals[pMini] + maxDiff) {
		return 0;
	}
	
	long long res = 1;
	for(int voisin : voisins[noeud]) {
		if(voisin != parent) {
			res *= (1 + solve(voisin, noeud, pMini));
			res %= MOD;
		}
	}
	
	return res;
}

int main() {
	ios_base::sync_with_stdio(false);
	
	cin >> maxDiff >> nbNoeuds;
	
	for(int iNoeud = 0;iNoeud < nbNoeuds;iNoeud++) {
		cin >> vals[iNoeud];
	}
	
	for(int iArc = 0;iArc < nbNoeuds - 1;iArc++) {
		int deb, fin;
		cin >> deb >> fin;
		voisins[deb - 1].push_back(fin - 1);
		voisins[fin - 1].push_back(deb - 1);
	}
	
	long long res = 0;
	
	for(int iNoeud = 0;iNoeud < nbNoeuds;iNoeud++) {
		res += solve(iNoeud, -1, iNoeud);
	}
	
	cout << res % MOD << endl;
	return 0;
}