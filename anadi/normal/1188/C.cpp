#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;

#define st first
#define nd second
#define PLL pair <LL, LL>
#define PII pair <int, int>

const int N = 1007;
const int MX = 998244353;
const LL INF = 1LL * MX * MX;

int n, k, ans;
int in[N];
int dp[N][N];

void add(int &a, int b){
	a += b;
	if(a >= MX)
		a -= MX;
}

int solve2(int t){
	in[0] = -MX;
	int last = 0, ret = 0;

	for(int i = 1; i <= n; ++i)
		if(in[i] - in[last] >= t)
			++ret, last = i;
	return ret >= k;
}

int solve(int t){
	for(int i = 1; i <= n; ++i)
		for(int j = 0; j <= k; ++j)
			dp[i][j] = 0;
	
	int last = 0;
	dp[0][0] = 1;
	
	for(int i = 1; i <= n; ++i){
		while(in[last + 1] + t <= in[i])
			++last;
		
		dp[i][0] = dp[i - 1][0];
		for(int j = 1; j <= k; ++j){
			dp[i][j] = dp[i - 1][j];
			add(dp[i][j], dp[last][j - 1]);
		}
	}
	
	return dp[n][k];
}

int main(){
	scanf("%d %d", &n, &k);
	for(int i = 1; i <= n; ++i)
		scanf("%d", &in[i]);
	sort(in + 1, in + n + 1);
	
	set <int> sens;
	for(int i = 1; i <= n; ++i)
		for(int j = i + 1; j <= n; ++j)
			sens.insert(in[i] - in[j]);

	int s = 0, e = 100 * 1000;
	while(s < e){
		int mid = (s + e + 1) >> 1;
		if(solve2(mid) == 0)
			e = mid - 1;
		else
			s = mid;
	}
	
	int pref = 0;
	for(auto v: sens){
		if(-v > s)
			continue;

		if(v == 0)
			break;

		int cur = solve(-v);
		ans = (ans + 1LL * (cur - pref + MX) * (-v)) % MX;
		pref = cur;
	}

	printf("%d\n", ans);
	return 0;
}