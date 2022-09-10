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
	LL res = 0LL;
	
	if(n + n - 1 < m){
		puts("0");
		return 0;
	}
	
	LL from = max(1LL, m - n);
	LL to = (m - 1) / 2;
	printf("%lld\n", to - from + 1);
	return 0;
}