#include <bits/stdc++.h>

using namespace std;

typedef double D;
typedef long long int LL;

#define st first
#define nd second
#define pb push_back
#define PLL pair <LL, LL>
#define PII pair <int, int>

const int N = 1e5 + 7;
const int MX = 1e9 + 7;
const LL INF = 1e18 + 9LL;

int n, m;
int cnt[N];

int main(){
	scanf("%d %d", &n, &m);
	for(int i = 0; i < m; ++i)
		cnt[(i * i)%m] += (n + m - (i == 0 ? m : i)) / m;
	
	LL res = 0LL;
	for(int i = 0; i < m; ++i)
		res += 1LL * cnt[i] * cnt[(m - i)%m];
	printf("%lld\n", res);
	return 0;
}