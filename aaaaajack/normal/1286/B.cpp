#include<bits/stdc++.h>
#define N 2010
using namespace std;
int c[N],sz[N],val[N];
int cov[N],ans[N];
vector<int> g[N];
void build(int u){
	sz[u]=1;
	for(int i=0;i<g[u].size();i++){
		int v=g[u][i];
		build(v);
		sz[u]+=sz[v];
	}
}
bool solve(int u){
	if(c[u]>=sz[u]) return false;
	int st=1;
	while(c[u]>0||cov[st]){
		if(!cov[st++]) c[u]--;
	}
	cov[st]=u;
	for(int i=0;i<g[u].size();i++){
		if(!solve(g[u][i])) return false;
	}
	return true;
}
int main(){
	int n,p,rt;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d%d",&p,&c[i]);
		if(p) g[p].push_back(i);
		else rt=i;
	}
	build(rt);
	if(solve(rt)){
		puts("YES");
		for(int i=1;i<=n;i++) ans[cov[i]]=i;
		for(int i=1;i<=n;i++){
			printf("%d%c",ans[i],i==n?'\n':' ');
		}
	}
	else{
		puts("NO");
	}
}