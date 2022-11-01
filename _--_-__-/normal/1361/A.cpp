#include <bits/stdc++.h>
using namespace std;

const int maxn=500111;
vector<int>g[maxn];
int n,m,p[maxn],ord[maxn];
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1,u,v;i<=m;i++){
		scanf("%d%d",&u,&v);
		g[u].push_back(v);
		g[v].push_back(u);
	}
	for(int i=1;i<=n;i++){
		scanf("%d",p+i);
	}
	bool ok=1;
	for(int i=1;i<=n;i++){
		set<int>all;
		for(int j=0;j<(int)g[i].size();j++){
			all.insert(p[g[i][j]]);
		}
		for(int j=1;j<p[i];j++)if(all.find(j)==all.end())ok=0;
		if(all.find(p[i])!=all.end())ok=0;
	}
	if(!ok)puts("-1");
	else{
		for(int i=1;i<=n;i++)ord[i]=i;
		sort(ord+1,ord+n+1,[](int x,int y){return p[x]<p[y];});
		for(int i=1;i<=n;i++)printf("%d ",ord[i]);
	}
	return 0;
}