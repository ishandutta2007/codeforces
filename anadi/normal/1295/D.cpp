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

void solve(){
	LL a, m;
	scanf("%lld %lld", &a, &m);
	
	LL d = __gcd(a, m);
	m /= d;
	
	LL ans = 1;
	for(int i = 2; 1LL * i * i <= m; ++i)
		if(m % i == 0){
			ans *= i - 1;
			m /= i;
			
			while(m % i == 0)
				m /= i, ans *= i;
		}
	
	if(m > 1)
		ans *= m - 1;
	printf("%lld\n", ans);
}

int main(){
	int cases;
	scanf("%d", &cases);
	
	while(cases--)
		solve();
	return 0;
}