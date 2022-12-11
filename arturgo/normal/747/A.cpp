#include <iostream>
#include <cmath>

using namespace std;

const int INFINI = 1000 * 1000 * 1000;

int main() {
	int nb;
	cin >> nb;
	
	int melA = 0, melB = INFINI;
	for(int iDiv = 1;iDiv * iDiv <= nb;iDiv++) {
		if(nb % iDiv == 0) {
			if(melB - melA > nb / iDiv - iDiv) {
				melA = iDiv;
				melB = nb / iDiv;
			}
		}
	}
	
	cout << melA << " " << melB << endl;
	return 0;
}