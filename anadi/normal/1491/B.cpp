#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;

#define st first
#define nd second
#define PLL pair <LL, LL>
#define PII pair <int, int>

const int N = 1'000'007;
const int MOD = 1'000'000'007;
const LL INF = 1LL * MOD * MOD;

int n, u, v;
int in[N];

void solve() {
	scanf("%d %d %d", &n, &u, &v);
	for(int i = 1; i <= n; ++i)
		scanf("%d", &in[i]);
	
	LL ans = INF;
	for(int i = 1; i < n; ++i) {
		if(abs(in[i] - in[i + 1]) >= 2)
			ans = min(ans, 0LL);
		
		if(abs(in[i] - in[i + 1]) == 1)
			ans = min(ans, (LL)min(u, v));
	}
	
	if(ans < INF)
		printf("%lld\n", ans);
	else
		printf("%lld\n", v + (LL)min(u, v));
}

int main() {
	int cases;
	scanf("%d", &cases);
	
	while(cases--)
		solve();
	return 0;
}