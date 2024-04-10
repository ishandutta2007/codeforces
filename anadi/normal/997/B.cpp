#include <bits/stdc++.h>

using namespace std;

typedef double D;
typedef long long int LL;

#define st first
#define nd second
#define pb push_back
#define PDD pair <D, D>
#define PLL pair <LL, LL>
#define PII pair <int, int>

const int N = 1007;
const int MX = 1e9 + 7;
const LL INF = 1e18 + 9LL;

LL n;
LL res = 0LL;
bool dp[N][N];

bool possible(LL a){
	LL cur = n;
	if(a > 1000){
		LL diff = (a - 950) / 50;
		a -= diff * 50LL;
		cur -= diff;
	}
	
	if(cur >= N)
		return false;
	return dp[a][cur];
}

bool possible2(LL a){
	LL cur = n;
	if(a > 1000){
		LL diff = (a - 1000);
		a -= diff;
		cur -= diff;
	}
	
	if(cur >= N)
		return false;
	return dp[a][cur];
}

int main(){
	cin >> n;
	LL from = max(1LL, 50LL * (n - 10)), to = 50LL * n;
	
	dp[0][0] = true;
	for(int i = 1; i < N; ++i){
		for(int j = 1; j <= i; ++j){
			dp[i][j] = dp[i - 1][j - 1];
			if(i > 4)
				dp[i][j] |= dp[i - 5][j - 1];
			if(i > 9)
				dp[i][j] |= dp[i - 10][j - 1];
			if(i > 49)
				dp[i][j] |= dp[i - 50][j - 1];
		}
	}
	
	for(LL i = from; i <= to; ++i)
		res += possible(i);
	
	res += max(0LL, from - n - 500);
	to = min(from, n + 500);

	for(int i = n; i < to; ++i)
		if(possible2(i))
			++res;
	printf("%lld\n", res);
	return 0;
}