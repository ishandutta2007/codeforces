#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

const int MOD = 1000 * 1000 * 1000 + 7;

long long puis27[200 * 1000], puis7[200 * 1000];

int main() {
	int n;
	cin >> n;
	
	puis27[0] = puis7[0] = 1;
	for(int i = 1;i < 200 * 1000;i++) {
		puis27[i] = (27 * puis27[i - 1]) % MOD;
		puis7[i] = (7 * puis7[i - 1]) % MOD;
	}
	
	cout << (puis27[n] + MOD - puis7[n]) % MOD << endl;
}