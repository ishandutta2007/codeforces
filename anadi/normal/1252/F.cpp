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

LL n;
vector <LL> dv;

int main(){
	scanf("%lld", &n);
	for(LL i = 2; i * i <= n; ++i)
		if(n % i == 0){
			dv.push_back(i);
			dv.push_back(n / i);
		}
	
	LL ans = n;
	for(auto v: dv)
		ans = __gcd(ans, v);
	printf("%lld\n", ans);
	return 0;
}