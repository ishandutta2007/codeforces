#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int maxn = 1e5 + 10;

vector<int> t[maxn];
int par[maxn][20], h[maxn];
int Time = 0, st[maxn], pos[maxn];

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

int dis(int v, int u){
	return h[v] + h[u] - 2 * h[lca(v, u)];
}

void dfs(int v, int p = -1){
	pos[Time] = v;
	st[v] = Time ++;
	par[v][0] = p;
	for (int i = 1; i <= 18 and par[v][i - 1] != -1; i++)
		par[v][i] = par[par[v][i - 1]][i - 1];
	for (auto u : t[v]){
		if (u != p){
			h[u] = h[v] + 1;
			dfs(u, v);
		}
	}
}

set<int> s;
int sum = 0;

void add(int v){
	if (s.empty()){
		s.insert(st[v]);
		return;
	}
	auto it = s.lower_bound(st[v]);
	if (it == s.end())
		it = s.begin();
	int nex = pos[*it];
	it = s.lower_bound(st[v]);
	if (it == s.begin())
		it = s.end();
	it --;
	int pre = pos[*it];
	sum -= dis(pre, nex);
	sum += dis(pre, v);
	sum += dis(v, nex);
	s.insert(st[v]);
	
}

void del(int v){
	if (s.size() == 1){
		s.clear();
		return;
	}
	auto it = s.upper_bound(st[v]);
	if (it == s.end())
		it = s.begin();
	int nex = pos[*it];
	it = s.lower_bound(st[v]);
	if (it == s.begin())
		it = s.end();
	it --;
	int pre = pos[*it];
	sum -= dis(pre, v);
	sum -= dis(v, nex);
	sum += dis(pre, nex);
	s.erase(st[v]);
}

int main(){
	ios_base::sync_with_stdio(false);
	int n, k;
	cin >> n >> k;
	for (int i = 1; i <= n - 1; i++){
		int v, u;
		cin >> v >> u;
		t[v].push_back(u);
		t[u].push_back(v);
	}
	memset(par, -1, sizeof par);
	dfs(1);
	int answer = 1, ptr = 1;
	for (int i = 1; i <= n; i++){
		while (ptr <= n){
			add(ptr);
			if ((sum / 2) + 1 > k){
				del(ptr);
				break;
			}
			ptr ++;
		}
		answer = max(answer, ptr - i);
		del(i);
	}
	cout << answer << endl;
}