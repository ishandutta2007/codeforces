#include <iostream>
#include <algorithm>
using namespace std;

vector<int> cartes;

int occs[200 * 1000];

int main() {
	ios_base::sync_with_stdio(false);
	int nbCartes;
	cin >> nbCartes;

	for(int iCarte = 0;iCarte < nbCartes;iCarte++) {
		int carte;
		cin >> carte;
		occs[carte]++;
	}

	for(int val = 0;val < 200 * 1000;val++) {
		if(occs[val] % 2 == 1) {
			cout << "Conan" << endl;
			return 0;
		}
	}

	cout << "Agasa" << endl;
	return 0;
}