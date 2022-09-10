#include <bits/stdc++.h>

using namespace std;

typedef double T;
typedef long long int LL;

#define st first
#define nd second
#define PLL pair <LL, LL>
#define PII pair <int, int>

const int N = 1e6 + 7;
const int MX = 1e9 + 7;
const LL INF = 1LL * MX * MX;

int n, x;
LL a[N], b[N];

void solve(){
	scanf("%d", &n);
	for(int i = 0; i < n; ++i)
		scanf("%lld %lld", &a[i], &b[i]);
	
	LL mn_b = INF, ans = 0;
	for(int i = 0; i < n; ++i){
		b[i] = min(b[i], a[(i + 1) % n]);
		mn_b = min(mn_b, b[i]);
		ans += a[i] - b[i];
	}
	
	printf("%lld\n", ans + mn_b);
}

int main(){
	int cases;
	scanf("%d", &cases);
	
	while(cases--)
		solve();
	return 0;
}