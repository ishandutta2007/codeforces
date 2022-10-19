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
int n,m,f[300100],a[100100],N,_N,M,res;
int main(){
	scanf("%d",&n),N=ksm(n),_N=ksm(n-1);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]),m+=a[i];
	M=ksm(m);
	f[0]=0;
	f[1]=mod-1ll*(n-1)*N%mod;
	for(int i=1;i<m;i++){
		int val=(f[i]+3ll*mod-N-1ll*i*M%mod*f[i-1]%mod-1ll*(m-i)*M%mod*(n-2)%mod*_N%mod*f[i]%mod)%mod;
		f[i+1]=1ll*val*m%mod*(n-1)%mod*ksm(m-i)%mod;
	}
	// for(int i=0;i<=m;i++)printf("%d ",f[i]);puts("");
	for(int i=1;i<=n;i++)(res+=f[a[i]])%=mod;
	(res+=mod-f[m])%=mod;
	printf("%d\n",res);
	return 0;
}