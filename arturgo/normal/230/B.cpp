#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

const int MAX_PREMIERS = 5000 * 1000;
bool estDivisible[MAX_PREMIERS];
vector<int> premiers;

void calculePremiers() {
	estDivisible[0] = estDivisible[1] = true;
	for(int i = 2;i < MAX_PREMIERS;i++) {
		if(!estDivisible[i]) {
			premiers.push_back(i);
			for(int j = 2 * i;j < MAX_PREMIERS;j += i) {
				estDivisible[j] = true;
			}
		}
	}
}

int main() {
	calculePremiers();
	
	ios_base::sync_with_stdio(false);
	int nb;
	cin >> nb;
	
	for(int i = 0;i < nb;i++) {
		long long a;
		cin >> a;
		
		if(a == 1) {
			cout << "NO\n";
			continue;
		}
		
		if((long long)sqrt(a) * (long long)sqrt(a) == a) {
			if(!estDivisible[(int)sqrt(a)]) {
				cout << "YES\n";
			}
			else {
				cout << "NO\n";
			}
		}	
		else {
			cout << "NO\n";
		}
	}
}