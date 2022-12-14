#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e5 + 10;

vector<int> t[maxn];
int sz[maxn], p[maxn];
int newint = 0;

vector<int> g[maxn];

void dfs(int v, int par = -1, int w = 0){
	g[w].push_back(v);
	int cnt = w;
	for (auto u : t[v]){
		if (u == par)
			continue;
		if (par == -1)
			cnt ++, newint ++;
		dfs(u,v,cnt);
	}
}

int dfssz(int v, int par = -1){
	sz[v] = 1;
	for (auto u : t[v])
		if (u != par)
			sz[v] += dfssz(u, v);
	return sz[v];
}

int main(){
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	for (int i = 1; i <= n-1; i++){
		int v, u;
		cin >> v >> u;
		t[v].push_back(u);
		t[u].push_back(v);
	}
	dfssz(1);
	ll answer = 0;
	for (int i = 1; i <= n; i++)
		answer += 2*min(sz[i], n-sz[i]);
	int cent = 1, par = -1;
	bool found = true;
	while (found){
		found = false;
		for (auto u : t[cent]){
			if (u != par and 2*sz[u] >= n){
				par = cent;
				cent = u;
				found = true;
				break;
			}
		}
	}
	dfs(cent);
	set<pair<int,int>> s;
	for (int i = 0 + (n&1); i <= newint; i++)
		s.insert({-g[i].size(), i});
	while (!s.empty()){
		int v = (*s.begin()).second;
		s.erase(s.begin());
		if (s.empty())
			break;
		int u = (*s.begin()).second;
		s.erase(s.begin());
		int x = g[v].back();
		int y = g[u].back();
		g[v].pop_back();
		g[u].pop_back();
		if (!g[v].empty())
			s.insert({-g[v].size(), v});
		if (!g[u].empty())
			s.insert({-g[u].size(), u});
		p[x] = y;
		p[y] = x;
	}
	for (int i = 1; i <= n; i++){
		if (p[i] == 0){
			for (int j = 1; j <= n; j++)
				if (p[j] != 0){
					p[i] = p[j];
					p[j] = i;
					break;
				}
		}
	}
	cout << answer << endl;
	for (int i = 1; i <= n; i++)
		cout << p[i] << " \n"[i == n];
}