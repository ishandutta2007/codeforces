#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
inline int quick_pow(int a, int b) {
	int res = 1;
	while (b) {
		if (b & 1) res = 1ll * res * a % mod;
		a = 1ll * a * a % mod;
		b >>= 1;
	}
	return res;
}
int main() {
	int n, m;
	cin >> n >> m;
	cout << quick_pow((quick_pow(2, m) - 1 + mod) % mod, n) << endl;
	return 0;
}