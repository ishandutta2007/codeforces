#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define DBG(v) cerr << #v << " = " << (v) << endl;

vector<int> f(const int n) {
	vector<int> v(n);
	for (int&x : v)
		cin >> x;
	sort(v.begin(), v.end());
	return v;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n, m;
	cin >> n >> m;
	vector<int> b = f(n);
	vector<int> g = f(m);

	if (b.back() > g[0]) {
		cout << -1;
		return 0;
	}

	ll ans = 0;

	for (ll x : b)
		ans += x * m;

	for (ll x : g)
		ans += x - b.back();
	if (b.back() < g[0])
		ans += b[n - 1] - b[n - 2];
	cout << ans;
	return 0;
}