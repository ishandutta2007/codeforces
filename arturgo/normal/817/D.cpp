#include <iostream>
#include <algorithm>
using namespace std;

vector< pair<int, int> > pileMin, pileMax;

long long ajouterMax(long long val) {
	long long sommeRem = 0;
	long long nbRem = 0;
	
	while(pileMax.size() != 0 && pileMax.back().first <= val) {
		nbRem += pileMax.back().second;
		sommeRem += (long long)(pileMax.back().second) * pileMax.back().first;
		pileMax.pop_back();
	}
	
	pileMax.push_back(make_pair(val, nbRem + 1));
	
	return nbRem * val - sommeRem;
}

long long ajouterMin(int val) {
	long long sommeRem = 0;
	long long nbRem = 0;
	
	while(pileMin.size() != 0 && pileMin.back().first >= val) {
		nbRem += pileMin.back().second;
		sommeRem += (long long)(pileMin.back().second) * pileMin.back().first;
		pileMin.pop_back();
	}
	
	pileMin.push_back(make_pair(val, nbRem + 1));
	
	return sommeRem - nbRem * val;
}

int nbs[1000 * 1000];

int main() {
	int nb;
	cin >> nb;
	
	long long total = 0;
	long long somme = 0;
	
	for(int i = 0;i < nb;i++) {
		int a;
		cin >> a;
		
		somme += ajouterMin(a);
		somme += ajouterMax(a);
		
		total += somme;
	}
	
	cout << total << endl;
}