#include<cstdio>
#include<cstring>
#define mod 1000000007
using namespace std;
int n,m,k,x,y,f[2][2039],ans;
int main(){
	register int i,j,k,now,last;
	scanf("%d%d",&n,&m);
	for(i=0;i<=n;i++) f[1][i]=1;
	for(i=2;i<=m;i++){
		now=i&1;last=now^1;
		for(j=1;j<=n;j++){
			f[now][j]=0;
			for(k=1;k*j<=n;k++){
				f[now][j]=(f[now][j]+f[last][j*k])%mod;
			}
		}
	}
	for(i=1;i<=n;i++) ans=(ans+f[m&1][i])%mod;
	printf("%d\n",ans);
}