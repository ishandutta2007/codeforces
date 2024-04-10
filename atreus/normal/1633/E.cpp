#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 3e5 + 10;

int par[55];
pair<int,pair<int,int>> e[300 + 10];
ll an[maxn], go[maxn];

int get_par(int v) {
	return par[v] < 0 ? v : par[v] = get_par(par[v]);
}

bool merge(int v, int u) {
	if ((v = get_par(v)) == (u = get_par(u)))
		return 0;
	if (par[v] > par[u])
		swap(v, u);
	par[v] += par[u];
	par[u] = v;
	return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++)
		cin >> e[i].second.first >> e[i].second.second >> e[i].first;
	sort(e, e + m);
	vector<int> crit;
	crit.push_back(0);
	for (int i = 0; i < m; i++) {
		for (int j = i; j < m; j++) {
			int e1 = e[i].first, e2 = e[j].first;
			int x = (e1 + e2) >> 1;
			crit.push_back(x);
			crit.push_back(x - 1);
			crit.push_back(x + 1);
		}
	}
	sort(crit.begin(), crit.end());
	crit.resize(unique(crit.begin(), crit.end()) - crit.begin());
	for (int i = 0; i < crit.size(); i++) {
		int x = crit[i];
		int lo = -1, hi = m;
		while (hi - lo > 1) {
			int mid = (lo + hi) >> 1;
			if (e[mid].first < x)
				lo = mid;
			else
				hi = mid;
		} // e[lo] < x and x <= e[hi]
		int cnt = 0, lef = 0;
		ll mst = 0;
		for (int i = 1; i <= n; i++)
			par[i] = -1;
		while (cnt < n - 1) {
			int idx;
			if (lo == -1 || (hi < m && abs(e[lo].first - x) > abs(e[hi].first - x)))
				idx = hi++;
			else
				idx = lo--;
			if (merge(e[idx].second.first, e[idx].second.second)) {
				if (e[idx].first <= x)
					lef++;
				cnt++;
				mst += abs(e[idx].first - x);
			}
		}
		an[i] = mst;
		go[i] = lef;
	}
	int p, k, a, b, c;
	cin >> p >> k >> a >> b >> c;
	int x;
	ll answer = 0;
	for (int i = 1; i <= k; i++) {
		if (i <= p)
			cin >> x;
		else
			x = (1LL * x * a + b) % c;
		int idx = upper_bound(crit.begin(), crit.end(), x) - crit.begin() - 1;
		ll mst = an[idx] + 1LL * go[idx] * (x - crit[idx]) - 1LL * (n - 1 - go[idx]) * (x - crit[idx]);
//		cout << "# " << x << " => " << crit[idx] << " : " << " - " << go[idx] << " " << an[idx] << " " << mst << endl;
		answer ^= mst;
	}
	cout << answer << '\n';
}