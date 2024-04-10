#include<bits/stdc++.h>
using namespace std;
enum{N=1009,M=4099,S=N-1,T=N-2};
using ll=long long;
struct E{
	int u,v;
}e[N];
int n,te,a[N],w[N],ans[N];
bool vis[N];
namespace F{
int he[N],to[M],ne[M],cur[M],t,q[N],d[N];
ll len[M];
void clr(){memset(he,0,N*4),t=1;}
void add(int x,int y,ll z){ne[++t]=he[x],to[t]=y,len[t]=z,he[x]=t,ne[++t]=he[y],to[t]=x,len[t]=0,he[y]=t;}
bool bfs(){
	int i,j,k,h=0,t=1;
	memset(d,0,N*4),d[S]=1,q[1]=S;
	while(h<t)for(i=q[++h],j=he[i];j;j=ne[j])if(len[j]&&!d[k=to[j]])if(d[k]=d[i]+1,q[++t]=k,k==T)return 1;
	return 0;
}
ll dfs(int x,ll y){
	if(x==T)return y;
	int&i=cur[x],j;
	ll u=0,w;
	for(;i;i=ne[i])if(len[i]&&d[j=to[i]]>d[x])if(w=dfs(j,min(y-u,len[i])),u+=w,len[i^1]+=w,len[i]-=w,u==y)break;
	return u;
}
void dinic(){while(bfs())memcpy(cur,he,N*4),dfs(S,1e18);}
void find(int x){
	if(vis[x])return;
	vis[x]=1;
	for(int i=he[x];i;i=ne[i])if(len[i])find(to[i]);
}
}
void wk(int l,int r,const basic_string<int>&b){
	if(l==r){for(int i:b)ans[i]=w[l];return;}
	int m=(l+r)>>1,i;
	F::clr();
	for(i=1;i<=te;++i)F::add(e[i].u,e[i].v,1e18);
	for(int o:b)if(i=abs(a[o]-w[m])-abs(a[o]-w[m+1]),i>0)F::add(S,o,i);else F::add(o,T,-i);
	F::dinic();
	basic_string<int>u,v;
	memset(vis,0,N),F::find(S);
	for(int o:b)if(vis[o])v+=o;else u+=o;
	wk(l,m,u),wk(m+1,r,v);
}
int main(){ios::sync_with_stdio(0);cin.tie(0);
	int i;
	basic_string<int>b;
	cin>>n>>te;
	for(i=1;i<=n;++i)cin>>a[i],b+=i,w[i]=a[i];
	for(i=1;i<=te;++i)cin>>e[i].u>>e[i].v;
	sort(w+1,w+n+1),i=unique(w+1,w+n+1)-w-1,wk(1,i,b);
	for(i=1;i<=n;++i)cout<<ans[i]<<' ';
}