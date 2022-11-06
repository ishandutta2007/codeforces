#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 998244353;

ll p2[(int) 2e5 + 999];
ll cs[(int) 2e5 + 999];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	p2[0] = 1;
	for (int i = 1; i <= (int) 2e5 + 99; ++i)
		p2[i] = (p2[i - 1] * 2) % mod;

	int n;
	string a, b;
	cin >> n >> n >> a >> b;
	n = (int)max(a.size(), b.size());
	a = string(n - (int)a.size(), '0') + a;
	b = string(n - (int)b.size(), '0') + b;

	cs[n] = 0;
	for(int i = n - 1; i >= 0; --i) {
		cs[i] = cs[i+1] + (a[i] == '0' ? 0LL : p2[n - 1 - i]);
		cs[i] %= mod;
	}

	ll ans = 0;
	for(int i = n - 1; i >= 0; --i) {
		if(b[i] == '1') {
			ans += cs[i];
			ans %= mod;
		}
	}
	cout << ans << '\n';
	return 0;
}