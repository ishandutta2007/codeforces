#include<cstdio>
#include<vector>
#include<algorithm>
#define inf 1023456789
#define N 200100
using namespace std;
vector<int> g[N];
int a[N],v[N],n;
int ne[N],nb[N],sz[N];
int e[N];
int ans=0,tb=0;
void DFS(int u,int p,int val){
	sz[u]=ne[u]=e[u]=1;
	nb[u]=0;
	int m[2]={};
	for(int i=0;i<g[u].size();i++){
		int v=g[u][i];
		if(v==p) continue;
		DFS(v,u,val);
		if(ne[u]&&ne[v]) ne[u]+=ne[v];
		else ne[u]=0;
		e[u]+=ne[v];
		nb[u]+=nb[v];
		sz[u]+=sz[v];
		if(e[v]-ne[v]>m[0]){
			m[1]=m[0];
			m[0]=e[v]-ne[v];
		}
		else if(e[v]-ne[v]>m[1]){
			m[1]=e[v]-ne[v];
		}
	}
	if(a[u]<val){
		e[u]=0;
		ne[u]=0;
		nb[u]++;
		return;
	}
	e[u]+=m[0];
	ans=max(ans,e[u]+m[1]+(nb[u]==tb?n-sz[u]:0));	
}
int main(){
	int k,vc;
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		v[i-1]=a[i];
	}
	sort(v,v+n);
	vc=unique(v,v+n)-v;
	int x,y;
	for(int i=1;i<n;i++){
		scanf("%d%d",&x,&y);
		g[x].push_back(y);
		g[y].push_back(x);
	}
	int l=0,r=vc;
	while(l+1<r){
		int m=(l+r)/2;
		ans=0;
		tb=0;
		for(int i=1;i<=n;i++){
			if(a[i]<v[m]) tb++;
		}
		DFS(1,0,v[m]);
		if(ans>=k) l=m;
		else r=m;
	}
	printf("%d\n",v[l]);
	return 0;
}