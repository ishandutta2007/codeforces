#include<cstdio>
#include<iostream>
#include<cstring>
#define mod 1000000007
using namespace std;
int n,m,k,x,y,z,a[100039];
char s[100039];
long long ans,pus=1,tot,q[100039],pow[100039],qs[100039];
int main(){
//	freopen("1.in","r",stdin);
	register int i;
	cin>>s+1;
	n=strlen(s+1);
	for(i=1;i<=n;i++)a[i]=s[i]-'0';
	pow[n]=1;
	for(i=n-1;i;i--) pow[i]=pow[i+1]*10%mod,pus=(pow[i]+pus)%mod;
	for(i=n;i;i--) q[i]=(q[i+1]+pow[i]*a[i])%mod,tot=(q[i]+tot)%mod;
	tot=(tot-q[1]+mod)%mod;
	qs[1]=a[1];
	for(i=2;i<=n;i++) qs[i]=(qs[i-1]*10+a[i])%mod;
	for(i=1;i<=n;i++){
		ans=(ans+qs[i-1]*pus+tot)%mod;
		pus=(pus-pow[i]+mod)%mod;
		tot=(tot-q[i+1]+mod)%mod;
		//printf("%lld\n",ans);
	}
	printf("%lld\n",ans);
}