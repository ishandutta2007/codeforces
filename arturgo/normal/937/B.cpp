#include <iostream>
using namespace std;

int main() {
	int p, y;
	cin >> p >> y;
	
	for(int pos = y;pos > p;pos--) {
		bool estDivisible = false;
		for(int div = 2;div <= p && div * div <= pos;div++) {
			if(pos % div == 0) {
				estDivisible = true;
			}
		}
		if(!estDivisible) {
			cout << pos << endl;
			return 0;
		}
	}
	
	cout << -1 << endl;
	return 0;
}