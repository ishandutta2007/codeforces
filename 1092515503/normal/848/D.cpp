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
int n,m,f[60][60],g[60][60],h[60][60],fac[60],inv[60];
int main(){
	scanf("%d%d",&n,&m);
	fac[0]=1;for(int i=1;i<=n;i++)fac[i]=1ll*fac[i-1]*i%mod;
	inv[n]=ksm(fac[n]);for(int i=n;i;i--)inv[i-1]=1ll*inv[i]*i%mod;
	f[0][0]=1;
	for(int i=0;i<=n;i++){
		for(int j=0;j<=i;j++){
			// printf("(%d,%d):%d\n",i,j,f[i][j]);
			for(int I=0;i+I<=n&&I<=i;I++)for(int J=0;J<=(I==i?j:I);J++)
				(g[i+I][min(j,J)]+=(i==I&&j==J?1ll:2ll)*f[i][j]*f[I][J]%mod)%=mod;
		}
		for(int j=0;j<=i;j++){
			// printf("[%d,%d]:%d\n",i,j,g[i][j]);
			for(int k=0,pro=1;k*(i+1)<=n;pro=1ll*pro*(g[i][j]+k)%mod,k++)
				for(int I=0;I+k*(i+1)<=n;I++)for(int J=0;J<=I;J++)
					// printf("%d:(%d,%d)<%d>%d,%d(%d,%d)\n",k,I,J,f[I][J],pro,inv[k],I+k*(i+1),J+k*(j+1)),
					(h[I+k*(i+1)][J+k*(j+1)]+=1ll*pro*inv[k]%mod*f[I][J]%mod)%=mod;
			for(int I=0;I<=n;I++)for(int J=0;J<=I;J++)f[I][J]=h[I][J],h[I][J]=0;
		}
	}
	printf("%d\n",f[n][m-1]);
	return 0;
}