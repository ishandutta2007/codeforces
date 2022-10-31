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
int T,n,ans,pos;
ll x,y,a[N],maxn;
il void ck(ct w){
	rll k;
	for(it i=1,j;i<=n;++i){
		it fl=0;
		for(j=i,k=x;j;--j) a[j]=k,k-=w,fl|=(a[j]==y);
		for(j=i,k=x;j<=n;++j) a[j]=k,k+=w,fl|=(a[j]==y);
		if(fl&&a[1]>0&&a[n]<maxn) maxn=a[n],ans=w,pos=i;//printf("%lld %lld %lld %d %d\n",a[1],a[n],maxn,ans,pos);
	}
}
int main(){ 
	scanf("%d",&T);
	while(T--){
		scanf("%d%lld%lld",&n,&x,&y);it k;ans=1e9;ct lim=y-x;maxn=1e18;
		for(k=1;k*k<=lim;++k)
			if(!(lim%k)) ck(k),ck(lim/k);
		rll tmp;
		for(it i=pos,tmp=x;i;--i) a[i]=tmp,tmp-=ans;
		for(it i=pos,tmp=x;i<=n;++i) a[i]=tmp,tmp+=ans;
		for(it i=1;i<=n;++i) printf("%lld ",a[i]);puts("");
	}
	return 0;
}