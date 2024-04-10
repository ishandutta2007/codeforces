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
int h[N],nxt[N],adj[N],n,m,k,u,v,s[N],d[N],t,ans[N],top;
bool vs[N];
il void dfs(ct x){
	s[++top]=x,d[x]=top;
	for(it i=h[x],j;i;i=nxt[i]){
		if(!d[j=adj[i]]) dfs(j);
		else if(d[x]-d[j]+1<=k&&(d[x]-d[j]+1)>2){
			printf("2\n%d\n",d[x]-d[j]+1);
			for(it w=d[j];w<=d[x];++w) printf("%d ",s[w]);
			exit(0);
		}
	}
	if(!vs[x]){
		vs[x]=1,ans[++*ans]=x;
		for(it i=h[x];i;i=nxt[i]) vs[adj[i]]=1;
	}
	--top;
}
il void add(){nxt[++t]=h[u],h[u]=t,adj[t]=v,nxt[++t]=h[v],h[v]=t,adj[t]=u;}
int main(){ 
	scanf("%d%d%d",&n,&m,&k);it i;
	for(i=1;i<=m;++i) scanf("%d%d",&u,&v),add();
	dfs(1);
	if(ans[0]>=(k+1>>1)){
		puts("1"),k=k+1>>1;
		for(i=1;i<=k;++i) printf("%d ",ans[i]);
		return 0;
	}
	
	return 0;
}