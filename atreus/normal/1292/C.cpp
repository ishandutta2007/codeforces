#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int maxn = 3000 + 5;

vector<int> t[maxn];
int h[maxn], st[maxn], ft[maxn], Time;
int sz[maxn];
int par[maxn][maxn];
ll dp[maxn][maxn];
int dis[maxn][maxn];
pair<int,int> a[maxn * maxn];

bool cmp(pair<int,int> fi, pair<int,int> se){
	return dis[fi.first][fi.second] < dis[se.first][se.second];
}

bool insub(int v, int u){
	return st[v] < st[u] and ft[v] >= ft[u];
}

void dfs(int v, int p = -1){
	par[v][0] = v;
	par[v][1] = p;
	for (int i = 2; par[v][i - 1] != -1; i++)
		par[v][i] = par[par[v][i - 1]][1];
	st[v] = Time ++;
	sz[v] = 1;
	for (auto u : t[v]){
		if (u != p){
			h[u] = h[v] + 1;
			dfs(u, v);
			sz[v] += sz[u];
		}
	}
	ft[v] = Time;
}

void DFS(int v, int w, int p = -1){
	for (auto u : t[v]){
		if (u != p){
			dis[w][u] = dis[w][v] + 1;
			DFS(u, w, v);
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	for (int i = 0; i < n - 1; i++){
		int v, u;
		cin >> v >> u;
		v --, u --;
		t[v].push_back(u);
		t[u].push_back(v);
	}
	memset(par, -1, sizeof par);
	dfs(0);
	for (int i = 0; i < n; i++)
		DFS(i, i);
	int t = 0;
	for (int i = 0; i < n; i++)
		for (int j = i + 1; j < n; j++)
			a[t ++] = {i, j};
	sort(a, a + t, cmp);
	ll answer = 0;
	for (int i = 0; i < t; i++){
		int v = a[i].first, u = a[i].second;
		if (h[v] > h[u])
			swap(v, u);
		if (insub(v, u)){
			int diff = h[u] - h[v];
			ll cost = 1ll * sz[u] * (n - sz[par[u][diff-1]]);
			dp[v][u] = max(dp[v][par[u][1]] + cost, dp[par[u][diff-1]][u] + cost);
			dp[u][v] = dp[v][u];
		}
		else{
			ll cost = 1ll * sz[v] * sz[u];
			dp[v][u] = max(dp[par[v][1]][u] + cost, dp[v][par[u][1]] + cost);
			dp[u][v] = dp[v][u];
		}
		answer = max(answer, dp[v][u]);
	}
	cout << answer << endl;
}