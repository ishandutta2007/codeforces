#include <iostream>
#include <cmath>
#include <list>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;

int main() {
	int nbLettres;
	cin >> nbLettres;
	
	int nbUns = 0, nbChs = 0;
	int der = 0;
	
	for(int iLettre = 0;iLettre < nbLettres;iLettre++) {
		int val;
		cin >> val;
		
		nbUns += val;
		if(val == 1 && der == 0) {
			nbChs++;
		}
		
		der = val;
	}
	
	cout << max(0, nbUns + nbChs - 1) << endl;
}