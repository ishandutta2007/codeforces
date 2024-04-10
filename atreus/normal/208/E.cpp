#include <iostream>
#include <sstream>
#include <queue>
#include <stack>
#include <deque>
#include <vector>
#include <cstring>
#include <cmath>
#include <map>
#include <unordered_map>
#include <set>
#include <algorithm>
#include <iomanip>
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
const ll inf = 1e18;

int dp[maxn], h[maxn], ans[maxn], p[maxn];
int par[maxn][25];
vector <int> g[maxn];
vector <pii> q[maxn];

void dfs (int v, int prnt = -1) {
	dp[h[v]] ++;
	for (auto Q : q[v]) 
		ans[Q.F] -= dp[h[v] + Q.S];
	for (auto u : g[v])
		if (u != prnt)
			dfs (u, v);
	for (auto Q : q[v])
		ans[Q.F] += dp[h[v] + Q.S];
}

void dfs1 (int v, int prnt = -1) {
	par[v][0] = prnt;
	for (int i = 1; i <= 20 and par[v][i - 1] != -1; i++)
		par[v][i] = par[par[v][i - 1]][i - 1];
	for (auto w : g[v]) {
		if (w != prnt) {
			h[w] = h[v] + 1;
			dfs1 (w, v);
		}
	}
}

int ancesor (int v, int x) {
	if (x > h[v])
		return 0;
	for (int i = 0; i < 20; i++)
		if (x & (1 << i))
			v = par[v][i];
	return v;
}

int main() {
	ios_base::sync_with_stdio(false);
	memset (par, -1, sizeof par);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> p[i];
		if (p[i] != 0) {
			g[p[i]].PB (i);
			g[i].PB (p[i]);
		}
	}
	for (int i = 1; i <= n; i++) 
		if (p[i] == 0)
			dfs1 (i);
	int m;
	cin >> m;
	for (int i = 1; i <= m; i++) {
		int v, ped;
		cin >> v >> ped;
		int u = ancesor (v, ped);
		if (u == 0) {
			ans[i] = 1;
		}
		else {
			q[u].PB ({i, ped});
		}
	}
	for (int i = 1; i <= n; i++)
		if (p[i] == 0)
			dfs (i);
	for (int i = 1; i <= m; i++)
		cout << ans[i] - 1 << ' ';
}