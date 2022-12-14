#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxn = 2e5 + 77;

int p[maxn], x[maxn];
map<int,ll> mp;

void add(int l, int r, int val) {
	mp[2 * l + 1] += val;
	mp[2 * r] -= val;
}

void solve() {
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> p[i];
	for (int i = 1; i <= m; i++)
		cin >> x[i];
	sort(x + 1, x + m + 1);
	x[m + 1] = 1e9;
	x[0] = -1e9;
	for (int i = 1; i <= n; i++) {
		int loc = 100 * (i - 1);
		int nex = lower_bound(x + 1, x + m + 1, loc) - x;
		int dis = min(x[nex] - loc, loc - x[nex - 1]);
		if (dis == 0)
			continue;
		add(loc - dis, loc + dis, p[i]);
	}
	ll par = 0, best = 0;
	for (auto [key, value] : mp) {
		par += value;
		best = max(best, par);
	}
	cout << best << endl;
}

int main() {
	ios_base::sync_with_stdio(false);
	int tc = 1;
//	cin >> tc;
	while (tc --) {
		solve();
	}
}