#include<bits/stdc++.h>
#pragma GCC optimize(3) 
using namespace std;
const int N=1e4+5; 
int n,m,k,x[N],y[N],f[N],sz[N];
int find(int x){return f[x]==x?f[x]:f[x]=find(f[x]);}
int main(){
	cin>>n>>m;
	for(int i=1;i<=m;i++)scanf("%d%d",&x[i],&y[i]);
	cin>>k;
	for(int i=1;i<=k;i++){
		int l,r;
		scanf("%d%d",&l,&r); 
		for(int j=1;j<=n;j++)f[j]=j,sz[j]=1;
		int ans=n;
		for(int j=1;j<l;j++){
			int u=find(x[j]),v=find(y[j]);
			if(u==v)continue;
			ans--; 
			if(sz[u]<sz[v])f[u]=v,sz[v]+=sz[u];
			else f[v]=u,sz[u]+=sz[v]; 
		}
		for(int j=r+1;j<=m;j++){
			int u=find(x[j]),v=find(y[j]);
			if(u==v)continue;
			ans--; 
			if(sz[u]<sz[v])f[u]=v,sz[v]+=sz[u];
			else f[v]=u,sz[u]+=sz[v]; 
		}
		cout<<ans<<endl; 
	} 
	return 0;
}