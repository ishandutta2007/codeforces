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
int T,n,a[N],x,b1[N],b2[N],mn[N*10],pr[N],cnt;
bool isp[10000002];
il void Pre(){
	for(it i=2,j;i<=10000000;++i){
		if(!isp[i]) isp[i]=1,pr[++cnt]=i,mn[i]=i;
		for(j=1;(x=i*pr[j])<=10000000;++j){
			isp[x]=1,mn[x]=Min(mn[i],pr[j]);
			if(!(i%pr[j])) break;
		}
	}
}
int main(){ 
	scanf("%d",&n);it i;Pre();
	for(i=1;i<=n;++i){
		scanf("%d",&a[i]),b1[i]=-1,b2[i]=-1;
		if(!(a[i]&1)){
			while(!(a[i]&1)) a[i]>>=1;
			if(a[i]>1) b1[i]=2,b2[i]=a[i];
			continue;
		}
		b1[i]=mn[a[i]];
		while(!(a[i]%b1[i])) a[i]/=b1[i];
		if(a[i]>1) b2[i]=a[i];
		else b1[i]=b2[i]=-1;
	}
	for(i=1;i<=n;++i) printf("%d ",b1[i]);puts("");
	for(i=1;i<=n;++i) printf("%d ",b2[i]);
	return 0;
}