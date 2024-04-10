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
const int inv2=5e8+4;
int n,g[1001000],f[1001000],inv[1001000],pov[1001000];
void mina(){
	scanf("%d",&n);
	for(int i=0;i<=n+1;i++)f[i]=g[i]=0;
	g[n]=inv[n],g[n-1]=mod-inv[n];
	for(int i=n;i;i--){
		(g[i-1]+=g[i])%=mod;
		g[i]=1ll*g[i]*pov[i]%mod;
		int p=(i>>1);
		(g[i-1]+=1ll*g[i]*inv[i]%mod)%=mod;
		(g[p]+=mod-1ll*g[i]*inv[i]%mod)%=mod;
		f[i]=1ll*inv[i-1]*g[i]%mod;
		f[i]=(1ll*inv[i]*g[i]%mod*(pov[p+1]+mod-2)+f[i])%mod;
	}
	for(int i=1;i<=n;i++)printf("%d ",f[i]);puts("");
}
int T;
int main(){
	pov[0]=inv[0]=1;for(int i=1;i<=1000000;i++)inv[i]=1ll*inv[i-1]*inv2%mod,pov[i]=(pov[i-1]<<1)%mod;
	scanf("%d",&T);while(T--)mina();return 0;
}