#include<stdio.h> 
#include<algorithm>
#define it register int
#define ct const int
#define il inline
using namespace std;
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
};
using io :: fr;
using io :: nc;
using io :: Max;
using io :: Min;
using io :: A;
using io :: sp;
const int N=1000005;
int T,n,m,h[N],nxt[N],adj[N],t,u,v,fl,fa[N],sz[N];
long long good[N],bad[N],a[N],p[N];
il void add(){nxt[++t]=h[u],h[u]=t,adj[t]=v,nxt[++t]=h[v],h[v]=t,adj[t]=u;}
il void dfs(ct x){
	if(!fl) return;
	sz[x]=1;
	for(it i=h[x];i;i=nxt[i]) if(adj[i]^fa[x]) fa[adj[i]]=x,dfs(adj[i]),sz[x]+=sz[adj[i]],p[x]+=p[adj[i]];
	if(p[x]+a[x]&1) return fl=0,void();
	good[x]=p[x]+a[x]>>1,bad[x]=p[x]-good[x];
	if(good[x]>p[x]||bad[x]>p[x]) return fl=0,void();
	register long long s=0;
	for(it i=h[x];i;i=nxt[i]) s+=good[adj[i]];
	if(good[x]<s) return fl=0,void();
}
int main(){ 
	fr(T);
	while(T--){
		fr(n),fr(m);it i;
		for(i=1;i<=n;++i) h[i]=sz[i]=p[i]=a[i]=good[i]=bad[i]=0;t=0;fl=1;
		for(i=1;i<=n;++i) fr(p[i]);
		for(i=1;i<=n;++i) fr(a[i]);
		for(i=1;i<n;++i) fr(u),fr(v),add();
		dfs(1),fl?puts("YES"):puts("NO");
	}
	return 0;
}