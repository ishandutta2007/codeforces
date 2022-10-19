#include<cstdio>
#define mod 1000000007ll
using namespace std;
long long n,m,k,x,y,z,ans=1,tot,po[1000039];
int main(){
	register int i;
	scanf("%lld",&n);
	po[0]=1;
	for(i=1;i<=n;i++) ans=ans*i%mod,po[i]=po[i-1]*2%mod;
	for(i=2;i<n;i++)tot=(tot+po[n-i-1])%mod;
	ans=(ans-tot*2-2+mod*3)%mod;
	printf("%lld\n",ans);
}