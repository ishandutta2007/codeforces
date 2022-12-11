#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;

vector<int> plateau;

int main() {
	ios_base::sync_with_stdio(false);
	
	int nbCases, nbTours, maxVal;
	cin >> nbCases >> nbTours >> maxVal;
	
	plateau = vector<int>(nbCases, -1);
	
	for(int iTour = 0;iTour < nbTours;iTour++) {
		int val;
		cin >> val;
		
		if(val <= maxVal / 2) {
			for(int iPos = 0;iPos < nbCases;iPos++) {
				if(plateau[iPos] == -1 || plateau[iPos] > val) {
					plateau[iPos] = val;
					cout << iPos + 1 << endl;
					fflush(stdout);
					break;
				}
			}
		}
		else {
			for(int iPos = nbCases - 1;iPos >= 0;iPos--) {
				if(plateau[iPos] == -1 || plateau[iPos] < val) {
					plateau[iPos] = val;
					cout << iPos + 1 << endl;
					fflush(stdout);
					break;
				}
			}
		}
		
		int der = -1;
		bool stop = true;
		for(int iPos = 0;iPos < nbCases;iPos++) {
			if(plateau[iPos] == -1) {
				stop = false;
				break;
			}
			if(der > plateau[iPos]) {
				stop = false;
				break;
			}
			der = plateau[iPos];
		}
		
		if(stop) {
			return 0;
		}
	}
	
	return 0;
}