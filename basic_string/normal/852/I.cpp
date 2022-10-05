#include<bits/stdc++.h>
using namespace std;
enum{N=100009,B=633};
map<int,int>mp;
basic_string<int>g[N];
bool b[N],v[N];
int a[N],n,m,id,o[N*2],p[N],sz[N],sn[N],fa[N],d[N],tp[N],c[N][2];
long long ans[N],now;
void dfs(int x){
	o[++id]=x,p[x]=id,sz[x]=1;
	for(int i:g[x])if(!p[i])if(fa[i]=x,d[i]=d[x]+1,dfs(i),sz[x]+=sz[i],sz[i]>sz[sn[x]])sn[x]=i;
	o[++id]=x;
}
void dfs(int x,int y){
	if(tp[x]=y,sn[x])dfs(sn[x],y);
	for(int i:g[x])if(!tp[i])dfs(i,i);
}
int lca(int x,int y){
	for(;tp[x]!=tp[y];x=fa[tp[x]])if(d[tp[x]]<d[tp[y]])swap(x,y);
	return d[x]<d[y]?x:y;
}
struct Q{
	int l,r,i;
}q[N];
void upd(int x){
	if(v[x]^=1)now+=c[a[x]][b[x]],++c[a[x]][b[x]^1];
	else now-=c[a[x]][b[x]],--c[a[x]][b[x]^1];
}
int main(){ios::sync_with_stdio(0),cin.tie(0);
	int i,j=0,k,x,l=1,r=0;
	for(cin>>n,i=1;i<=n;++i)cin>>b[i];
	for(i=1;i<=n;a[i++]=mp[k])if(cin>>k,!mp[k])mp[k]=++j;
	for(i=1;i<n;++i)cin>>j>>k,g[j]+=k,g[k]+=j;
	dfs(1),dfs(1,1);
	for(cin>>m,i=1;i<=m;++i){
		if(cin>>j>>k,p[j]>p[k])swap(j,k);
		q[i]={p[j],p[k],i};
	}
	sort(q+1,q+m+1,[](Q a,Q b){return a.l/B<b.l/B||(a.l/B==b.l/B&&((a.l/B&1)?a.r<b.r:a.r>b.r));});
	for(i=1;i<=m;++i){
		while(r<q[i].r)upd(o[++r]);
		while(l>q[i].l)upd(o[--l]);
		while(r>q[i].r)upd(o[r--]);
		while(l<q[i].l)upd(o[l++]);
		j=o[l],k=o[r],x=lca(j,k);
		if(j!=x)if(upd(j),k!=x)upd(x);
		ans[q[i].i]=now;
		if(j!=x)if(upd(j),k!=x)upd(x);
	}
	for(i=1;i<=m;++i)cout<<ans[i]<<'\n';
}