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
int a[N],b[N],pw[60],n;
ll ans[N];
int main(){ 
	scanf("%d",&n);it i,j;rll x;
	pw[0]=1;for(i=1;i<=20;++i) pw[i]=pw[i-1]<<1;
	for(i=0;i<pw[13];++i) if(__builtin_popcount(i)==6) a[++a[0]]=i;
	for(i=0;i<13;++i){
		for(b[0]=0,j=1;j<=n;++j) 
			if(a[j]&pw[i]) b[++b[0]]=j;
		if(b[0]){
			cout<<'?'<<' '<<b[0];
			for(j=1;j<=b[0];++j) cout<<' '<<b[j];
			cout<<endl,cout<<flush,cin>>x;
			for(j=1;j<=n;++j) if(!(a[j]&pw[i])) ans[j]|=x;
		}
	}
	cout<<'!';for(i=1;i<=n;++i) cout<<' '<<ans[i];
	return 0;
}