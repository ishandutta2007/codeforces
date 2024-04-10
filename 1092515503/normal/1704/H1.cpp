/*
Criteria:
1.read the problem carefully; WRITE DOWN SPECIAL CONSTRAINTS when the problem is long;
2.consider special situations/constraints to get observations;
3.think of everything throughout before coding;
4.return to the initial list of notifications after coding.

CONSTRAINTS:

OBSERVATIONS:

OTHER NOTIFICATIONS:

THINK CAREFULLY AND CODE DETERMINEDLY!
*/
#include<bits/stdc++.h>
using namespace std;
int n,mod,fac[5010],inv[5010],res;
int ksm(int x,int y=mod-2){int z=1;for(;y;y>>=1,x=1ll*x*x%mod)if(y&1)z=1ll*z*x%mod;return z;}
int C(int x,int y){return 1ll*fac[x]*inv[y]%mod*inv[x-y]%mod;}
int main(){
	scanf("%d%d",&n,&mod);
	fac[0]=1;for(int i=1;i<=n;i++)fac[i]=1ll*fac[i-1]*i%mod;
	inv[n]=ksm(fac[n]);for(int i=n;i;i--)inv[i-1]=1ll*inv[i]*i%mod;
	for(int i=1,p=n-1;i<=n;i++,p=1ll*p*(n-1)%mod)for(int j=i<<1;j<=n;j++){
		int a=1ll*p*C(j-i-1,i-1)%mod;
		// printf("<%d,%d:%d>\n",i,j,a);
		a=1ll*a*ksm(j-i,n-j)%mod;
		a=1ll*inv[n-j]*inv[i]%mod*a%mod;
		(res+=a)%=mod;
	}
	printf("%d\n",1ll*res*fac[n]%mod);
	return 0;
}