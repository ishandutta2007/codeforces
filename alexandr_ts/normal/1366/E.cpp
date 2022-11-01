#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int INF = 2e9;
const ll MOD = 998244353;
const int N = 1e6 + 10;

int a[N], b[N];
int mn[N];

void solve() {
	int n, m;
	cin >> n >> m;
	map<int, int> rpos;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		rpos[a[i]] = i;
	}
	for (int i = 0; i < m; ++i) {
		cin >> b[i];
	}

	vector<int> v;
	for (int i = 0; i < m; ++i) {
		if (!rpos.count(b[i])) {
			cout << 0 << endl;
			return;
		}
		if (!v.empty() && v.back() > rpos[b[i]]) {
			cout << 0 << endl;
			return;
		}
		v.push_back(rpos[b[i]]);
	}

	mn[n] = INF;
	for (int i = n - 1; i >= 0; --i) {
		mn[i] = min(mn[i + 1], a[i]);
	}
	for (auto pos: v) {
		if (mn[pos] != a[pos]) {
			cout << 0 << endl;
			return;
		}	
	}
	if (mn[0] != b[0]) {
		cout << 0 << endl;
		return;
	}

	ll ans = 1;
	for (int i = 1; i < v.size(); ++i) {
		int pos = v[i] - 1;
		while (a[pos] >= a[v[i]]) --pos;
		ans *= (v[i] - pos);
		ans %= MOD;
	}
	cout << ans << endl;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int t = 1;
	while (t--) {
		solve();
	}
}