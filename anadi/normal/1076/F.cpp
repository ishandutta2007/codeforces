#include <bits/stdc++.h>

using namespace std;

typedef double D;
typedef long long int LL;

#define st first
#define nd second
#define pb push_back
#define PLL pair <LL, LL>
#define PII pair <int, int>

const int N = 3e5 + 7;
const int MX = 1e9 + 7;
const LL INF = 1e18 + 9LL;

int n, k;
int x[N], y[N];
int dp[N][2];

int get(int la, int lb, int ca, int cb){
	int ret = k + 1;
	if(la <= k){
		int need = (cb + k - 1) / k;
		LL maxPoss = 1LL * cb * k + k - la;
		if(need <= ca && ca <= maxPoss)
			ret = min(1LL * ret, max(1LL, k - maxPoss + ca));
	}
	
	if(lb <= k){
		LL maxPoss = 1LL * (ca - 1) * k + k - lb;
		LL maxPoss2 = 1LL * (cb + 1) * k;
		
		if(cb <= maxPoss && ca <= maxPoss2)
			ret = min(1LL * ret, max(1LL, k - maxPoss2 + ca));
	}
	
	return ret;
}

int main(){
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
//	cout.tie(NULL);

	scanf("%d %d", &n, &k);
	for(int i = 1; i <= n; ++i)
		scanf("%d", &x[i]);
	for(int i = 1; i <= n; ++i)
		scanf("%d", &y[i]);
	
	for(int i = 1; i <= n; ++i){
		dp[i][0] = get(dp[i - 1][0], dp[i - 1][1], x[i], y[i]);
		dp[i][1] = get(dp[i - 1][1], dp[i - 1][0], y[i], x[i]);
	}
	
	puts((dp[n][0] <= k || dp[n][1] <= k) ? "YES" : "NO");
	return 0;
}