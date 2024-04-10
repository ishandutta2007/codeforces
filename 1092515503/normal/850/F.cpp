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
int ksm(int x,int y=mod-2){int z=1;for(;y;y>>=1,x=1ll*x*x%mod)if(y&1)z=1ll*z*x%mod;return z;}
const int N=100000;
int n,m,g[100100],f[100100],a[100100],res;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]),m+=a[i];
	g[0]=mod-1ll*(m-1)*ksm(m)%mod;for(int i=1;i<=N;i++)g[i]=(g[i-1]+mod-1ll*(m-1)*ksm(m-i)%mod)%mod;
	f[0]=0;for(int i=1;i<=N;i++)f[i]=(f[i-1]+g[i-1])%mod;
	// for(int i=0;i<=3;i++)printf("%d ",f[i]);puts("");
	for(int i=1;i<=n;i++)(res+=f[a[i]])%=mod;
	(res+=1ll*m*(m-1)%mod)%=mod;
	printf("%d\n",res);
	return 0;
}