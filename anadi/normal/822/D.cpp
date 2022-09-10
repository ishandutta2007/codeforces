#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;

#define st first
#define nd second
#define pb push_back
#define PLL pair <LL, LL>
#define PII pair <int, int>

const int N = 5e6 + 7;
const LL MX = 1e9 + 7LL;

int t, l, r;
LL dp[N];

int main(){
	scanf("%d %d %d", &t, &l, &r);
	for(int i = 2; i <= r; ++i)
		dp[i] = 1LL * i * i;
	
	for(int i = 1; i <= r; ++i)
		for(int j = 2; i * j <= r; ++j)
			dp[j * i] = min(dp[j * i], dp[i] + ((1LL * j  * (j * i - i)) >> 1));
	
	LL res = 0LL;
	LL nowT = 1LL;
	for(int i = l; i <= r; ++i)
		res += ((dp[i]%MX) * nowT)%MX,
		nowT = (1LL * nowT * t)%MX;
	res %= MX;
	
	printf("%lld\n", res);
	return 0;
}