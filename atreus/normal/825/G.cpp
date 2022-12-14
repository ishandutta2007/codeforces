#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;

const int maxn = 1e6 + 10;

int gm, par[maxn], dp[maxn];
vector<int> t[maxn];
bool mark[maxn];

void dfs(int v, int p = -1){
	par[v] = p;
	for (auto u : t[v]){
		if (u != p){
			dp[u] = min(dp[v], u);
			dfs(u, v);
		}
	}
}

void add(int v){
	if (mark[v])
		return;
	mark[v] = 1;
	gm = min(gm, v);
	add(par[v]);
}

int main(){
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n - 1; i++){
		int v, u;
		scanf("%d%d", &v, &u);
		t[v].push_back(u);
		t[u].push_back(v);
	}
	int last = 0;
	int type, v;
	scanf("%d%d", &type, &v);
	v = (v + last) % n + 1;
	gm = v;
	dp[v] = v;
	mark[v] = 1;
	dfs(v);
	m --;
	while (m --){
		scanf("%d%d", &type, &v);
		v = (v + last) % n + 1;
		if (type == 1)
			add(v);
		else{
			last = min(dp[v], gm);
			printf("%d ", last);
		}
	}
}