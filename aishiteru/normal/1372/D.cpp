#include<stdio.h>
#include<string.h>
#define it register int
#define ct const int
#define il inline
using namespace std;
typedef long long ll;
#define rll register ll
#define cll const ll
const int N=1000005;
int n,a[N];
ll pre[N],suf[N],ans;
il ll Max(cll p,cll q){return p>q?p:q;}
int main(){ 
	scanf("%d",&n);it i;
	for(i=1;i<=n;++i) scanf("%d",&a[i]);
	for(i=2,pre[1]=a[1];i<=n;++i) pre[i]=pre[i-2]+a[i];
	for(i=n;i;--i) suf[i]=suf[i+2]+a[i];
	for(i=1;i<=n;++i) ans=Max(ans,pre[i]+suf[i+1]);
	printf("%lld",ans);
	return 0;
}