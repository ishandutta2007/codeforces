/**
 *    author:  Atreus
 *    created: 17.01.2019 17:09:02     
**/
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int maxn = 1e5 + 10;

vector <pair <int, int> > t[maxn];
int par[maxn][21], h[maxn];
ll sp[maxn];

int st[maxn], pos[maxn];
int Time = 0;

void dfs(int v, int p = -1){
	st[v] = Time;
	pos[Time ++] = v;

	par[v][0] = p;
	for (int i = 1; i <= 20 and par[v][i - 1] != -1; i++)
		par[v][i] = par[par[v][i - 1]][i - 1];

	for (auto edge : t[v]){
		int u = edge.first, w = edge.second;
		if (u != p){
			sp[u] = sp[v] + w;
			h[u] = h[v] + 1;
			dfs(u, v);
		}
	}
}

int lca(int v, int u){
	if (h[v] < h[u])
		swap(v, u);
	for (int i = 20; i >= 0; i--)
		if (h[v] - (1 << i) >= h[u])
			v = par[v][i];
	if (v == u)
		return v;
	for (int i = 20; i >= 0; i--){
		if (par[v][i] != par[u][i]){
			v = par[v][i];
			u = par[u][i];
		}
	}
	return par[v][0];
}

ll dis(int v, int u){
	return sp[v] + sp[u] - 2ll * sp[lca(v, u)];
}

int main(){
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	for (int i = 0; i < n - 1; i++){
		int v, u, w;
		cin >> v >> u >> w;
		v --, u --;
		t[v].push_back({u, w});
		t[u].push_back({v, w});
	}
	memset(par, -1, sizeof par);
	dfs(0);
	int nq;
	cin >> nq;
	set <int> s;
	ll answer = 0;
	while (nq --){
		char type;
		cin >> type;
		if (type == '+'){
			int v;
			cin >> v;
			v --;
			if (!s.empty()){
				auto fi = s.upper_bound(st[v]);
				if (fi == s.end())
					fi = s.begin();
				auto se = s.upper_bound(st[v]);
				if (se == s.begin())
					se = s.end();
				se --;
				
				answer -= dis(pos[*fi], pos[*se]);
				answer += dis(pos[*fi], v);
				answer += dis(pos[*se], v);
			}
			s.insert(st[v]);
		}
		else if (type == '-'){
			int v;
			cin >> v;
			v --;
			if (s.size() > 1){
				auto fi = s.upper_bound(st[v]);
				if (fi == s.end())
					fi = s.begin();
				auto se = s.find(st[v]);
				if (se == s.begin())
					se = s.end();
				se --;
				int u = pos[*fi], w = pos[*se];
			
				answer += dis(u, w);
				answer -= dis(u, v);
				answer -= dis(w, v);
			}
			s.erase(st[v]);
		}
		else
			cout << (answer >> 1) << '\n';
	}
}