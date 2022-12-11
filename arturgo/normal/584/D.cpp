#include <iostream>
using namespace std;

bool estPrem(int nb) {
	for(int i = 2;i * i <= nb;i++) {
		if(nb % i == 0)
			return false;
	}
	return true;
}

int pg(int nb) {
	for(int i = nb;i >= 0;i--) {
		if(estPrem(i))
			return i;
	}
}

int main() {
	int nb;
	cin >> nb;
	
	if(nb == 3) {
		cout << 1 << endl << 3 << endl;
		return 0;
	}
	
	int gp = pg(nb - 2);
	
	int res = nb - gp;
	
	if(res == 2) {
		cout << 2 << endl << gp << " 2" << endl;
	}
	else if(res == 4) {
		cout << 3 << endl << gp << " 2 2" << endl;
	}
	else {
		for(int iE = 2;iE < res;iE++) {
			if(estPrem(iE) && estPrem(res - iE)) {
				cout << 3 << endl << gp << " " << iE << " " << res - iE << endl;
				return 0;
			}
		}
	}
	return 0;
}