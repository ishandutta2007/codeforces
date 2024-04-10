#include<cstdio>
#include<cstring>
#include<algorithm>
#define abs(x) ((x)>0?(x):-(x))
#define min(a,b) ((a)<(b)?(a):(b))
using namespace std;
int n,m,k,x,y,z,a[239],dp[239][439],t,ans;
int main(){
	//freopen("1.in","r",stdin);
	register int i,j,k;
	scanf("%d",&t);
	while(t--){
		ans=1e9;
		scanf("%d",&n);
		for(i=1;i<=n;i++) scanf("%d",&a[i]);
		sort(a+1,a+n+1);
		memset(dp,0x3f,sizeof(dp));
		for(i=0;i<=2*n;i++) dp[0][i]=0;
		for(i=1;i<=n;i++){
			for(j=i;j<=2*n;j++) dp[i][j]=min(dp[i-1][j-1]+abs(j-a[i]),dp[i][j-1]);
		}
		for(j=1;j<=2*n;j++) ans=min(ans,dp[n][j]);
		printf("%d\n",ans);
	}
}