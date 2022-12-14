#include <bits/stdc++.h>

#define F first
#define S second
#define PB push_back
#define PF push_front
#define MP make_pair

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
const int maxn = 1e5 + 100;

int sz[maxn], par[maxn];
vector <int> g[maxn];

void dfs (int v) {
	if (g[v].empty()) {
		sz[v] = 1;
		par[1] ++;
		return;
	}
	for (auto u : g[v]) {
		dfs (u);
		sz[v] += sz[u];
	}
	par[sz[v]] ++;
}

int main() {
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	for (int i = 2; i <= n; i++) {
		int p;
		cin >> p;
		g[p].PB (i);
	}
	dfs (1);
	
	int tmp = 0;
	for (int i = 1; i <= n; i++) {
		tmp += par[i];
		par[i] = tmp;
	}
	for (int i = 1; i <= n; i++) {
		int idx = lower_bound (par + 1, par + n + 1, i) - par;
		cout << idx << " ";
	}
	cout << endl;
	return 0;
}