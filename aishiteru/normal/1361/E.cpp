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
int T,n,o,h[N],nxt[N],adj[N],t,fl,vs[N],m,ans[N],d[N],tag[N],anc[N],c[N];
std::mt19937 rng(std::chrono::steady_clock::now().time_since_epoch().count());
il int rnd(ct l,ct r){return std::uniform_int_distribution<int>(l,r)(rng);}
il void DFS(ct x){
	if(!fl) return;
	vs[x]=1;
	for(it i=h[x],j;i;i=nxt[i])
		if(!vs[j=adj[i]]) DFS(j);
		else if(vs[j]==2) return fl=0,void();
	vs[x]=2;
}
il void fd_any(){//1/5  dfs
	for(it x=100,i;~x;--x){
		for(i=1;i<=n;++i) vs[i]=0;
		fl=1,i=rnd(1,n),DFS(i);
		if(fl) return o=i,void();
	}
}
il int dfs(ct x){// 
	anc[x]=x,vs[x]=1;
	for(it i=h[x],j;i;i=nxt[i])
		if(!vs[j=adj[i]]) d[j]=d[x]+1,c[x]+=dfs(j),d[anc[j]]<d[anc[x]]?anc[x]=anc[j]:0;
		else ++c[x],--c[j],d[j]<d[anc[x]]?anc[x]=j:0;
	if(c[x]>1) tag[x]=1;
	return c[x];
}
il void dfs_ck(ct x){//
	tag[x]|=tag[anc[x]],vs[x]=2;
	for(it i=h[x],j;i;i=nxt[i])
		if(vs[j=adj[i]]^2) dfs_ck(j);
	if(!tag[x]) ans[++*ans]=x;
}
int main(){ 
	scanf("%d",&T);it i;
	while(T--){
		scanf("%d%d",&n,&m),t=ans[0]=0;
		for(i=1;i<=n;++i) h[i]=c[i]=0;
		auto add = [&](ct u,ct v){nxt[++t]=h[u],h[u]=t,adj[t]=v;};
		for(it u,v;m;--m) scanf("%d%d",&u,&v),add(u,v);
		o=-1,fd_any();
		if(o<0){puts("-1");continue;}
		for(i=1;i<=n;++i) vs[i]=tag[i]=0;
		d[o]=0,dfs(o),dfs_ck(o);
		if(5*ans[0]<n){puts("-1");continue;}
		std::sort(ans+1,ans+1+ans[0]);
		for(i=1;i<=ans[0];++i) printf("%d ",ans[i]);puts("");
	}
	return 0;
}