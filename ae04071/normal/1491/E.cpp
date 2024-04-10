#include <bits/stdc++.h>
using namespace std;

int n,vis[200001],sz[200001],pa[200001];
vector<int> adj[200001];

int fib[31];
map<int, int> fm;

void init(int cur,int p) {
	for(auto &v:adj[cur]) if(v!=p) init(v, cur);
	pa[cur] = p;
}

void get_sz(int cur,int p) {
	sz[cur] = 1;
	for(auto &v:adj[cur]) if(!vis[v] && v!=p) {
		get_sz(v, cur);
		sz[cur] += sz[v];
	}
}
int find_subr(int cur,int p,int ts) {
	if(sz[cur] == ts) return cur;
	for(auto &v:adj[cur]) if(!vis[v] && v!=p) {
		int val;
		if( (val = find_subr(v, cur, ts)) )
			return val;
	}
	return 0;
}
bool div_fib(int root) {
	get_sz(root, 0);
	if(sz[root] == 1) return true;

	auto it = fm.find(sz[root]);
	if (it == fm.end()) return false;

	int sr = find_subr(root, 0, it->second);
	if(!sr) {
		sr = find_subr(root, 0, sz[root] - it->second);
		if(!sr) 
			return false;
	}

	bool f = true;
	vis[pa[sr]] = 1;
	f &= div_fib(sr);
	vis[pa[sr]] = 0;
	vis[sr] = 1;
	f &= div_fib(root);
	vis[sr] = 0;
	
	return f;
}

int main() {
	scanf("%d",&n);
	for(int i=1,u,v;i<n;i++) {
		scanf("%d%d",&u,&v);
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	fib[0] = fib[1] = 1;
	for(int i=2;i<=30;i++) {
		fib[i] = fib[i-1] + fib[i-2];
		fm[fib[i]] = fib[i-2];
	}
	init(1, 0);
	puts(div_fib(1) ? "YES" : "NO");
	
	return 0;
}