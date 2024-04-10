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
#define P 998244353
const int N=1000005;
int n,ans,fac[N],ifac[N],inv[N];
ll K;
il int ksm(it x,it L){it ans=1;while(L) L&1?ans=(0ll+ans)*x%P:0,x=(0ll+x)*x%P,L>>=1;return ans;}
il int C(ct n,ct m){return m<0||n<m?0:(0ll+fac[n])*ifac[m]%P*ifac[n-m]%P;}
int main(){ 
	scanf("%d%lld",&n,&K);if(K>=n) return putchar('0'),0;
	K=n-K;it i;
	for(i=2,fac[0]=fac[1]=ifac[0]=ifac[1]=inv[0]=inv[1]=1;i<=n;++i) fac[i]=(0ll+fac[i-1])*i%P,inv[i]=(0ll+inv[P%i])*(P-P/i)%P,ifac[i]=(0ll+ifac[i-1])*inv[i]%P;
	for(i=0;i<=K;++i) ans=(ans+(0ll+ksm(K-i,n))*(i&1?P-C(K,i):C(K,i)))%P;
	printf("%d",(K<n?2ll:1ll)*(0ll+ans)*C(n,K)%P);
	return 0;
}