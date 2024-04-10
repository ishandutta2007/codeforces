#include <bits/stdc++.h>

using namespace std;

typedef double D;
typedef long long int LL;

#define st first
#define nd second
#define pb push_back
#define PLL pair <LL, LL>
#define PII pair <int, int>
#define PIII pair <PII, int>

const int N = 2e5 + 7;
const int MX = 1e9 + 7;
const int inf = 1e9 + 9;

int n, m;
int pod[N];
int dad[N];
bool block[N];
vector <int> G[N];
vector <PIII> res;
vector <int> change;

int dfs(int u, int p){
	pod[u] = 1;
	for(int v: G[u])
		if(v != p && !block[v])
			pod[u] += dfs(v, u);
	return pod[u];
}

PII centroid(int u){
	dfs(u, u);
	int par = u;
	int half = (pod[u] + 1) / 2;
	bool even = (pod[u] & 1) ? 0 : 1;
	
	bool change = true;
	while(change){
		change = false;
		for(int v: G[u])
			if(pod[v] >= half && !block[v] && v != par){
				change = true;
				par = u;
				u = v;
				break;
			}
	}
	
	if(pod[u] == half && even)
		return {u, par};
	return {u, -1};
}

void dfs2(int u, int p, int d){
	if(d > 1)
		change.pb(u);
	dad[u] = p;

	for(int v: G[u])
		if(v != p)
			dfs2(v, u, d + 1);
}

inline void add(int x, int y, int z){
	res.pb({{x, y}, z});
}

void solve(int u){
	if(u == -1)
		return;
	
	for(int v: G[u]){
		if(block[v])
			continue;
		dfs2(v, u, 0);
		
		int last = v;
		for(int cur: change){
			add(u, last, cur);
			add(cur, dad[cur], v);
			last = cur;
		}
		
		if(last != v)
			add(u, last, v);
		change.clear();
	}
}

int main(){
	scanf("%d", &n);
	for(int i = 1; i < n; ++i){
		int u, v;
		scanf("%d %d", &u, &v);
		G[u].pb(v);
		G[v].pb(u);
	}
	
	PII centroidy = centroid(1);
	block[centroidy.st] = block[centroidy.nd == -1 ? 0 : centroidy.nd] = true;

	solve(centroidy.st);
	solve(centroidy.nd);
	
	printf("%d\n", (int)res.size());
	for(int i = 0; i < (int)res.size(); ++i)
		printf("%d %d %d\n", res[i].st.st, res[i].st.nd, res[i].nd);
	return 0;
}