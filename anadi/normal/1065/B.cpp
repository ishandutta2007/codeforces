#include <bits/stdc++.h>

using namespace std;

typedef double D;
typedef long long int LL;

#define st first
#define nd second
#define pb push_back
#define PLL pair <LL, LL>
#define PII pair <int, int>

const int N = 1e6 + 7;
const int MX = 1e9 + 7;
const LL INF = 1e18 + 9LL;

LL n, m;

int main(){
	scanf("%lld %lld", &n, &m);
	LL t = 0;
	while(t * (t - 1) / 2 < m)
		++t;

	printf("%lld %lld\n", max(0LL, n - 2 * m), n - t);
	return 0;
}