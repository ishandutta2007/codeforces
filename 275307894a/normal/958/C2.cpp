#include<cstdio>
using namespace std;
int n,m,k,x,y,z,dp[59][20039],f[139],a[20039],q[20039];
inline int max(int x,int y){return x>y?x:y;}
int main() {
//	freopen("1.in","r",stdin);
	register int i,j,h;
	scanf("%d%d%d",&n,&m,&k);
	for(i=1;i<=n;i++)scanf("%d",&a[i]),q[i]=(q[i-1]+a[i])%k;
	for(i=1;i<=n;i++) dp[0][i]=-1e9;
	for(i=1;i<=m;i++){
		for(j=0;j<=k;j++) f[j]=-1e9;f[0]=0;
		for(j=1;j<=n;j++){
			for(h=0;h<k;h++)dp[i][j]=max(dp[i][j],f[h]+(q[j]-h+k)%k);
			f[q[j]]=max(f[q[j]],dp[i-1][j]);
		}
	}
	printf("%d\n",dp[m][n]);
}