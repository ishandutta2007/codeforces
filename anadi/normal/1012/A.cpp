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

int n;
int a[N];

int main(){
	scanf("%d", &n);
	for(int i = 1; i <= n + n; ++i)
		scanf("%d", &a[i]);
	sort(a + 1, a + n + n + 1);
	
	LL res = 1LL * (a[n] - a[1]) * (a[n + n] - a[n + 1]);
	for(int i = 1; i <= n; ++i)
		res = min(res, 1LL * (a[n + i - 1] - a[i]) * (a[n + n] - a[1]));
	printf("%I64d\n", res);
	return 0;
}