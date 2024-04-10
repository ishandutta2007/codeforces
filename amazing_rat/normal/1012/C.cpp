#include <bits/stdc++.h>
#define dbug(x) cout<<#x<<"="<<x<<endl
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while ('0'>ch||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do {(t*=10)+=ch-'0';ch=getchar();} while ('0'<=ch&&ch<='9'); t*=f;
}
const int INF=(1e9);
int n,m,dp[5010][5010][2],a[5010];
int main() {
	//freopen("1.txt","r",stdin);
	read(n); m=(n+1)/2;
	a[0]=a[n+1]=-INF;
	for (int i=1;i<=n;i++) read(a[i]);
	memset(dp,0x7f7f7f7f,sizeof(dp));
	dp[0][0][0]=0;
	for (int i=1;i<=n;i++)
	for (int j=0;j<=(i+1)/2;j++) {
		dp[i][j][0]=min(dp[i-1][j][0],dp[i-1][j][1]);
		if (!j) continue;
		dp[i][j][1]=min(dp[i][j][1],dp[i-1][j-1][0]+max(a[i-1]-a[i]+1,0)+max(a[i+1]-a[i]+1,0));
		if (i==1) continue;
		if (a[i-2]<=a[i-1])
			 dp[i][j][1]=min(dp[i][j][1],dp[i-2][j-1][1]+max(a[i-2]-a[i],0)  +max(a[i+1]-a[i]+1,0));
		else dp[i][j][1]=min(dp[i][j][1],dp[i-2][j-1][1]+max(a[i-1]-a[i]+1,0)+max(a[i+1]-a[i]+1,0));
	}
	for (int i=1;i<=m;i++)
		printf("%d ",min(dp[n][i][1],dp[n][i][0]));
	printf("\n");
	return 0;
}