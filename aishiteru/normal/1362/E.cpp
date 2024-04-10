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
	il void ckMax(I& p,I q){p=(p>q?p:q);}
	template <class I> 
	il void ckMin(I& p,I q){p=(p<q?p:q);}
};
using io :: fr;
using io :: nc;
using io :: Max;
using io :: Min;
using io :: A;
using io :: sp;
using io :: ckMax;
using io :: ckMin;
const int N=1000005,inf=1e9;
#define P 1000000007
#define ckP 19260817
int a[N],b[N],n,p,T;
il int ksm(it x,it L,ct p){it ans=1;while(L) L&1?ans=(0ll+ans)*x%p:0,x=(0ll+x)*x%p,L>>=1;return ans;}
il void mo(int &x,ct q,ct p){x+=q,x=(x<0?x+p:(x>=p?x-p:x));}
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&p),b[0]=0;it ans=0,ck=0,i;
		for(i=1;i<=n;++i) scanf("%d",&a[i]); 
		if(p==1){printf("%d\n",n&1);continue;}
		std::sort(a+1,a+1+n);
		for(i=n;i;--i)
			if((!ans)&&(!ck)) mo(ans,ksm(p,a[i],P),P),mo(ck,ksm(p,a[i],ckP),ckP);
			else mo(ans,-ksm(p,a[i],P),P),mo(ck,-ksm(p,a[i],ckP),ckP);
		printf("%d\n",ans);
	}
	return 0;
}