#include <bits/stdc++.h>
#define dbug(x) cout<<#x<<"="<<x<<endl
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while ('0'>ch||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do {(t*=10)+=ch-'0';ch=getchar();} while ('0'<=ch&&ch<='9'); t*=f;
}
int n,m,ans;
int dp[1010][1010][2];
int main() {
	//freopen("1.txt","r",stdin);
	read(n); read(m); m=n-m;
	if (m==n) { printf("1\n"); return 0; }
	for (int k=0;k<=1;k++) {
		if (m-k<0) continue;
		for (int i=1;i<=n;i++)
		for (int j=0;j<=n;j++) dp[i][j][0]=dp[i][j][1]=-(1e9);
		dp[1][k][k]=k;
		for (int i=1;i<=n;i++) {
			for (int j=0;j<=i;j++) {
				for (int k1=0;k1<=1;k1++)
				for (int k2=0;k2<=1;k2++) {
					dp[i+1][j+k2][k2]=max(dp[i+1][j+k2][k2],dp[i][j][k1]+(k1==0&&k2==1));
					//if (i==6&&j==3&&k1==0) printf("!!%d %d\n",k2,dp[i+1][j+k2][k2]);	
				}
				//if (k) printf("%d %d %d %d\n",i,j,dp[i][j][0],dp[i][j][1]);
			}
		}
		//printf(" %d %d %d\n",k,dp[n][m][0],dp[n][m][1]);
		if (!k) ans=max(ans,dp[n][m][0]),ans=max(ans,dp[n][m][1]);
		else ans=max(ans,dp[n][m][0]),ans=max(ans,dp[n][m][1]-1);
	}
	printf("%d\n",ans);
	return 0;
}