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
int n,p,a[N],c[N],f[N],ans[N],mx;
il int mo(ct x){return x>=p?x-p:x;}
int main(){
	scanf("%d%d",&n,&p);it i;ct nn=n<<1;
	for(i=1;i<=n;++i) scanf("%d",&a[i]),mx=(a[i]>mx?a[i]:mx);mx-=n;
	for(i=1;i<=n;++i) ++c[Max(0,a[i]-mx)];
	for(i=1;i<nn;++i) c[i]+=c[i-1];
	for(i=1;i<=n;++i) ++f[mo((i+mx-c[i])%p+p)];
	for(i=1;i<n;++i) !f[mo((i+mx)%p+p)]?ans[++*ans]=i+mx:0,--f[mo((i+mx-c[i])%p+p)],++f[mo((n+i+mx-c[n+i])%p+p)];
	for(i=1,printf("%d\n",*ans);i<=*ans;++i) printf("%d ",ans[i]);
	return 0;
}