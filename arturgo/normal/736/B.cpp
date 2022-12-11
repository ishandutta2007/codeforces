#include <iostream>
using namespace std;

bool estPremier(int nombre) {
	for(int iDiv = 2;iDiv * iDiv <= nombre;iDiv++) {
		if(nombre % iDiv == 0) {
			return false;
		}
	}
	return true;
}

int main() {
	int revenu;
	cin >> revenu;
	
	if(estPremier(revenu)) {
		cout << 1 << endl;
	}
	else if(revenu % 2 == 0) {
		cout << 2 << endl;
	}
	else if(estPremier(revenu - 2)) {
		cout << 2 << endl;
	}
	else {
		cout << 3 << endl;
	}
	return 0;
}