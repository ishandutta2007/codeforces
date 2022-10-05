#include<bits/stdc++.h>
using namespace std;
const int N=1e5+3;
typedef int ar[N];
ar ans,sn,sz,fa,l,r,p,ct,s,a;
int id;
vector<pair<int,int>>q[N];
basic_string<int>g[N];
void dfs(int x,int y){
	fa[x]=y,sz[x]=1,p[l[x]=++id]=x;
	for(int i:g[x])if(i!=y)if(dfs(i,x),sz[x]+=sz[i],sz[i]>sz[sn[x]])sn[x]=i;
	r[x]=id;
}
void dp(int x,bool b){
	for(int i:g[x])if(i!=fa[x]&&i!=sn[x])dp(i,1);
	if(sn[x])dp(sn[x],0);
	++s[++ct[a[x]]];
	for(int i:g[x])if(i!=fa[x]&&i!=sn[x])for(int j=l[i];j<=r[i];++j)++s[++ct[a[p[j]]]];
	for(auto i:q[x])ans[i.second]=s[i.first];
	if(b)for(int i=l[x];i<=r[x];++i)--s[ct[a[p[i]]]--];
}
int main(){
	int n,m,i,j,k;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;++i)scanf("%d",a+i);
	for(i=1;i<n;++i)scanf("%d%d",&j,&k),g[j]+=k,g[k]+=j;
	for(i=1;i<=m;++i)scanf("%d%d",&j,&k),q[j].push_back({k,i});
	dfs(1,0),dp(1,0);
	for(i=1;i<=m;++i)printf("%d\n",ans[i]);
	return 0;
}