#include <bits/stdc++.h>
#ifndef AECODE
#define eprint if(false) printf
#else
#define eprint printf("DEBUG "), printf
#endif
#define sz(x) ((int)(x).size())
using namespace std;

const int MAXN=100001,MAXD=18,MAXA=10;
int n,m,Q,ea[MAXD][MAXN],ecnt[MAXD][MAXN],de[MAXN];
vector<int> ec[MAXD][MAXN];
vector<int> adj[MAXN];

void add(vector<int> &ta, vector<int> &sa) {
	vector<int> res;
	int i,j,k,tc=sz(ta),sc=sz(sa);
	for(i=0,j=0,k=0;k<MAXA && (i<tc || j<sc);k++) {
		if(i!=tc && (j==sc || ta[i] < sa[j])) res.push_back(ta[i++]);
		else res.push_back(sa[j++]);
	}
	ta = res;
}
void make_dfs(int cur,int p,int d) {
	int pp=p, a=1;
	ea[0][cur] = p, de[cur] = d;
	while(ea[a-1][pp]) {
		add(ec[a][cur], ec[a-1][pp]);
		add(ec[a][cur], ec[a-1][cur]);
		pp = ea[a][cur] = ea[a-1][pp];
		a++;
	}
	for(auto &v:adj[cur]) if(v!=p) make_dfs(v,cur,d+1);
}
void lca(int u,int v,vector<int>& res) {
	if(de[u] > de[v]) swap(u,v);

	int dif=de[v]-de[u];
	for(int i=0;1<<i<=dif;i++) if(dif>>i & 1) {
		add(res, ec[i][v]);
		v = ea[i][v];
	}
	if(u==v) {
		add(res, ec[0][v]);
		return;
	}
	for(int i=MAXD-1;i>=0;i--) if(ea[i][u]!=ea[i][v]) {
		add(res, ec[i][u]);
		add(res, ec[i][v]);
		u = ea[i][u], v = ea[i][v];
	}
	add(res, ec[0][u]);
	add(res, ec[0][v]);
	add(res, ec[0][ea[0][v]]);
}

int main() {
	int f=0;
	scanf("%d%d%d",&n,&m,&Q);
	for(int i=1,u,v;i<n;i++) {
		scanf("%d%d",&u,&v);
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	for(int i=1,v;i<=m;i++) {
		scanf("%d",&v);
		if(sz(ec[0][v]) < MAXA) ec[0][v].push_back(i);
	}

	make_dfs(1,0,0);

	while(Q--) {
		int v,u,a;
		vector<int> res;
		scanf("%d%d%d",&u,&v,&a);
		lca(u,v,res);

		res.resize(min(sz(res),a));

		printf("%d ",sz(res));
		for(auto &t:res) printf("%d ",t);
		puts("");
	}
	
	return 0;
}