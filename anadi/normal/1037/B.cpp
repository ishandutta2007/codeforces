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

int n, s;
int in[N];

int main(){
	scanf("%d %d", &n, &s);
	for(int i = 1; i <= n; ++i)
		scanf("%d", &in[i]);
	sort(in + 1, in + n + 1);
	
	LL res = 0LL;
	for(int i = 1; i <= (n + 1) / 2; ++i)
		res += max(0, in[i] - s);
	for(int i = (n + 1) / 2; i <= n; ++i)
		res += max(0, s - in[i]);
	printf("%lld\n", res);
	return 0;
}