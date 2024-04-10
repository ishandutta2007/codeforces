#include <iostream>
#include <algorithm>
using namespace std;

int nbs[100*1000];

int main() {
	int nb;
	cin >> nb;
	
	for(int i = 0;i < nb;i++) {
		cin >> nbs[i];
	}
	
	sort(nbs, nbs + nb);
	
	if(nbs[2] != nbs[1]) {
		long long nbLast = count(nbs, nbs + nb, nbs[2]);
		cout << nbLast << endl;
	} 
	else if(nbs[1] != nbs[0]) {
		long long nbLast = count(nbs, nbs + nb, nbs[2]);
		cout << nbLast * (nbLast - 1) / 2 << endl;
	}
	else {
		long long nbLast = count(nbs, nbs + nb, nbs[2]);
		cout << nbLast * (nbLast - 1) * (nbLast - 2) / 6 << endl;
	}
}