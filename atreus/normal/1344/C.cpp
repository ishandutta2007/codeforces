#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef complex<long double> point;

const int maxn = 2e5 + 10;

pair<int,int> e[maxn];
vector<int> g[maxn];
int d[maxn], D[maxn], ft[maxn], pd[maxn], dp[maxn];
vector<int> topol;
bool visited[maxn];

void dfs(int v){
	visited[v] = 1;
	for (auto u : g[v])
		if (!visited[u])
			dfs(u);
	ft[v] = (int)topol.size();
	topol.push_back(v);
}

bool mark[maxn];

int main(){
	ios_base::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++){
		int v, u;
		cin >> v >> u;
		e[i] = {v,u};
		g[v].push_back(u);
		d[u] ++;
		D[v] ++;
	}
	for (int i = 1; i <= n; i++)
		if (!visited[i])
			dfs(i);
	for (int i = 0; i < m; i++){
		int v = e[i].first, u = e[i].second;
		if (ft[v] < ft[u])
			return cout << -1 << endl, 0;
	}
	int cnt = 0;
	for (auto v : topol){
		dp[v] = v;
		for (auto u : g[v])
			dp[v] = min(dp[v], dp[u]);
	}
	reverse(topol.begin(), topol.end());
	for (int v = 1; v <= n; v++)
		pd[v] = v;
	for (auto v : topol)
		for (auto u : g[v])
			pd[u] = min(pd[u], pd[v]);
	for (int v = 1; v <= n; v++)
		if (dp[v] == v and pd[v] == v)
			mark[v] = 1, cnt ++;
	cout << cnt << endl;
	for (int i = 1; i <= n; i++)
		if (mark[i])
			cout << 'A';
		else
			cout << 'E';
	cout << endl;
}