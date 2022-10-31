#include<stdio.h>
#include<algorithm>
#define it register int
#define ct const int
#define il inline 
using namespace std;
typedef long long ll;
#define rll register ll
#define cll const ll
const int N=2000005;
const ll inf=4e18;
int n;
ll f[N][2],r1,r2,r3,d,a[N];
il ll Min(cll p,cll q){return p<q?p:q;}
il void ckMin(rll&p,cll q){p=(p<q?p:q);}
int main(){ 
	scanf("%d%lld%lld%lld%lld",&n,&r1,&r2,&r3,&d);it i;
	for(i=1;i<=n;++i) scanf("%lld",&a[i]),f[i][0]=f[i][1]=inf;
	f[1][0]=(0ll+r1)*a[1]+r3,f[1][1]=Min((0ll+r1)*a[1]+r1,r2);
	for(i=2;i<=n;++i)
		ckMin(f[i][0],Min(Min(f[i-1][0]+d+(0ll+r1)*a[i]+r3,f[i-1][1]+d+r2+(d<<1)+(r1<<1)),f[i-1][1]+d+(0ll+r1)*a[i]+Min(r3+(d<<1)+r1,r1+(d<<1)+(r1<<1)))),
		ckMin(f[i][1],d+Min(f[i-1][0]+Min((0ll+r1)*a[i]+r1,r2),f[i-1][1]+Min(r2+d+r1+d,(0ll+r1)*a[i]+(d<<1)+(r1<<1))));
	printf("%lld",Min(f[n][0],f[n-1][1]+d+(0ll+r1)*a[n]+r1+r3+d));
    return 0;
}