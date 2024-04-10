#include <bits/stdc++.h>
using namespace std;
#define sz(a) (int)((a).size())
#define all(a) (a).begin(), (a).end()
using ll = long long;
#define int long long
const int maxn = 1e5, mod = 1e9 + 9;

int pw(int a, int b) {
	if(!b) return 1;
	if(b & 1) return ll(a) * pw(a, b - 1) % mod;
	a = pw(a, b >> 1);
	return ll(a) * a % mod;
}

int32_t main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n, a, b, k; string s;
	cin >> n >> a >> b >> k >> s;

	int q = pw(ll(b) * pw(a, mod - 2) % mod, k);

	if(q != 1) {
		int qn = pw(q, (n + 1) / k);
		int div = pw((1 - q + mod) % mod, mod - 2);
		int mul = (1 - qn + mod) % mod;

		int ans = 0;
		for(int i = 0; i < k; i++) {
			int b1 = ll(pw(a, n - i)) * pw(b, i) % mod;
			int sum = ll(b1) * mul % mod * ll(div) % mod;
			if(s[i] == '-') sum = mod - sum;
			ans = (ans + sum) % mod;
		}
		cout << (ans + mod) % mod;
	} else {
		int y = (n + 1) / k;
		int ans = 0;
		for(int i = 0; i < k; i++) {
			int b1 = ll(pw(a, n - i)) * pw(b, i) % mod;
			int sum = ll(b1) * y % mod;
			if(s[i] == '-') sum = mod - sum;
			ans = (ans + sum) % mod;
		}
		cout << (ans + mod) % mod;
	}
}