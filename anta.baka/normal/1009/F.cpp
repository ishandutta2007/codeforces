#pragma GCC optimize("O3")

#include <iostream>
#include <fstream>
#include <algorithm>
#include <iomanip>
#include <numeric>
#include <vector>
#include <cstring>
#include <string>
#include <set>
#include <map>
#include <queue>
#include <deque>
#include <unordered_map>
#include <unordered_set>
#include <cassert>

#define sz(a) (int)((a).size())
#define all(a) (a).begin(), (a).end()
#define pb push_back

using namespace std; using ll = long long; using pii = pair<int, int>; using vi = vector<int>; using ld = long double;

const int N = (int)1e6;

int n;
vi g[N];
vi vd[N];
vi* l[N];
int pt[N];
int ans[N];

void dfs(int v, int p) {
	l[v] = &vd[v];
	pt[v] = -1;
	for (int to : g[v]) {
		if (to != p) {
			dfs(to, v);
			if (sz(*l[to]) > sz(*l[v])) {
				l[v] = l[to];
				pt[v] = pt[to];
			}
		}
	}
	for (int to : g[v]) {
		if (to != p && l[to] != l[v]) {
			int s1 = sz(*l[v]);
			int s2 = sz(*l[to]);
			for (int i = 0; i < sz(*l[to]); i++) {
				(*l[v])[s1 - 1 - i] += (*l[to])[s2 - 1 - i];
				assert(pt[v] != -1);
				if ((*l[v])[s1 - 1 - i] > (*l[v])[pt[v]] || (*l[v])[s1 - 1 - i] == (*l[v])[pt[v]] && s1 - 1 - i > pt[v]) {
					pt[v] = s1 - 1 - i;
				}
			}
			(*l[to]).shrink_to_fit();
		}
	}
	(*l[v]).pb(1);
	if (pt[v] == -1 || (*l[v])[pt[v]] <= 1) {
		pt[v] = sz(*l[v]) - 1;
	}
	ans[v] = sz(*l[v]) - 1 - pt[v];
}

int32_t main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	//ifstream cin("in.txt");
	cin >> n;
	for (int i = 0; i < n - 1; i++) {
		int u, v; cin >> u >> v; --u; --v; g[u].pb(v); g[v].pb(u);
	}
	dfs(0, -1);
	for (int u = 0; u < n; u++) {
		cout << ans[u] << '\n';
	}
}