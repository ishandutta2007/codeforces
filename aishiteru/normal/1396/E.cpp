#include<bits/stdc++.h>
#define it register int
#define ct const int
#define il inline
using namespace std;
typedef long long ll;
#define rll register ll
#define cll const ll
typedef double db;
#define rdb register db
#define cdb const db
typedef long double ldb;
typedef unsigned long long ull;
#define pb push_back
#define mkp make_pair
#define pl pair<ll,int> 
#define pi pair<int,int>
#define fir first
#define sec second
namespace io{
	il char nc(){
		static char buf[100000],*p1=buf,*p2=buf;
		return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++; 
	}
	template <class I> 
	il void fr(I &num){
		num=0;register char c=nc();it p=1;
		while(c<'0'||c>'9') c=='-'?p=-1,c=nc():c=nc();
		while(c>='0'&&c<='9') num=num*10+c-'0',c=nc();
		num*=p;
	} 
	template <class I> 
	il I Max(I p,I q){return p>q?p:q;}
	template <class I> 
	il I Min(I p,I q){return p<q?p:q;}
	template <class I> 
	il I A(I x){return x<0?-x:x;}
	template <class I> 
	il void sp(I&p,I&q){I x=p;p=q,q=x;}
	template <class I>
	il void ckMax(I&p,I q){p=(p>q?p:q);}
	template <class I>
	il void ckMin(I&p,I q){p=(p<q?p:q);}
};
using io :: fr;
using io :: nc;
using io :: Max;
using io :: Min;
using io :: A;
using io :: sp;
using io :: ckMax;
using io :: ckMin; 
const int N=1000005;
int n,rt,h[N],nxt[N],adj[N],sz[N],mx[N],u,v,t,fa[N],id[N],cn[N];
ll K,lk,rk;
vector<int> g[N];
il void add(){nxt[++t]=h[u],h[u]=t,adj[t]=v,nxt[++t]=h[v],h[v]=t,adj[t]=u;} 
il void DFS(ct x,ct fa){
	sz[x]=1;
	for(it i=h[x],j;i;i=nxt[i])
		if((j=adj[i])^fa)
			DFS(j,x),sz[x]+=sz[j],ckMax(mx[x],sz[j]),lk+=sz[j]&1,rk+=Min(sz[j],n-sz[j]); 
	ckMax(mx[x],n-sz[x]);
	if(mx[x]<=mx[rt]) rt=x;	 
}
il void dfs(ct x){
	sz[x]=1;
	for(it i=h[x],j;i;i=nxt[i])
		if((j=adj[i])^fa[x])
			fa[j]=x,dfs(j),sz[x]+=sz[j];
	++cn[sz[x]];
}
il void Dfs(ct x){
	id[x]=x,g[x].push_back(x);it tot=1;
	for(it i=h[x],j;i;i=nxt[i]) if((j=adj[i])^fa[x]) Dfs(j),tot+=g[id[j]].size();
	priority_queue<pi> q;
	q.push(mkp(1,x));
	for(it i=h[x],j;i;i=nxt[i])
		if(((j=adj[i])^fa[x])&&g[id[j]].size()) q.push(mkp(g[id[j]].size(),id[j]));
	while(tot>sz[x]){
		auto u=q.top();q.pop();
		auto v=q.top();q.pop();
		printf("%d %d\n",g[u.sec].back(),g[v.sec].back()),g[u.sec].pop_back(),g[v.sec].pop_back();
		tot-=2,--u.fir,--v.fir,u.fir?q.push(u),0:0,v.fir?q.push(v),0:0;
	} 
	for(it i=h[x],j;i;i=nxt[i])
		if(((j=adj[i])^fa[x])&&g[id[j]].size()){
			if(g[id[j]].size()>g[id[x]].size()) sp(id[j],id[x]);
			for(const int &p : g[id[j]]) g[id[x]].push_back(p);
			g[id[j]].clear();
		}
}
int main(){
	scanf("%d%lld",&n,&K);it i,pos=1;
	for(i=1;i<n;++i) scanf("%d%d",&u,&v),add();
	mx[0]=n+1,DFS(1,0);
	if(K<lk||K>rk||(K&1)!=(rk&1)) return puts("NO"),0;
	dfs(rt);
	for(i=n-1;i>1;--i){
		if(rk-K<(cn[i]<<1)){pos=i;break;}
		rk-=(cn[i]<<1),cn[i-2]+=cn[i];
	}
	for(i=1;i<=n;++i) sz[i]=Min(sz[i],pos-(pos+sz[i]&1));sz[rt]=0;
	for(i=1;i<=n;++i) if(sz[i]==pos&&rk>K) sz[i]-=2,rk-=2;
	puts("YES"),Dfs(rt);
	return 0;
}