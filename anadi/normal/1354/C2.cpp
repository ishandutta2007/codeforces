#include <bits/stdc++.h>

using namespace std;

typedef long double T;
typedef long long int LL;

#define st first
#define nd second
#define PLL pair <LL, LL>
#define PII pair <int, int>

const int N = 1e6 + 7;
const T PI = acosl(-1.0);

const int MX = 1e9 + 7;
const LL INF = 1LL * MX * MX;

void solve(){
	int n;
	scanf("%d", &n);

	T alpha = PI / n;
	T cur = alpha / 4;
	T ans = 0.0;
	
	for(int i = 0; i < n; ++i){
		ans += sin(cur);
		cur += alpha;
	}
	
	printf("%.10Lf\n", ans);
}

int main(){
	int cases;
	scanf("%d", &cases);
	
	while(cases--)
		solve();
	return 0;
}