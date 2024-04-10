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
const int N=4000005;
int n,a[N],x;
ll b[N],mn[N],tag[N];
il void B(ct rt,ct l,ct r){
	if(l==r) return mn[rt]=b[l],void();
	ct mid=l+r>>1,ls=rt<<1,rs=ls|1;
	B(ls,l,mid),B(rs,mid+1,r),mn[rt]=Min(mn[ls],mn[rs]);
}
il void pd(ct rt){
	ct ls=rt<<1,rs=ls|1;
	mn[ls]+=tag[rt],mn[rs]+=tag[rt],tag[ls]+=tag[rt],tag[rs]+=tag[rt],tag[rt]=0;
}
il void upd(ct rt,ct l,ct r ,ct u,ct v,ct x){
	if(l>=u&&r<=v) return mn[rt]+=x,tag[rt]+=x,void();
	ct mid=l+r>>1,ls=rt<<1,rs=ls|1;
	if(tag[rt]) pd(rt);
	if(u<=mid) upd(ls,l,mid,u,v,x);
	if(v>mid) upd(rs,mid+1,r,u,v,x);
	mn[rt]=Min(mn[ls],mn[rs]);
}
il ll que(ct rt,ct l,ct r,ct u,ct v){
	if(l>=u&&r<=v) return mn[rt];
	ct mid=l+r>>1,ls=rt<<1,rs=ls|1;
	if(tag[rt]) pd(rt);mn[rt]=Min(mn[ls],mn[rs]);
	if(v<=mid) return que(ls,l,mid,u,v);
	if(u>mid) return que(rs,mid+1,r,u,v);
	return Min(que(ls,l,mid,u,mid),que(rs,mid+1,r,mid+1,v));
}
int main(){
	scanf("%d",&n);it i;ct nn=n+1>>1;
	for(i=1;i<=nn;++i) scanf("%d",&a[i]);
	scanf("%d",&x);for(i=nn+1;i<=n;++i) a[i]=x;
	it k=n/2+1;ct nk=n-k+1;
	for(i=1;i<=k;++i) b[1]+=a[i];
	for(i=2;i<=nk;++i) b[i]=x-a[i-1];
	for(i=1;i<=nk;++i) b[i]+=b[i-1];
	B(1,1,nk);
	while(k<=n){
		if(que(1,1,nk,1,n-k+1)>0) return printf("%d ",k),0;
		++k,upd(1,1,nk,1,nk,x);
	}
	puts("-1");
	return 0;
}