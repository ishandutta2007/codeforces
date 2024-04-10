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
const int N=4000005;
#define P 998244353
int fac[N],ifac[N],inv[N],ans,n,m;
il int ksm(it x,it L){it ans=1;while(L) L&1?ans=(0ll+ans)*x%P:0,x=(0ll+x)*x%P,L>>=1;return ans;}
il int C(ct n,ct m){return n<m||m<0?0:(0ll+fac[n])*ifac[m]%P*ifac[n-m]%P;}
il void mo(it &p,ct q){p+=q,p=(p>=P?p-P:p);}
int main(){ 
	scanf("%d%d",&n,&m);it i,o=0,x;
	for(i=2,fac[0]=ifac[0]=inv[0]=fac[1]=ifac[1]=inv[1]=1;i<N;++i) fac[i]=(0ll+fac[i-1])*i%P,inv[i]=(0ll+inv[P%i])*(P-P/i)%P,ifac[i]=(0ll+ifac[i-1])*inv[i]%P;
	for(i=0;i<=n;++i) mo(o,C(n-i+m,m));
	o=(0ll+o)*ksm(C(n+m,m),P-2)%P;
	for(i=1;i<=n;++i) x=(0ll+o)*inv[i]%P*(m+i)%P*C(n,i)%P,i&1?mo(ans,x):mo(ans,P-x);
	printf("%d",ans);
	return 0;
}