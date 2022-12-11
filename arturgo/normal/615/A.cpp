#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <string>
using namespace std;

int nbs[200 * 1000];

int main() {
	ios_base::sync_with_stdio(false);
	
	int nbBoutons, nbLampes;
	cin >> nbBoutons >> nbLampes;
	
	for(int iBouton = 0;iBouton < nbBoutons;iBouton++) {
		int nb;
		cin >> nb;
		
		for(int iLampe = 0;iLampe < nb;iLampe++) {
			int num;
			cin >> num;
			nbs[num - 1]++;
		}
	}
	
	for(int iLampe = 0;iLampe < nbLampes;iLampe++) {
		if(nbs[iLampe] == 0) {
			cout << "NO" << endl;
			return 0;
		}
	}
	
	cout << "YES" << endl;
	return 0;
}