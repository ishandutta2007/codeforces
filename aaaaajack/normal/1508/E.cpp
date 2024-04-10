#include<bits/stdc++.h>
#define N 300100
using namespace std;
int a[N],b[N],ans[N],od[N],par[N],deg[N];
vector<int> g[N];
bool cmp(int i,int j){
	return a[i]<a[j];
}
long long DFS(int u,int d,int piv, int& s1, int& spiv,int *lab, bool &gg){
	long long ans=a[u]<piv?d:0;
	if(a[u]>=piv) lab[u]=spiv++;
	for(int i=0;i<g[u].size();i++){
		ans+=DFS(g[u][i],d+1,piv,s1,spiv,lab,gg);
	}
	if(a[u]<piv) lab[u]=s1++;
	else if(s1<piv) gg=true;
	return ans;
}
int main(){
	int n;
	long long day=0;
	bool gg=false;
	scanf("%d",&n);
	int piv=1;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		od[a[i]]=i;
	}
	for(int i=1;i<n;i++){
		int u,v;
		scanf("%d%d",&u,&v);
		g[u].push_back(v);
		deg[u]++;
		par[v]=u;
	}	
	while(piv<=n && !deg[od[piv]]){
		deg[par[od[piv]]]--;
		piv++;
	}
	if(piv<=n){
		for(int u=od[piv];par[u];u=par[u]){
			swap(a[u],a[par[u]]);
			day++;
		}
		for(int u=od[piv];par[u];u=par[u]){
			if(a[u]!=a[par[u]]+1) gg=true;
		}
	}
	for(int i=1;i<=n;i++){
		sort(g[i].begin(),g[i].end(),cmp);
	}
	int s1=1,spiv=piv;
	day+=DFS(1,0,piv,s1,spiv,b,gg);
	for(int i=1;i<=n;i++){
		if(a[i]!=b[i]) gg=true;
	}
	if(gg) puts("NO");
	else{
		puts("YES");
		printf("%lld\n",day);
		s1=spiv=1;
		DFS(1,0,1,s1,spiv,ans,gg);
		for(int i=1;i<=n;i++) printf("%d ",ans[i]);
		puts("");
	}
	return 0;
}