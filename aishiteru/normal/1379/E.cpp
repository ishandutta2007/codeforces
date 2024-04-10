#include<stdio.h>
#include<algorithm>
#define it register int
#define ct const int
#define il inline
using namespace std;
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
};
using io :: fr;
const int N=1000005;
int n,k,f[N];
il bool chk(ct x){return (x&(x+1))!=0;}
il bool ck(ct n,ct k){
	if(!k&&n==1) return 1;
	if(!(n&1)) return 0;
	if(k>(n-3>>1)) return 0;
	if(n==9&&k==2) return 0;
	return chk(n)?(k!=0):(k!=1);
}
il int Max(ct p,ct q){return p>q?p:q;}
il int Min(ct p,ct q){return p<q?p:q;}
il void solve(ct l,ct r,ct k){
	if(l==r) return;
	if(!k){
		for(it i=l+1,cnum=l,fl=0;i<=r;cnum+=fl,fl^=1,++i) f[i]=cnum;
		return;
	}
	ct n=r-l;
	for(it i=1,x;i<n;++i){
		x=chk(i)+(Max(i,n-i)>=2*Min(i,n-i));
		if(k>=x&&ck(n-i,k-x))
			return f[l+1]=l,solve(l+1,l+i,chk(i)),f[l+i+1]=l,solve(l+i+1,r,k-x);
	}
}
int main(){ 
	scanf("%d%d",&n,&k);
	if(!ck(n,k)) return puts("NO"),0;
	solve(1,n,k),puts("YES");
	for(it i=1;i<=n;++i) printf("%d ",f[i]);
	return 0;
}