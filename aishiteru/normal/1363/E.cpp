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
int T,n,a[N],b[N];
vector<int> g[N];
ll ans;
il void dfs(ct x,ct fa){
	a[x]=Min(a[x],a[fa]);it tot=A(b[x]);
	for(const int&i : g[x])
		if(i^fa) dfs(i,x),b[x]+=b[i],tot+=A(b[i]);
	ans+=(0ll+a[x])*A(tot-A(b[x]));
//	printf("%d %d %d\n",a[x],tot,b[x]);
}
int main(){
	scanf("%d",&n);it i,u,v,sum=0;
	for(i=1;i<=n;++i) scanf("%d%d%d",&a[i],&u,&v),b[i]=u-v,sum+=b[i];
	if(sum) return puts("-1"),0;
	for(i=1;i<n;++i) scanf("%d%d",&u,&v),g[u].push_back(v),g[v].push_back(u);
	a[0]=2e9,dfs(1,0),printf("%lld",ans);
	return 0;
}