#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;

#define st first
#define nd second
#define PLL pair <LL, LL>
#define PII pair <int, int>

const int N = 1e6 + 7;
const int MX = 1e9 + 7;
const LL INF = 1LL * MX * MX;

int n, x;
int best, bestDiff;

void solve(){
	scanf("%d %d", &n, &x);
	best = 0, bestDiff = 0;
	
	for(int i = 1; i <= n; ++i){
		int a, b;
		scanf("%d %d", &a, &b);
		
		best = max(best, a);
		bestDiff = max(bestDiff, a - b);
	}
	
	if(best >= x)
		puts("1");
	else if(bestDiff == 0)
		puts("-1");
	else
		printf("%d\n", 1 + (x - best + bestDiff - 1) / bestDiff);
}

int main(){
	int cases;
	scanf("%d", &cases);
	
	while(cases--)
		solve();
	return 0;
}