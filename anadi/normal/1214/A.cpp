#include <bits/stdc++.h>

using namespace std;

typedef double D;
typedef long long int LL;

#define st first
#define nd second
#define PLL pair <LL, LL>
#define PII pair <int, int>

const int N = 1e6 + 7;
const int MX = 1e9 + 7;
const LL INF = 1LL * MX * MX;

int main(){
	int n, d, e;
	cin >> n >> d >> e;
	e *= 5;
	
	if(n < N){
		int ans = n;
		for(int i = 0; i * d <= n; ++i)
			ans = min(ans, (n - i * d) % e);
		printf("%d\n", ans);
		return 0;
	}
	
	int dv = __gcd(d, e);
	printf("%d\n", n % dv);
	return 0;
}