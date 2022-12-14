/**
 *    author:  Atreus
 *    created: 23.01.2019 17:20
 **/
#include <bits/stdc++.h>
#define F first
#define S second

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;

const int maxn = 2e5 + 10;
int n, st[maxn], ft[maxn], pos[maxn], h[maxn], par[maxn][20], dp[maxn][20];
vector<int> t[maxn];

int lca(int v, int u){
	if (h[v] < h[u])
		swap(v, u);
	for (int i = 18; i >= 0; i--)
		if (h[v] - (1 << i) >= h[u])
			v = par[v][i];
	if (v == u)
		return v;
	for (int i = 18; i >= 0; i--){
		if (par[v][i] != par[u][i]){
			v = par[v][i];
			u = par[u][i];
		}
	}
	return par[v][0];
}

int Time = 1;
void dfs(int v, int p = -1){
	st[v] = Time;
	pos[Time++] = v;

	par[v][0] = p;
	for (int i = 1; i <= 18 and par[v][i - 1]; i++)
		par[v][i] = par[par[v][i - 1]][i - 1];

	for (auto u : t[v]){
		h[u] = h[v] + 1;
		dfs(u, v);
	}
	ft[v] = Time;
}

vector<int> seg[4 * maxn];

int get(int id, int L, int R, int l, int r, int lb, int ub){
	if (L == l and R == r){
		int idx = lower_bound(seg[id].begin(), seg[id].end(), lb) - seg[id].begin();
		if (idx == seg[id].size() or seg[id][idx] > ub)
			return n + 1;
		return seg[id][idx];
	}
	int mid = (L + R) >> 1;
	int ret = n + 1;
	if (l < mid)
		ret = min(ret, get(2 * id + 0, L, mid, l, min(mid, r), lb, ub));
	if (mid < r)
		ret = min(ret, get(2 * id + 1, mid, R, max(l, mid), r, lb, ub));
	return ret;
}

void change(int id, int L, int R, int idx, int x){
	seg[id].push_back(x);
	if (L + 1 == R)
		return;
	int mid = (L + R) >> 1;
	if (idx < mid)
		change(2 * id + 0, L, mid, idx, x);
	else
		change(2 * id + 1, mid, R, idx, x);
}

void solve(int v, int u){
	if (h[v] < h[u])
		swap(v, u);
	int answer = 0;
	for (int i = 18; i >= 0; i--){
		if (h[dp[v][i]] > h[u]){
			v = dp[v][i];
			answer += (1 << i);
		}
	}
	if (dp[v][0] == -1)
		cout << -1 << endl;
	else
		cout << answer + 1 << endl;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin >> n;
	for (int i = 2; i <= n; i++){
		int p;
		cin >> p;
		t[p].push_back(i);
	}
	dfs(1);
	int m;
	cin >> m;
	for (int i = 0; i < m; i++){
		int v, u;
		cin >> v >> u;
		int w = lca(v, u);
		change(1, 1, n + 1, st[v], st[u]);
		change(1, 1, n + 1, st[v], st[w]);
		change(1, 1, n + 1, st[u], st[v]);
		change(1, 1, n + 1, st[u], st[w]);
	}
	for (int i = 1; i < 4 * maxn; i++)
		sort(seg[i].begin(), seg[i].end());
	pos[n + 1] = -1;
	memset(dp, -1, sizeof dp);
	for (int v = 1; v <= n; v++){
		int u = get(1, 1, n + 1, st[v], ft[v], 1, n);
		dp[v][0] = pos[u];
		if (h[dp[v][0]] >= h[v])
			dp[v][0] = -1;
		for (int j = 1; j <= 18 and dp[v][j - 1] != -1; j++)
			dp[v][j] = dp[dp[v][j - 1]][j - 1];
	}
	int q;
	cin >> q;
	for (int i = 0; i < q; i++){
		int v, u;
		cin >> v >> u;
		int w = lca(v, u);
		if (v == w or u == w){
			solve(v, u);
			continue;
		}
		int answer = 0;
		for (int i = 18; i >= 0; i--){
			if (dp[v][i] != -1 and h[dp[v][i]] > h[w]){
				v = dp[v][i];
				answer += (1 << i);
			}
			if (dp[u][i] != -1 and h[dp[u][i]] > h[w]){
				u = dp[u][i];
				answer += (1 << i);
			}
		}
		if (dp[v][0] == -1 or dp[u][0] == -1){
			cout << -1 << '\n';
			continue;
		}
		if (get(1, 1, n + 1, st[v], ft[v], st[u], ft[u] - 1) == n + 1)
			cout << answer + 2 << '\n';
		else
			cout << answer + 1 << '\n';
	}
}