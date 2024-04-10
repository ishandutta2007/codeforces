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
const LL INF = 1e18 + 17LL;

int n;
char s[N];

int main(){
	scanf("%d %s", &n, s + 1); int cnt = 0;
	for(int i = 1; i <= n; ++i)
		cnt += s[i] == '8';
	printf("%d\n", min(n / 11, cnt));
	return 0;
}