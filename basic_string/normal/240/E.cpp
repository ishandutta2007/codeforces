#include<bits/stdc++.h>
using namespace std;
enum{N=100009,M=N};
int x[M],y[M],x2[M],y2[M],w2[M],w[M],ie[N],p[N],id[N],v[N],ae[N];
basic_string<int>g[N];
void dfs(int x){for(int i:g[x])if(!ae[y2[i]])ae[y2[i]]=i,dfs(y2[i]);}
int main(){
ifstream cin("input.txt");ofstream cout("output.txt");
	int n2,r2,n,m,r,i,j,k,t,o=0;
	for(cin>>n>>m,n2=n,r=r2=i=1;i<=m;++i)cin>>x[i]>>y[i]>>w[i],x2[i]=x[i],y2[i]=y[i],w2[i]=w[i];
	for(w[0]=1e8;;n=t,r=id[r]){
		for(memset(ie,0,N*4),i=1;i<=m;++i)if(x[i]!=y[i]&&w[i]<w[ie[y[i]]])ie[y[i]]=i,p[y[i]]=x[i];
		for(i=1;i<=n;++i)if(i!=r&&!ie[i])return cout<<-1,0;
		for(memset(v,0,N*4),memset(id,t=0,N*4),i=1,v[r]=N;i<=n;++i)if(i!=r){
			for(o+=w[ie[i]],g[x2[ie[i]]]+=ie[i],j=i;!v[j];j=p[j])v[j]=i;
			if(v[j]==i)for(++t,k=j;id[k=p[k]]=t,k!=j;);
		}
		if(!t){cout<<o<<'\n';break;}
		for(i=1;i<=n;++i)if(!id[i])id[i]=++t;
		for(i=1;i<=m;x[i]=id[x[i]],y[i]=id[y[i]],++i)if(id[x[i]]^id[y[i]])w[i]-=w[ie[y[i]]];
	}
	for(dfs(r2),i=1;i<=n2;++i)if(i!=r2&&w2[ae[i]])cout<<ae[i]<<' ';
	return 0;
}