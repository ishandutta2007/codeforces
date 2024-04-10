#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;

const int N = 2207;
const long double inf = 1e18;

int n, k;
LL res = 0LL;
long double A[N], B[N];

int cnt[N][N];
long double dp[N][N];

int ile(double wsp){
	for(int i = 1; i <= n; ++i)
		for(int j = 0; j <= i; ++j){
			dp[i][j] = inf;
			if(dp[i - 1][j] + 2.0 * wsp < dp[i][j]){
				dp[i][j] = dp[i - 1][j] + 2.0 * wsp;
				cnt[i][j] = cnt[i - 1][j];
			}
			
			if(dp[i - 1][j] + A[i] + B[i] < dp[i][j]){
				dp[i][j] = dp[i - 1][j] + A[i] + B[i];
				cnt[i][j] = cnt[i - 1][j] + 2;
			}
			
			if(j != 0 && dp[i - 1][j - 1] + A[i] + wsp < dp[i][j]){
				dp[i][j] = dp[i - 1][j - 1] + A[i] + wsp;
				cnt[i][j] = cnt[i - 1][j - 1] + 1;
			}

			if(j < i - 1 && dp[i - 1][j + 1] + B[i] + wsp < dp[i][j]){
				dp[i][j] = dp[i - 1][j + 1] + B[i] + wsp;
				cnt[i][j] = cnt[i - 1][j + 1] + 1;
			}
		}
	
//	printf("%lf -> %lf %d\n", wsp, dp[n][0], cnt[n][0]);
	if(cnt[n][0] == 2 * k)
		res = round(dp[n][0] - wsp * (2 * n - 2 * k));
	return cnt[n][0];
}

LL bs(long double s, long double e){
	int xd = 100;
	while(xd--){
		long double m = (e + s) / 2.0;
		if(ile(m) < 2 * k)
			s = m;
		else
			e = m;
	}
	
	return res;
}

int main(){
	scanf("%d %d", &n, &k);
	for(int i = 1; i <= n; ++i)
		scanf("%Lf", &A[i]);
	for(int i = 1; i <= n; ++i)
		scanf("%Lf", &B[i]);

	for(int i = 1; i <= n; ++i)
		for(int j = 0; j <= n; ++j)
			dp[i][j] = inf;
	for(int i = 1; i <= n; ++i)
		dp[0][i] = inf;

	printf("%lld\n", bs(0.0, 1e10));
	return 0;
}