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
int n,f[410][410],g[410][410];
int main(){
	scanf("%d",&n);
	g[0][0]=f[0][0]=1;
	for(int i=1;i<=n;i++){
		for(int j=0;j<=n;j++)for(int k=0;k<=n;k++){
			if(j+k+1<=n)f[i][j+k+1]=(1ll*g[i-1][j]*g[i-1][k]+f[i][j+k+1])%mod;//take i as individual path.
			if(j+k<=n)f[i][j+k]=(2ll*g[i-1][j]*g[i-1][k]%mod*(j+k)+f[i][j+k])%mod;
			//choose a path,and insert i in the front or at the back of it.
			if(j+k>=2&&j+k-1<=n)
				f[i][j+k-1]=(1ll*(j+k)*(j+k-1)%mod*g[i-1][j]%mod*g[i-1][k]+f[i][j+k-1])%mod;
			//use i to fuse two paths.
		}
		for(int j=0;j<=n;j++)for(int k=0;k<=n;k++)
			if(j+k<=n)g[i][j+k]=(1ll*g[i-1][j]*g[i-1][k]+g[i][j+k])%mod;
		for(int j=0;j<=n;j++)(g[i][j]+=f[i][j])%=mod;
		// for(int j=0;j<=n;j++)printf("[%d,%d]",f[i][j],g[i][j]);puts("");
	}
	printf("%d\n",g[n][1]);
	return 0;
}