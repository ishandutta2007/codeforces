#include <bits/stdc++.h>

using namespace std;

const long long MOD = 1000000007;

long long BigMod (long long a, long long e) {
	if (e == 0) return 1;
	if (e == 1) return a % MOD;
	long long half = BigMod((a * a) % MOD, e >> 1) % MOD;
	if (!(e & 1)) return half;
	return (a * half) % MOD;
}

int main() {
	long long p, k; cin >> p >> k;
	
	if (k == 0) {
		long long ret = BigMod(p, p - 1);
		cout << ret << endl;
		return 0;
	} if (k == 1) {
		long long ret = BigMod(p, p);
		cout << ret << endl;
		return 0;
	}
	
	long long ord, prod = 1;
	for (ord = 1; ord < p; ord++) {
		prod = (prod * k) % p;
		if (prod == 1) break;
	}
	long long ret = BigMod(p, (p - 1)/ord);
	cout << ret << endl;
	return 0;
}