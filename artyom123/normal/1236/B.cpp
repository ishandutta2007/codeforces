#include <bits/stdc++.h>
 
using namespace std;
 
#define pb push_back
#define int long long
#define fi first
#define se second
#define all(x) x.begin(), x.end()

const int mod = 1e9 + 7;

int modpow(int n, int m) {
	if (m == 0) {
		return 1;
	}
	int now = modpow(n, m / 2);
	if (m % 2 == 0) {
		return (now * now) % mod;
	}
	return (((now * now) % mod) * n) % mod;
}
signed main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#else
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
#endif
	int n, m;
	cin >> n >> m;
	cout << modpow((modpow(2, m) - 1 + mod) % mod, n);
	return 0;
}