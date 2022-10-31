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
const int N=2000005,P=1e9+7;
int n,m,T;
vector<int> g[N];
ll e[N],p[N],sz[N];
il void dfs(ct x,ct fa){
	sz[x]=1;
	for(const int &j : g[x]) if(j^fa) dfs(j,x),sz[x]+=sz[j];
	//printf("x=%d sz[x]=%d\n",x,sz[x]);
	e[x]=sz[x]*(n-sz[x]);
}
int main(){
	//freopen("a.in","r",stdin);
	//freopen("a.out","w",stdout);
	scanf("%d",&T);it i,u,v;
	while(T--){
		scanf("%d",&n);rll ans=0;
		for(i=1;i<=n;++i) g[i].clear(),sz[i]=e[i]=0;
		for(i=1;i<n;++i) scanf("%d%d",&u,&v),g[u].push_back(v),g[v].push_back(u);
		dfs(1,0),scanf("%d",&m);
		for(i=1;i<=m;++i) scanf("%lld",&p[i]);p[++m]=1;
		while(m<n) p[++m]=1;
		std::sort(p+1,p+1+m),std::sort(e+1,e+1+n);
		while(m>n) p[m-1]=p[m-1]*p[m]%P,--m;
		//for(i=1;i<=n;++i) printf("%d ",e[i]);puts("");
		for(i=2;i<=n;++i) ans=(ans+e[i]*p[i])%P;
		printf("%lld\n",ans);
	}
	return 0;
}