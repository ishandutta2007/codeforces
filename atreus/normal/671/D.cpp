#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn = 3e5 + 5;

ll dp[maxn], lazy[maxn], val[maxn], c[maxn];
int cmp[maxn];
vector<int> t[maxn], st[maxn], fi[maxn];
set<pair<ll, int> > s[maxn];

ll dfs(int v, int p = -1){
	cmp[v] = v;
	ll sum = 0;
	for (auto u : t[v])
		if (u != p)
			sum += dfs(u, v);

	for (auto u : t[v]){
		if (u != p){
			lazy[cmp[u]] += sum - dp[u];
			if (s[cmp[v]].size() < s[cmp[u]].size())
				swap(cmp[v], cmp[u]);
			while (!s[cmp[u]].empty()){
				auto nex = *s[cmp[u]].begin();
				val[nex.second] = nex.first + lazy[cmp[u]] - lazy[cmp[v]];
				s[cmp[v]].insert({val[nex.second], nex.second});
				s[cmp[u]].erase(nex);
			}
		}
	}
	for (auto it : st[v])
		val[it] = c[it] + sum - lazy[cmp[v]], s[cmp[v]].insert({val[it], it});
	for (auto it : fi[v])
		s[cmp[v]].erase({val[it], it});
	if (v == 0)
		return 0;
	if (s[cmp[v]].empty()){
		cout << -1 << endl;
		exit(0);
	}
	dp[v] = (*s[cmp[v]].begin()).first + lazy[cmp[v]];
	return dp[v];
}

int main(){
	ios_base::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n - 1; i++){
		int x, y;
		cin >> x >> y;
		x --, y --;
		t[x].push_back(y);
		t[y].push_back(x);
	}
	for (int i = 0; i < m; i++){
		int u, v;
		cin >> u >> v >> c[i];
		u --, v --;
		st[u].push_back(i);
		fi[v].push_back(i);
	}
	dfs(0);
	ll answer = 0;
	for (auto u : t[0])
		answer += dp[u];
	cout << answer << endl;
}