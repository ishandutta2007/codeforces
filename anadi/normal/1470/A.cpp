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

int n, m;
int in[N];
int cost[N];

void solve() {
	scanf("%d %d", &n, &m);
	for(int i = 1; i <= n; ++i)
		scanf("%d", &in[i]);

	for(int i = 1; i <= m; ++i)
		scanf("%d", &cost[i]);

	sort(in + 1, in + n + 1);
	reverse(in + 1, in + n + 1);
	
	LL ans = 0;
	for(int i = 1; i <= n; ++i)
		if(i <= in[i])
			ans += cost[i];
		else
			ans += cost[in[i]];
	
	printf("%lld\n", ans);
}

int main() {
	int cases;
	scanf("%d", &cases);
	
	while(cases--)
		solve();
	return 0;
}