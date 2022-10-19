#include<cstdio>
#include<cstring>
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))
using namespace std;
int n,m,dp[59][59][59][59],a[59][59];
char _s;
int main(){
//	freopen("1.in","r",stdin);
	register int i,j,x,y,k;
	scanf("%d",&n);memset(dp,0x3f,sizeof(dp));
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++) {
			_s=getchar();
			while(_s!='#'&&_s!='.') _s=getchar();
			a[i][j]=(_s=='#'?1:0);
			dp[i][i][j][j]=a[i][j];
		}
	}
	for(i=n;i;i--){
		for(j=i;j<=n;j++){
			for(x=n;x;x--){
				for(y=x;y<=n;y++){
					dp[i][j][x][y]=min(dp[i][j][x][y],max(y-x+1,j-i+1));
					for(k=i;k<j;k++) dp[i][j][x][y]=min(dp[i][j][x][y],dp[i][k][x][y]+dp[k+1][j][x][y]);
					for(k=x;k<y;k++) dp[i][j][x][y]=min(dp[i][j][x][y],dp[i][j][x][k]+dp[i][j][k+1][y]);
				}
			}
		}
	}
	printf("%d\n",dp[1][n][1][n]);
}