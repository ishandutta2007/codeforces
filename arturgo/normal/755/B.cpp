#include <iostream>
#include <vector>
using namespace std;

vector<string> a, b;

int main() {
	int nbA, nbB;
	cin >> nbA >> nbB;
	
	int nbCommons = 0;
	
	for(int iA = 0;iA < nbA;iA++) {
		string c;
		cin >> c;
		a.push_back(c);
	}
	
	for(int iB = 0;iB < nbB;iB++) {
		string c;
		cin >> c;
		for(int iA = 0;iA < nbA;iA++) {
			if(c == a[iA]) {
				nbCommons++;
				break;
			}
		}
	}
	
	int nbAs = nbCommons - (nbCommons / 2) + nbA - nbCommons;
	int nbBs = nbCommons / 2 + nbB - nbCommons;
	
	if(nbAs > nbBs) {
		cout << "YES" << endl;
	}
	else {
		cout << "NO" << endl;
	}
    return 0;
}