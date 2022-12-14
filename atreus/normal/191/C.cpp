#include <iostream>
#include <queue>
#include <stack>
#include <vector>
#include <cstring>
#include <cmath>
#include <unordered_set>
#include <map>
#include <deque>
#include <unordered_map>
#include <fstream>
#include <set>
#include <algorithm>
#include <iomanip>
#define fin cin
#define fout cout
#define F first
#define S second
#define PB push_back
#define PF push_front
#define MP make_pair
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pll;
typedef pair<int,int> pii;
typedef unsigned long long ull;
const int maxn = 1e5 + 5;
const int mod = 1e9 + 9;
const int inf = (1 << 30);
const int block = 316;
const int Del = 12157;
const ll Inf = 1e18;

vector <pii> v[maxn];

vector <int> g[maxn];

set <int> s[maxn];

int c[maxn], ans[maxn];

void dfs (int u, int parent = -1, int idx = 0) {
	for (auto w : v[u]) {
		if (w.F != parent) {
			dfs (w.F, u, w.S);
			if (s[c[w.F]].size() > s[c[u]].size())
				c[u] = c[w.F];
		}
	}
	for (auto w : v[u]) {
		if (w.F != parent and c[u] != c[w.F]) {
			for (auto j : s[c[w.F]]) {
				if (s[c[u]].find (j) != s[c[u]].end())
					s[c[u]].erase (j);
				else
					s[c[u]].insert (j);
			}
		}
	}
	
	for (auto w : g[u]) {
		if (s[c[u]].find (w) != s[c[u]].end())
			s[c[u]].erase (w);
		else
			s[c[u]].insert (w);
	}

	ans[idx] = s[c[u]].size();
}

int main () {
	ios_base::sync_with_stdio (false);
	int n;
	cin >> n;
	for (int i = 1; i < n; i++) {
		int u, w;
		cin >> u >> w;
		v[u].PB ({w, i});
		v[w].PB ({u, i});
	}
	
	int q;
	cin >> q;
	for (int i = 1; i <= q; i++) {
		int u, w;
		cin >> u >> w;
		g[u].PB (i);
		g[w].PB (i);
	}

	for (int i = 1; i <= n; i++)
		c[i] = i;
	dfs (1);
	
	for (int i = 1; i < n; i++)
		cout << ans[i] << " ";
	cout << endl;
	return 0;
}