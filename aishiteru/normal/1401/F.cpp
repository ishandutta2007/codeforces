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
ll tr[N],a[N];
int tag,n,Q,lim;
il void add(it x,ct num){++x;while(x<N) tr[x]+=num,x+=(x&-x);}
il ll que(it x){rll num=0;++x;while(x) num+=tr[x],x-=(x&-x);return num;}
il ll q(ct x){
	rll ans=a[x^tag];it now=0;
	for(it i=17;~i;--i)
		if(x>>i&1) ans+=que((now^tag)|((1<<i)-1))-que(((now^tag)&(0x7fffffff^((1<<i)-1)))-1),now|=1<<i;
	return ans;
}
int main(){ 
	fr(n),fr(Q),lim=1<<n;it u,v,op;
	for(it i=0;i<lim;++i) fr(a[i]),add(i,a[i]);
	while(Q--){
		fr(op),fr(u);
		if(op==1||op==4) fr(v);
		if(op==1) --u,add(u^tag,-a[u^tag]),a[u^tag]=v,add(u^tag,v);
		if(op==2) tag^=(1<<u)-1;
		if(op==3) tag^=(1<<u);
		if(op==4) printf("%lld\n",q(v-1)-(u-1?q(u-2):0));
	}
	return 0;
}