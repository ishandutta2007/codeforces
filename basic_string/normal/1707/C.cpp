#include<bits/stdc++.h>
using namespace std;
const int N=2e5+3;
int n,m;
basic_string<int>e[N];
struct E{
	int x,y;
}a[N];
int f[N],ct,p[N],id,ed[N],s[N],ans[N],q[N];
set<pair<int,int>>st[N];
int gf(int x){return f[x]==x?x:f[x]=gf(f[x]);}
void dfs(int x,int y){
	p[x]=++id,q[id]=x;
	for(int o:e[x])if(o^y){
		dfs(o,x);
		st[x].insert({p[o],o});
	}
	ed[x]=id;
}
int main(){ios::sync_with_stdio(0);cin.tie(0);
	int i,x,y;
	cin>>n>>m;
	for(i=1;i<=n;++i)f[i]=i;
	
	for(i=1;i<=m;++i){
		cin>>x>>y;
		if(gf(x)!=gf(y)){
			f[gf(x)]=gf(y);
			e[x]+=y,e[y]+=x;
		}else a[++ct]={x,y};
	}
	dfs(1,0);
	for(i=1;i<=ct;++i){
		x=a[i].x,y=a[i].y;
		if(p[x]>p[y])swap(x,y);
		if(p[y]<=ed[x]){
			++s[1];
			++s[p[y]],--s[ed[y]+1];
			auto o=(--st[x].upper_bound({p[y],0}))->second;
			--s[p[o]],++s[ed[o]+1];
		}else{
			++s[p[x]],--s[ed[x]+1];
			++s[p[y]],--s[ed[y]+1];
		}
	}
	for(i=1;i<=n;++i){
		s[i]+=s[i-1];
		if(s[i]==m-n+1)ans[q[i]]=1;
	}
	for(i=1;i<=n;++i)cout<<ans[i];
}