#include <bits/stdc++.h>

using namespace std;

typedef long double T;
typedef long long int LL;

#define st first
#define nd second
#define PLL pair <LL, LL>
#define PII pair <int, int>

const int N = 1e6 + 7;
const int MX = 1e9 + 7;
const LL INF = 1LL * MX * MX;

int n;
int in[N];
int mx[N];

void solve(){
	int max_inc = 0;
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i){
		scanf("%d", &in[i]);
		mx[i] = in[i];

		if(i > 1)
			mx[i] = max(mx[i], mx[i - 1]);
		max_inc = max(max_inc, mx[i] - in[i]);
	}
	
	int ans = 0;
	while(max_inc > 0)
		max_inc /= 2, ++ans;
	printf("%d\n", ans);
}

int main(){
	int cases;
	scanf("%d", &cases);
	
	while(cases--)
		solve();
	return 0;
}