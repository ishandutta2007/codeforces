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
int n,m,a[N],T,u,v,k,cn,x;
struct ky{
	int l,r;
}b[N],c[N];
#define rky register ky
il ky mer(rky a,rky b){
	if(a.r>b.r) sp(a,b);
	if(a.r>=b.l) return (ky){Min(a.l,b.l),Max(a.r,b.r)};
	return (ky){-1,-1};
}
il void mer(){
	it i,fl=0;rky now=(ky){u,v},o;
	for(i=1;i<=cn;++i){
		o=mer(b[i],now);//printf("%d %d %d %d %d %d\n",b[i].l,b[i].r,now.l,now.r,o.l,o.r);
		if(o.l!=-1) 
			b[i]=(ky){-1,-1},now=o,fl=1;
	}
	if(fl){
		it tcn=0;b[++cn]=now;
		for(i=1;i<=cn;++i) if(b[i].l!=-1) c[++tcn]=b[i];
		cn=tcn;
		for(i=1;i<=cn;++i) b[i]=c[i];
		return;
	}
	if(x>=u&&x<=v) b[++cn]=now;
}
int main(){ 
	scanf("%d",&T);
	while(T--){
		scanf("%d%d%d",&n,&x,&m),cn=0;rll ans=0;
		while(m--) scanf("%d%d",&u,&v),mer();
		for(it i=1;i<=cn;++i) ans+=b[i].r-b[i].l+1;//printf("%d %d\n",b[i].l,b[i].r);
		printf("%lld\n",ans+(cn==0));
	}
	return 0;
}