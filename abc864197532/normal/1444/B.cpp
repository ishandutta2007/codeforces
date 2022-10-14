#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;

const int mod = 998244353, N = 1e5;

lli modpow(lli a, int b) {
	lli ans = 1;
	for (; b; b >>= 1, a = a * a % mod) {
		if (b & 1) ans = ans * a % mod;
	}
	return ans;
}

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector <int> a(n * 2);
    for (int i = 0; i < n * 2; ++i) cin >> a[i];
    sort(a.begin(), a.end());
    lli cur = 0;
    for (int i = 0; i < n; ++i) {
    	cur = (cur + a[n + i] - a[i]) % mod;
	}
	for (int i = 2 * n; i > n; --i) {
		cur = cur * i % mod;
	}
	for (int i = n; i > 0; --i) {
		cur = cur * modpow(i, mod - 2) % mod;
	}
	cout << cur << endl;
}