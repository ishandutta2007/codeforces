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

int n, k;
int cnt[N];
char s[N];

int main(){
	scanf("%d %d", &n, &k);
	scanf("%s", s + 1);
	
	for(int i = 1; i <= n; ++i)
		cnt[s[i]]++;
	
	int res = MX;
	for(int i = 0; i < k; ++i)
		res = min(res, cnt['A' + i]);
	printf("%d\n", res * k);
	return 0;
}