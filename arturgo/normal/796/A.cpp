#include <iostream>
#include <set>
using namespace std;

int main() {
	int nbMaisons, fille, argent;
	cin >> nbMaisons >> fille >> argent;
	
	int minDist = 1000 * 1000 * 1000;
	for(int iMaison = 0;iMaison < nbMaisons;iMaison++) {
		int prix;
		cin >> prix;
		if(prix != 0 && prix <= argent) {
			minDist = min(minDist, abs(iMaison + 1 - fille) * 10);
		}
	}
	
	cout << minDist << endl;
}