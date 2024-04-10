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
std::mt19937 rnd(std::chrono::steady_clock::now().time_since_epoch().count());
const int N=100005;
int o,p[N],a[N],n;
il void que(ct x,ct y){cout<<'?'<<' '<<x<<' '<<y<<endl,cout<<flush,cin>>o;}
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n;
	for(it i=1;i<=n;++i) p[i]=i;
	std::shuffle(p+1,p+1+n,rnd);
	it T=2221,p0=p[1],i=0,x=(1<<30)-1;
	while(T){
		++i,i>n?std::shuffle(p+1,p+1+n,rnd),i=1:0;
		if(p[i]==p0) continue;
		--T,que(p[i],p0),x&=o;
		if(x==o) p0=p[i];
	}
	for(i=1,a[p0]=0;i<=n;++i) if(i^p0) que(i,p0),a[i]=o;
	cout<<'!';for(i=1;i<=n;++i) cout<<' '<<a[i];
	return 0;
}