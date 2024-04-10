#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define DBG(v) cerr << #v << " = " << (v) << endl;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n;
	cin >> n;
	vector<ll> a(n);
	for (ll &x : a)
		cin >> x;
	for (int i = 0; i < n; ++i)
		a[i] *= (i + 1LL) * (n - i);
	sort(a.begin(), a.end());

	vector<ll> b(n);
	for (ll &x : b)
		cin >> x;
	sort(b.rbegin(), b.rend());

	const ll mod = 998244353;
	ll ans = 0;
	for (int i = 0; i < n; ++i)
		ans += a[i] % mod * b[i] % mod;

	cout << (ans % mod + mod) % mod;
	return 0;
}