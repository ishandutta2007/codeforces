#include <bits/stdc++.h>

using namespace std;

typedef double D;
typedef long long int LL;

#define st first
#define nd second
#define pb push_back
#define PLL pair <LL, LL>
#define PII pair <int, int>

const int N = 2007;
const int MX = 1e9 + 7;
const LL INF = 1e18 + 17LL;

int n, m, x;
int a[N], b[N];
int mn[N], mn2[N];

int main(){
	scanf("%d %d", &n, &m);
	for(int i = 1; i <= n; ++i)
		scanf("%d", &a[i]);
	for(int i = 1; i <= m; ++i)
		scanf("%d", &b[i]);
	scanf("%d", &x);
	
	int res = 0;
	for(int i = 1; i <= n || i <= m; ++i)
		mn[i] = mn2[i] = MX;
	
	for(int i = 1; i <= n; ++i){
		int s = 0;
		for(int j = i; j <= n; ++j)
			s += a[j], mn[j - i + 1] = min(mn[j - i + 1], s);
	}

	for(int i = 1; i <= m; ++i){
		int s = 0;
		for(int j = i; j <= m; ++j)
			s += b[j], mn2[j - i + 1] = min(mn2[j - i + 1], s);
	}
	
	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= m; ++j)
			if(1LL * mn[i] * mn2[j] <= x)
				res = max(res, i * j);
	printf("%d\n", res);
	return 0;
}