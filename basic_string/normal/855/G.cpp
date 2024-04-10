#include<bits/stdc++.h>
using namespace std;
const int N=1e5+3;
using ll=long long;
int f[N],s[N],fa[N],sz[N],n,d[N];
ll g[N],ans;
basic_string<int>e[N];
int gf(int x){return f[x]==x?x:f[x]=gf(f[x]);}
void dfs(int x,int y){
	fa[x]=y,sz[x]=s[x]=1,f[x]=x,d[x]=d[y]+1;
	for(int i:e[x])if(i!=y)dfs(i,x),sz[x]+=sz[i],g[x]+=sz[i]*1ll*sz[i];
	ans+=(n-1ll)*(n-1)-g[x]-(n-sz[x])*1ll*(n-sz[x]);
}
void mg(int&x,int y){
	ans+=s[x]*2ll*s[y]*(n-s[x]-s[y]);
	ans+=s[y]*((sz[x]-s[x])*1ll*(sz[x]-s[x])-g[x]);
	ans+=s[x]*((n-sz[x]-s[y])*1ll*(n-sz[x]-s[y])-g[y]+sz[x]*1ll*sz[x]-(n-sz[y])*1ll*(n-sz[y]));
	ans+=s[x]*1ll*s[y]*(s[x]-1);
	ans+=s[y]*1ll*s[x]*(s[y]-1);
	g[y]=g[y]-sz[x]*1ll*sz[x]+g[x];
	f[x]=y,s[y]+=s[x],x=y;
}
int main(){
	int i,j,k,q;
	scanf("%d",&n);
	for(i=1;i<n;++i)scanf("%d%d",&j,&k),e[j]+=k,e[k]+=j;
	for(scanf("%d",&q),dfs(1,0);printf("%lld\n",ans),q--;){
		scanf("%d%d",&i,&j),i=gf(i),j=gf(j);
		for(;i!=j;mg(i,gf(fa[i])))if(d[i]<d[j])swap(i,j);
	}
	return 0;
}