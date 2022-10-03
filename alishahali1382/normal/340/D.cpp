#include <bits/stdc++.h>
using namespace std;
int n, ans, inp;
int dp[100001];
int main(){
	ios_base::sync_with_stdio(false);
	scanf("%d", &n);
	fill(dp+1, dp+n+1, n+1);
	for (int i=0; i<n; i++){
		scanf("%d", &inp);
		int x=lower_bound(dp, dp+n, inp)-dp;
		dp[x]=min(dp[x], inp);
		ans=max(ans, x);
	}
	printf("%d\n", ans);
	return 0;
}