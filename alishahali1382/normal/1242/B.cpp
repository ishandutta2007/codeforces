#include <bits/stdc++.h>
#if defined(__GNUC__)
#pragma GCC optimize ("Ofast")
#endif
using namespace std;
#define pb push_back
const int MAXN = 100010;

struct DSU{
	int par[MAXN];
	int sz[MAXN];
	DSU(){
		for (int i=1; i<MAXN; i++) par[i]=i;
		for (int i=1; i<MAXN; i++) sz[i]=1;
	}
	int get(int x){
		if (par[x]==x) return x;
		return par[x]=get(par[x]);
	}
	void join(int x, int y){
		x=get(x);
		y=get(y);
		if (x==y) return ;
		if (sz[x]>sz[y]) swap(x, y);
		par[x]=y;
		sz[y]+=sz[x];
	}
} dsu;

int n, m, u, v, x, t, root=1;
int mark[MAXN];
vector<int> G[MAXN];
vector<int> out[MAXN];

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	while (m--){
		cin>>u>>v;
		G[u].pb(v);
		G[v].pb(u);
	}
	for (int i=2; i<=n; i++) if (G[i].size()<G[root].size()) root=i;
	for (int i=0; i<=n; i++) mark[i]=2;
	for (int i:G[root]) mark[i]=1;
	for (int i=1; i<=n; i++) if (mark[i]==2) dsu.join(root, i);
	
	for (int i:G[root]){
		int tmp=0;
		for (int j:G[i]){
			if (mark[j]==2) tmp++;
			else mark[j]=0;
		}
		if (tmp<n-G[root].size()) dsu.join(root, i);
		for (int j:G[root]) if (mark[j]==1) dsu.join(i, j);
		for (int j:G[i]) if (mark[j]!=2) mark[j]=1;
	}
	
	for (int i=1; i<=n; i++){
		if (dsu.get(i)==i) t++;
	}
	cout<<t-1<<'\n';
		
	return 0;
}