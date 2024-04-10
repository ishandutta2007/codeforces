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

int main(){
	LL a, b, c;
	cin >> a >> b >> c;
	
	LL ans = 0;
	if(b > a)
		ans = 2 * c + (a + a + 1);
	else if(a == b)
		ans = 2 * c + b + b;
	else
		ans = 2 * c + b + b + 1;
	printf("%lld\n", ans);
	return 0;
}