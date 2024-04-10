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
const int N=1050005,M=300005;
#define P 998244353
int n,m,l[N],r[N],fac[N],ifac[N],inv[N],c[N],sum[M][42],a[N],b[N],ans;
bool vs[N];
il int Max(ct p,ct q){return p>q?p:q;}
il int Min(ct p,ct q){return p<q?p:q;}
il int C(ct n,ct m){return n<m||m<0?0:(0ll+fac[n])*ifac[m]%P*ifac[n-m]%P;}
int main(){
	scanf("%d%d",&n,&m);it i,j,s,L,R,tot;ct lim=1<<m;
	for(i=1;i<=n;++i) scanf("%d%d",&l[i],&r[i]),++c[l[i]],--c[r[i]+1];
	for(i=0;i<m;++i) scanf("%d%d",&a[i],&b[i]);
	for(i=2,fac[0]=fac[1]=inv[0]=inv[1]=ifac[0]=ifac[1]=1;i<=n;++i) fac[i]=(0ll+fac[i-1])*i%P,inv[i]=(0ll+inv[P%i])*(P-P/i)%P,ifac[i]=(0ll+ifac[i-1])*inv[i]%P;
	for(i=1;i<=n;++i) c[i]+=c[i-1];
	for(i=1;i<=n;++i)
		for(j=0;j<=40;++j)
			sum[i][j]=sum[i-1][j]+C(c[i]-j,i-j),sum[i][j]=(sum[i][j]>=P?sum[i][j]-P:sum[i][j]);
	for(s=0;s<lim;++s){
		L=1,R=n,tot=0;
		for(i=0;i<m;++i) s&(1<<i)?!vs[a[i]]?++tot,vs[a[i]]=1:0,!vs[b[i]]?++tot,vs[b[i]]=1:0,L=Max(L,Max(l[a[i]],l[b[i]])),R=Min(R,Min(r[a[i]],r[b[i]])):0;
		for(i=0;i<m;++i) s&(1<<i)?vs[a[i]]=vs[b[i]]=0:0;
		if(L<=R) ans+=__builtin_popcount(s)&1?sum[L-1][tot]-sum[R][tot]:sum[R][tot]-sum[L-1][tot],ans=(ans<0?ans+P:(ans>=P?ans-P:ans));
	}
	printf("%d",ans);
	return 0;
}