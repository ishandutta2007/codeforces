#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e5 + 10;

int dp[maxn], t[maxn], x[maxn], y[maxn], par[maxn];

int main(){
	ios_base::sync_with_stdio(false);
	int r, n;
	scanf("%d%d", &r, &n);
	for (int i = 1; i <= n; i++)
		scanf("%d%d%d", &t[i], &x[i], &y[i]);
	x[0] = y[0] = 1;
	memset(dp, -63, sizeof dp);
	dp[0] = 0;
	par[0] = 0;
	for (int i = 1; i <= n; i++){
		for (int j = i-1; j >= max(0,i-2*r); j--)
			if (abs(x[i]-x[j])+abs(y[i]-y[j]) <= t[i]-t[j])
				dp[i] = max(dp[i], dp[j]+1);
		if (2*r < i)
			dp[i] = max(dp[i], par[i-2*r-1]+1);
		par[i] = max(par[i-1], dp[i]);
	}
	printf("%d\n", par[n]);
}