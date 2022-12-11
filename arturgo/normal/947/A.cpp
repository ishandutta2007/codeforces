#include <iostream>
#include <bitset>
#include <vector>
using namespace std;

const int MAX_PREMIERS = 1000 * 1000 + 42;
bool estDivisible[MAX_PREMIERS];
vector<int> divs[MAX_PREMIERS];
vector<int> premiers;

void calculePremiers() {
	estDivisible[0] = estDivisible[1] = true;
	for(int i = 2;i < MAX_PREMIERS;i++) {
		if(!estDivisible[i]) {
			premiers.push_back(i);
			for(int j = 2 * i;j < MAX_PREMIERS;j += i) {
				estDivisible[j] = true;
				divs[j].push_back(i);
			}
		}
	}
}

bitset<1000 * 1001> x1s;

int main() {
	calculePremiers();
	
	int x2;
	cin >> x2;
	
	for(int iDiv = 2;iDiv < x2;iDiv++) {
		if(x2 % iDiv == 0 && !estDivisible[iDiv]) {
			for(int iPos = x2 - iDiv + 1;iPos <= x2;iPos++) {
				x1s[iPos] = true;
			}
		}
	}
	
	int minX0 = 1000 * 1000;
	for(int x1 = 3;x1 <= 1000 * 1000;x1++) {
		if(x1s[x1]) {
			for(int div : divs[x1]) {
				if(div != x1 && x1 % div == 0 && !estDivisible[div]) {
					minX0 = min(minX0, x1 - div + 1);
				}
			}
		}
	}
	
	cout << minX0 << endl;
	return 0;
}