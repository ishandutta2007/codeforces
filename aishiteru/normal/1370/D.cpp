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
int T,n,a[N],b[N],k,kk;
vector<int> vec;
il bool ck(ct x){
	it fl=0,cn1=0,cn2=0,i;
	for(i=1;i<=n;++i){
		if(!fl) fl^=1,++cn1;
		else if(a[i]<=x) ++cn2,fl^=1;
	}
	if(cn1+cn2>=k&&(cn1>=kk&&cn2>=kk)) return 1;
	fl=1,cn1=0,cn2=0;
	for(i=1;i<=n;++i){
		if(!fl) fl^=1,++cn1;
		else if(a[i]<=x) ++cn2,fl^=1;
	}
	return (cn1+cn2>=k&&(cn1>=kk&&cn2>=kk));
}
il void ms(){
	it l=1,r=*b,mid,ans=0;
	while(l<=r) mid=l+r>>1,ck(b[mid])?ans=b[mid],r=mid-1:l=mid+1;
		//printf("l=%d r=%d mid=%d b[mid]=%d now=%d\n",l,r,mid,b[mid],ck(b[mid]));
	printf("%d\n",ans);
}
int main(){ 
	scanf("%d%d",&n,&k);
	for(it i=1;i<=n;++i) scanf("%d",&a[i]),b[i]=a[i];kk=k>>1;
	std::sort(b+1,b+1+n),*b=std::unique(b+1,b+1+n)-b-1;
	ms();  
	return 0;
}