#include<bits/stdc++.h>
using namespace std;
enum{N=300009};
int w[N],fa[N],fe[N],a[N],e[N],p[N];
bool be[N];
long long d[N];
vector<pair<int,int>>v[N];
void dfs(int x){for(auto o:v[x])if(o.first!=fa[x])fa[o.first]=x,fe[o.first]=o.second,dfs(o.first);}
int main(){ios::sync_with_stdio(0),cin.tie(0);
	int n,m,i,j,k,t=0;
	long long mx=-1e18,m2=mx;
	cin>>n>>m;
	for(i=1;i<n;++i)cin>>j>>k>>w[i],v[j].push_back({k,i}),v[k].push_back({j,i});
	dfs(1);
	for(i=n;i;i=fa[i])a[++t]=i,p[i]=t,be[fe[i]]=1,d[t+1]=d[t]+w[fe[i]];
	for(i=1;i<=n;++i){
		j=0;
		for(auto o:v[i])if(!be[o.second])++j,e[p[i]]=w[o.second];
		if(j>1){
			while(m--)cout<<d[t]<<'\n';
			return 0;
		}
	}
	for(i=3;i<=t;++i)mx=max(mx,d[i-2]-d[i]);
	for(i=1;i<=t;++i)if(e[i]){
		if(i>1)mx=max(mx,e[i]+d[i-1]-d[i]);
		if(i<t)mx=max(mx,e[i]+d[i]-d[i+1]);
	}
	for(i=1;i<=t;++i)if(e[i])mx=max(mx,e[i]-d[i]+m2),m2=max(m2,e[i]+d[i]);
	while(m--)cin>>i,cout<<min(0ll,i+mx)+d[t]<<'\n';
	return 0;
}