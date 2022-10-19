/*
Criteria:
1.read the problem carefully; WRITE DOWN SPECIAL CONSTRAINTS when the problem is long;
2.consider special situations/constraints to get observations;
3.think of everything throughout before coding;
4.return to the initial list of notifications after coding.

CONSTRAINTS:

OBSERVATIONS:

OTHER NOTIFICATIONS:

THINK CAREFULLY AND CODE DETEMINEDLY!
*/
#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int ksm(int x,int y=mod-2){int z=1;for(;y;y>>=1,x=1ll*x*x%mod)if(y&1)z=1ll*z*x%mod;return z;}
int n,m,fac[300],inv[300],f[300];
int main(){
    scanf("%d%d",&n,&m);
    fac[0]=1;for(int i=1;i<=n;i++)fac[i]=1ll*fac[i-1]*i%mod;
    inv[n]=ksm(fac[n]);for(int i=n;i;i--)inv[i-1]=1ll*inv[i]*i%mod;
    f[0]=1;
    for(int i=1;i<=m;i++)for(int j=n-1;j>=0;j--)for(int k=1;k<=j;k++)
        f[j]=(1ll*f[j-k]*inv[k]%mod*ksm(m-i+1,(j-k)*k+k*(k-1)/2)+f[j])%mod;
    printf("%d\n",1ll*f[n-1]*fac[n-1]%mod);
    return 0;
}