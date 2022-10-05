#include<bits/stdc++.h>
using namespace std;
enum{N=600009};
vector<pair<int,int>>g[N][2];
bool b[N],w[N],vis[N],ans[N];
int x[N],y[N],f1[N],f2[N],dg[N];
void dfs(int x,int y=0){
	if(vis[x])return;
	vis[x]=1;
	for(auto o:g[x][0])if(!b[o.second])b[o.second]=1,dfs(o.first,x),ans[o.second]=(x==::x[o.second]);
	for(auto o:g[x][1])if(!b[o.second])b[o.second]=1,dfs(o.first,x),ans[o.second]=(x==::x[o.second]);
}
int main(){ios::sync_with_stdio(0),cin.tie(0);
	int n,m,i,j,k,l,t;
	pair<int,int>u,v;
	cin>>n>>m,t=m;
	for(i=1;i<=m;++i){
		cin>>j>>k>>l,--l,x[i]=j,y[i]=k;
		if(!l)w[j]^=1,w[k]^=1;
		g[j][l].push_back({k,i}),g[k][l].push_back({j,i});
	}
	for(i=1,j=0;i<=n;++i)j+=w[i];
	cout<<j<<'\n';
	for(i=1;i<=n;++i)for(l=0;l<2;++l){
		auto&o=g[i][l];
		while(1){
			while(size(o)&&b[o.back().second])o.pop_back();
			if(size(o))u=o.back(),o.pop_back(),b[u.second]=1;else break;
			while(size(o)&&b[o.back().second])o.pop_back();
			if(empty(o)){o.push_back(u),b[u.second]=0;break;}
			v=o.back(),o.pop_back();
			x[++t]=u.first,y[t]=v.first;
			f1[t]=u.second,b[f2[t]=v.second]=1;
			g[x[t]][l].push_back({y[t],t}),g[y[t]][l].push_back({x[t],t});
		}
	}
	for(i=1;i<=n;++i){
		for(auto o:g[i][0])if(!b[o.second])++dg[i];
		for(auto o:g[i][1])if(!b[o.second])++dg[i];
	}
	for(i=1;i<=n;++i)if(dg[i]==1)dfs(i);
	for(i=1;i<=n;++i)dfs(i);
	for(i=t;i>m;--i){
		if(x[f2[i]]==x[i]||y[f2[i]]==x[i])swap(f1[i],f2[i]);
		if(x[f1[i]]==x[i])ans[f1[i]]=ans[i];else ans[f1[i]]=!ans[i];
		if(y[f2[i]]==y[i])ans[f2[i]]=ans[i];else ans[f2[i]]=!ans[i];
	}
	for(i=1;i<=m;++i)cout<<int(ans[i])+1;
	return 0;
}