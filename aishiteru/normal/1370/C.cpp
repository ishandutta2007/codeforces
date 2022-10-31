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
int T,n;
namespace PR{
	const int p[]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59};
	il int ksm(it a,it b,ct p){it now=1;while(b) b&1?now=(0ll+now)*a%p:0,a=(0ll+a)*a%p,b>>=1;return now;}
	bool isp(ct num){
		for(it i=0;i<14;++i) if(!(num%p[i])) return num==p[i];
		it pw=0,r=num-1;
		while(!(r&1)) ++pw,r>>=1;
		for(it i=0;i<14;++i){
			it y,x=ksm(p[i],r,num);
			for(it j=1;j<=pw&&x>1;++j){
				y=(0ll+x)*x%num;
				if(y==1&&x!=num-1) return 0;
				x=y;
			}
			if(x!=1) return 0;
		}
		return 1;
	} 
}
using PR::isp;
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		if(n==1){puts("FastestFinger");continue;}
		if(n==2){puts("Ashishgup");continue;}
		if(n&1){puts("Ashishgup");continue;}
		it o=1;while(!(n&1)) n>>=1,o<<=1;
		if(n==1){puts("FastestFinger");continue;}
		if(o==2&&isp(n)){puts("FastestFinger");continue;}
		puts("Ashishgup");
	} 
	return 0;
}