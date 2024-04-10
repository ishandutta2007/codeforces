#include <bits/stdc++.h>

using namespace std;

typedef double D;
typedef long long int LL;

#define st first
#define nd second
#define pb push_back
#define PLL pair <LL, LL>
#define PII pair <int, int>

const int N = 1e6 + 7;
const int MX = 1e9 + 7;
const LL INF = 1e18 + 9LL;

LL n;
LL dp[100];
vector <LL> maxi = {1, INF - 9, MX - 7, N - 7, 31622, 3981, 1000, 372, 177, 100, 63, 43, 31, 24, 19, 15, 13, 11, 10, 8, 7, 7, 6, 6, 5, 5, 4, 4, 4, 4, 3, 3, 3, 3, 3, 3, 3, 3, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2};

LL fast(LL a, int b){
	LL ret = 1LL;
	while(b){
		if(b & 1)
			ret *= a;
		
		b >>= 1;
		a *= a;
	}
	
	return ret;
}

LL get(LL from, LL to, int pt){
	to = min(to, maxi[pt]);
	while(from < to){
		LL m = (from + to + 1) / 2LL;
		if(fast(m, pt) <= n)
			from = m;
		else
			to = m - 1;
	}
	
	return from;
}

void solve(){
	scanf("%lld", &n);

	dp[1] = n - 1;
	for(int i = 2; i <= 60; ++i)
		dp[i] = get(1, dp[i - 1] + 1, i) - 1;
	
	for(int i = 60; i >= 1; --i)
		for(int j = i + i; j <= 60; j += i)
			dp[i] -= dp[j];
	printf("%lld\n", dp[1]);
}

int main(){
	int quest;
	scanf("%d", &quest);
	while(quest--)
		solve();
	return 0;
}