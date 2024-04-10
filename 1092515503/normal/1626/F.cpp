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
const int mod=998244353;
int ksm(int x,int y=mod-2){int z=1;for(;y;y>>=1,x=1ll*x*x%mod)if(y&1)z=1ll*z*x%mod;return z;}
const int lcm=720720;
int n,a,X,Y,K,M,res,sum;
int f[lcm],g[lcm],F[lcm],G[lcm];
int main(){
	scanf("%d%d%d%d%d%d",&n,&a,&X,&Y,&K,&M);
	for(int _=0;_<n;_++)f[a%lcm]++,(sum+=a/lcm)%=mod,a=(1ll*a*X+Y)%M;
	sum=1ll*sum*lcm%mod;
	res=1ll*K*sum%mod*ksm(n,K-1)%mod;
//	printf("%d\n",res);
	for(int i=1;i<=K;i++){
		for(int j=0;j<lcm;j++){
//			if(f[j]||g[j])printf("[%d:%d,%d]",j,f[j],g[j]);
			F[j]=(1ll*f[j]*(n-1)+F[j])%mod;
			G[j]=(1ll*g[j]*(n-1)+G[j])%mod;
			(F[j/i*i]+=f[j])%=mod;
			G[j/i*i]=(1ll*f[j]*j+g[j]+G[j/i*i])%mod;
		}//puts("");
		for(int j=0;j<lcm;j++)f[j]=F[j],g[j]=G[j],F[j]=G[j]=0;
	}
	for(int j=0;j<lcm;j++)(res+=g[j])%=mod;
	printf("%d\n",res);
	return 0;
}