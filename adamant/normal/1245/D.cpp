#include <bits/stdc++.h>

using namespace std;

#define int int64_t
#define all(x) begin(x), end(x)
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

const int maxn = 3000;
int par[maxn];
int get(int v) {
	return v == par[v] ? v : par[v] = get(par[v]);
}

bool uni(int a, int b) {
	a = get(a);
	b = get(b);
	if(a == b) {
		return 0;
	}
	par[a] = b;
	return 1;
}

signed main() {
	//freopen("input.txt", "r", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);
	iota(par, par + maxn, 0);
	int n;
	cin >> n;
	int x[n], y[n], c[n], k[n];
	for(int i = 0; i < n; i++) {
		cin >> x[i] >> y[i];
	}
	for(int i = 0; i < n; i++) {
		cin >> c[i];
	}
	for(int i = 0; i < n; i++) {
		cin >> k[i];
	}
	vector<tuple<int, int, int>> edges;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < i; j++) {
			edges.push_back({(k[i] + k[j]) * (abs(x[i] - x[j]) + abs(y[i] - y[j])), i, j});
		}
		edges.push_back({c[i], i, n});
	}
	sort(all(edges));
	int ans = 0;
	vector<int> electro;
	vector<pair<int, int>> pr;
	for(auto it: edges) {
		if(uni(get<1>(it), get<2>(it))) {
			ans += get<0>(it);
			if(get<2>(it) == n) {
				electro.push_back(get<1>(it) + 1);
			} else {
				pr.push_back({get<1>(it) + 1, get<2>(it) + 1});
			}
		}
	}
	cout << ans << endl;
	cout << electro.size() << endl;
	for(auto it: electro) {
		cout << it << ' ';
	}
	cout << endl << pr.size() << endl;
	for(auto it: pr) {
		cout << it.first << ' ' << it.second << endl;
	}
	return 0;
}