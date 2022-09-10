#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;

#define st first
#define nd second
#define pb push_back
#define PLL pair <LL, LL>
#define PII pair <int, int>

const int N = 1e6 + 7;
const int MX = 1e9 + 7;
const LL INF = 1e18 + 9LL;

int n, d;
int x, y;

void solve(){
	scanf("%d %d %d %d", &n, &x, &y, &d);
	if(abs(x - y)%d == 0){
		printf("%d\n", abs(x - y) / d);
		return;
	}
	
	int res = 2 * MX;
	if(y%d == 1)
		res = min(res, (y + d - 2) / d + (x + d - 2) / d);

	if(n%d == y%d)
		res = min(res, (n - y + d - 1) / d + (n - x + d - 1) / d);
	
	if(res >= MX + MX)
		printf("-1\n");
	else
		printf("%d\n", res);
}

int main(){
	int cases;
	scanf("%d", &cases);
	
	while(cases--)
		solve();
	return 0;
}