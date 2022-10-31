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
const int N=2100005;
int h[N],nxt[N],adj[N],d[N],a[N],b[N],o[N],n,nn,t;
bool vs[N];
il void dfs(ct x){
	for(it &i=h[x],j;j=i;i=nxt[i])
		if(!vs[i+1>>1]) vs[i+1>>1]=1,dfs(adj[i]),o[++*o]=j+(j&1?1:-1),o[++*o]=j;
}
il bool ck(ct x){
	for(it i=0;i<=x;++i) d[i]=h[i]=0;
	for(it i=0;i<=n;++i) vs[i]=0;o[0]=t=0;
	auto add = [&] (ct u,ct v){nxt[++t]=h[u],h[u]=t,adj[t]=v,nxt[++t]=h[v],h[v]=t,adj[t]=u;};
	for(it i=1;i<=n;++i) d[a[i]&=x]^=1,d[b[i]&=x]^=1,add(a[i],b[i]);
	for(it i=0;i<=x;++i) if(d[i]) return 0;
	return dfs(a[1]),o[0]==nn;
}
int main(){ 
	scanf("%d",&n);it i;nn=n<<1;
	for(i=1;i<=n;++i) scanf("%d%d",&a[i],&b[i]);
	for(i=20;~i;--i)
		if(ck((1<<i)-1)){
			printf("%d\n",i);
			for(it j=1;j<=*o;++j) printf("%d ",o[j]);
			return 0;
		}
	return 0;
}