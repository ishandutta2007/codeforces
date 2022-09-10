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
int in[N];

void solve(){
	scanf("%d %d", &n, &x);
	for(int i = 1; i <= n; ++i)
		scanf("%d", &in[i]);

	sort(in + 1, in + n + 1);
	reverse(in + 1, in + n + 1);
	
	int ans = 0;
	long long s = 0;
	
	for(int i = 1; i <= n; ++i){
		s += in[i] - x;
		if(s >= 0)
			ans = i;
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