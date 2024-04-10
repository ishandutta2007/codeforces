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
int n,a[N],b[N],T;
vector<pi> v1,v2;
int main(){ 
	scanf("%d",&T);it i;
	while(T--){
		scanf("%d",&n);ct nn=n>>1;
		for(i=1;i<=n;++i) scanf("%d",&a[i]);
		for(i=1;i<=n;++i) scanf("%d",&b[i]);
		if((n&1)&&a[nn+1]!=b[nn+1]){puts("No");continue;}
		v1.clear(),v2.clear();
		for(i=1;i<=nn;++i) v1.push_back(mkp(Min(a[i],a[n-i+1]),Max(a[i],a[n-i+1])));
		for(i=1;i<=nn;++i) v2.push_back(mkp(Min(b[i],b[n-i+1]),Max(b[i],b[n-i+1])));
		std::sort(v1.begin(),v1.end()),std::sort(v2.begin(),v2.end());
		v1==v2?puts("Yes"):puts("No");
	}
	return 0;
}