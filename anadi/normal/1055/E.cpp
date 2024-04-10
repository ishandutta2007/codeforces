#include <bits/stdc++.h>

using namespace std;

typedef double D;
typedef long long int LL;

#define st first
#define nd second
#define pb push_back
#define PLL pair <LL, LL>
#define PII pair <int, int>

const int N = 1507;
const int MX = 1e9 + 7;
const LL INF = 1e18 + 9LL;

int n, s, m, k;
int in[N];
PII seg[N];
int pref[N];
int best[N];
int dp[N][N];
vector <int> G[N];

bool ok(int val){
	for(int i = 1; i <= n; ++i)
		pref[i] = pref[i - 1] + (in[i] <= val);
	
	for(int i = 0; i <= m; ++i)
		dp[0][i] = 0;
	
	for(int i = 1; i <= n; ++i){
		dp[i][0] = 0;
		for(int j = 1; j <= m; ++j){
			dp[i][j] = dp[i - 1][j];
			dp[i][j] = max(dp[i][j], dp[best[i] - 1][j - 1] + pref[i] - pref[best[i] - 1]);
		}
	}
	
	for(int i = 1; i <= m; ++i)
		if(dp[n][i] >= k)
			return true;
	return false;
}

int main(){
	scanf("%d %d %d %d", &n, &s, &m, &k);
	for(int i = 1; i <= n; ++i)
		scanf("%d", &in[i]);
	
	for(int i = 1; i <= s; ++i){
		scanf("%d %d", &seg[i].st, &seg[i].nd);
		G[seg[i].nd].push_back(seg[i].st);
	}
	
	best[n + 1] = n + 1;
	for(int i = n; i >= 1; --i){
		best[i] = min(best[i + 1], i + 1);
		for(int v: G[i])
			best[i] = min(best[i], v);
	}
	
	int p = 1, k = MX;
	while(p < k){
		int mid = (p + k) / 2;
		if(ok(mid))
			k = mid;
		else
			p = mid + 1;
	}
	
	if(p == MX)
		puts("-1");
	else
		printf("%d\n", p);
	return 0;
}