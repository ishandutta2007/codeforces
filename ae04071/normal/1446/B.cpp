#include <bits/stdc++.h>
using namespace std;

int n,m,dp[5005][5005];
char s[5005],t[5005];

int main() {
	scanf("%d%d%s%s",&n,&m,s+1,t+1);
	
	int ans=0;
	s[0]=1;
	for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) {
		dp[i][j] = max({dp[i-1][j]-1, dp[i][j-1]-1, dp[i-1][j-1]-2+4*(s[i]==t[j])});
		dp[i][j] = max(dp[i][j], 0);
		ans = max(ans, dp[i][j]);
	}
	printf("%d\n",ans);

	return 0;
}