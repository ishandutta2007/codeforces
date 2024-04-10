#include<cstdio>
#include<algorithm>
#define min(a,b) ((a)<(b)?(a):(b))
#define mod 998244353
using namespace std;
int n,m,k,x,y,z;
long long ans,a[400039],po[300039],pr[300039],f[300039],now,s[300039],sf[300039],head;
int main(){
	register int i,j;
	scanf("%d",&n);
	for(i=1;i<=2*n;i++)scanf("%lld",&a[i]);
	po[0]=1;
	for(i=1;i<=2*n;i++) po[i]=po[i-1]*2%mod;
	sort(a+1,a+2*n+1);
	for(i=1;i<=2*n;i++){
		if(i>n) ans=(a[i]+ans)%mod;
		else ans=(ans-a[i]+mod)%mod;
	}
	for(i=2; i<=300000; i++) {
		if(!f[i]) s[++head]=i,pr[i]=i;
		for(j=1; j<=head&&i*s[j]<=300000; j++) {
			f[i*s[j]]=1;pr[i*s[j]]=s[j];
			if(i%s[j]==0) break;
		}
	}
	for(i=1;i<=2*n-1;i++){
		now=i;
		while(now!=1) sf[pr[now]]++,now/=pr[now];
	} 
	for(i=1;i<=n-1;i++){
		now=i;
		while(now!=1) sf[pr[now]]--,now/=pr[now];
	}
	for(i=1;i<=n;i++){
		now=i;
		while(now!=1) sf[pr[now]]--,now/=pr[now];
	}
	for(i=1;i<=2*n;i++){
		while(sf[i]) ans=ans*i%mod,sf[i]--;
	}
	printf("%lld\n",ans*2%mod);
}