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
const int N=205,inf=1e9;
int a[N],b[N],c[N],R,G,B;
ll ans,f[N][N][N];
il bool cmp(ct p,ct q){return p>q;}
int main(){ 
	scanf("%d%d%d",&R,&G,&B);it i,j,k;
	for(i=1;i<=R;++i) scanf("%d",&a[i]);std::sort(a+1,a+1+R,cmp);
	for(i=1;i<=G;++i) scanf("%d",&b[i]);std::sort(b+1,b+1+G,cmp);
	for(i=1;i<=B;++i) scanf("%d",&c[i]);std::sort(c+1,c+1+B,cmp);
	++R,++G,++B;
	for(i=1;i<=R;++i)
		for(j=1;j<=G;++j)
			for(k=1;k<=B;++k)
				ckMax(ans,f[i][j][k]),
				ckMax(f[i+1][j+1][k],f[i][j][k]+a[i]*b[j]),
				ckMax(f[i+1][j][k+1],f[i][j][k]+a[i]*c[k]),
				ckMax(f[i][j+1][k+1],f[i][j][k]+c[k]*b[j]),
				ckMax(f[i+1][j][k],f[i][j][k]),ckMax(f[i][j+1][k],f[i][j][k]),ckMax(f[i][j][k+1],f[i][j][k]);
	printf("%lld",ans);
	return 0;
}