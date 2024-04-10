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
int n,add,rdc,mov,a[N];
ll ans;
il ll ck(ct mid){
	rll Add=0,Rdc=0;
	for(it i=1;i<=n;++i) Add+=Max(0,mid-a[i]),Rdc+=Max(0,a[i]-mid);
	return Min(Add*add+Rdc*rdc,Min(Add,Rdc)*mov+(Add-Min(Add,Rdc))*add+(Rdc-Min(Add,Rdc))*rdc);
}
il void ms(){
	it l=0,r=1e9,m1,m2,mid;ans=1e18;
	while(r-l>3) mid=(r-l)/3,m1=l+mid,m2=r-mid,ck(m1)>ck(m2)?l=m1:r=m2;
	ans=ck(l),++l;while(l<=r) ans=Min(ans,ck(l)),++l;
	printf("%lld",ans);
}
int main(){
	scanf("%d%d%d%d",&n,&add,&rdc,&mov);
	for(it i=1;i<=n;++i) scanf("%d",&a[i]);
	ms();
	return 0;
}