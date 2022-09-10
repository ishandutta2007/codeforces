#include <bits/stdc++.h>

using namespace std;

typedef double D;
typedef long long int LL;

#define st first
#define nd second
#define pb push_back
#define mp make_pair
#define PDD pair <D, D>
#define PLL pair <LL, LL>
#define PII pair <int, int>

const int N = 1e5 + 7;
const int MX = 1e9 + 7;
const int inf  = 1e9 + 9;

int l, r, x, y, k;

int main(){
	scanf("%d %d %d %d %d", &l, &r, &x, &y, &k);
	if(1LL * x * k <= r && 1LL * y * k >= l && l + k - (l%k == 0 ? k : l%k) <= r)
		puts("YES");
	else
		puts("NO");
	return 0;
}