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
	il void ckMax(I& p,I q){p=(p>q?p:q);}
	template <class I> 
	il void ckMin(I& p,I q){p=(p<q?p:q);}
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
int a[N],b[N],n,Q;
il bool ck(ct mid){
	it cn=std::upper_bound(a+1,a+1+n,mid)-a-1;
	for(it i=1;i<=Q;++i){
		if(b[i]>0&&b[i]<=mid) ++cn;
		if(b[i]<0&&(-b[i])<=cn) --cn;
	}
	return cn;
}
int main(){
	scanf("%d%d",&n,&Q);it i,x,num=0;
	for(i=1;i<=n;++i) scanf("%d",&a[i]);
	for(i=1;i<=Q;++i) scanf("%d",&b[i]);
	it l=1,r=n,mid,ans=0;
	while(l<=r) mid=l+r>>1,ck(mid)?r=mid-1,ans=mid:l=mid+1;
	ck(ans)?printf("%d",ans):putchar('0');
	return 0;
}