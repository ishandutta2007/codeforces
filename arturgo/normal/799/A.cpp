#include <iostream>
#include <functional>
#include <algorithm>
using namespace std;

int main() {
	int nbCakes, temps, capacite, nouv;
	cin >> nbCakes >> temps >> capacite >> nouv;
	
	int tempsUn = (nbCakes + capacite - 1) / capacite * temps;
	
	if(nouv + temps < tempsUn) {
		cout << "YES" << endl;
	}
	else {
		cout << "NO" << endl;
	}
	return 0;
}