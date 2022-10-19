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
const int mod=1e9+7;
const int N=1000000;
int ksm(int x,int y=mod-2){int z=1;for(;y;y>>=1,x=1ll*x*x%mod)if(y&1)z=1ll*z*x%mod;return z;}
int n,a[200100],fac[1001000],inv[1001000],res;
int bnm(int x,int y){return x<0?0:1ll*fac[x+y]*inv[x]%mod*inv[y]%mod;}
int main(){
	scanf("%d",&n);
	for(int i=0;i<=n;i++)scanf("%d",&a[i]);
	fac[0]=1;for(int i=1;i<=N;i++)fac[i]=1ll*fac[i-1]*i%mod;
	inv[N]=ksm(fac[N]);for(int i=N;i;i--)inv[i-1]=1ll*inv[i]*i%mod;
	res=bnm(a[0]-1,1);
	for(int i=1;i<=n;i++)(res+=bnm(a[i]-1,i+1))%=mod;
	printf("%d\n",res);
	return 0;
}