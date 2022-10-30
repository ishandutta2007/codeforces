#include<stdio.h>
#define it register int
#define ct const int
#define il inline
const int N=1000005;
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
};
using io :: fr;
using io :: nc;
using io :: Max;
using io :: Min;
using io :: A;
using io :: sp;
int T,n;
long long a[N],cn[N],sum,cnum;
il void gc(it&op){
	register char c=nc();
	while(c!='+'&&c!='-') c=nc();
	op=(c=='+');
}
int main(){ 
	fr(n);it op,x;
	for(it i=1;i<=n;++i) fr(x),++a[x];
	for(it i=1;i<=100000;++i) sum+=(a[i]>>1),cnum+=(a[i]>=4);
	fr(T);
	while(T--){
		gc(op),fr(x),sum-=(a[x]>>1),cnum-=(a[x]>=4),op?++a[x]:--a[x],sum+=(a[x]>>1),cnum+=(a[x]>=4);
		if(cnum<1){puts("NO");continue;}
		sum>=4?puts("YES"):puts("NO");
	} 
	return 0;
}