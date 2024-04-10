#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;

#define st first
#define nd second
#define PLL pair <LL, LL>
#define PII pair <int, int>

const int N = 1e6 + 7;
const int MX = 1e9 + 7;
const LL INF = 1e18 + 9LL;

int n, d;
int in[N];

void solve(){
	int ans = 0;
	scanf("%d %d", &n, &d);
	for(int i = 0; i < n; ++i){
		int cur;
		scanf("%d", &cur);
		
		while(cur > 0 && d >= i){
			cur--;
			ans++;
			d -= i;
		}
	}
	
	printf("%d\n", ans);
}

int main(){
	int cases;
	scanf("%d", &cases);
	
	while(cases--)
		solve();
	return 0;
}