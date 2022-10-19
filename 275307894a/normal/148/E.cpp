#include<cstdio>
#define max(a,b) ((a)>(b)?(a):(b))
using namespace std;
int n,m,k,x,y,z,t[139],f[139][139],dp[10039],q[139],qs[139],a[139];
int main(){
	register int i,j,k;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++){
		scanf("%d",&t[i]);
		for(j=1;j<=t[i];j++) scanf("%d",&a[j]);
		qs[t[i]+1]=0;
		for(j=1;j<=t[i];j++) q[j]=q[j-1]+a[j];
		for(j=t[i];j;j--) qs[j]=qs[j+1]+a[j];
		for(j=1;j<=t[i];j++) {
			for(k=0;k<=j;k++) f[i][j]=max(f[i][j],q[k]+qs[t[i]-j+1+k]);
		} 
	}
	for(i=1;i<=n;i++){
		for(j=m;j;j--){
			for(k=1;k<=t[i]&&k<=j;k++) dp[j]=max(dp[j],dp[j-k]+f[i][k]);
		}
	}
	printf("%d\n",dp[m]);
}