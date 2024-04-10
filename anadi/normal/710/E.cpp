#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;
typedef double D;

#define PII pair <int, int>
#define PLL pair <LL, LL>
#define PDD pair <D, D>
#define pb push_back
#define mp make_pair
#define nd second
#define st first

const int N = 2e7 + 7;
const LL INF = 1e18 + 7LL;

int n, x, y;
LL d[N];

int main(){
	scanf("%d %d %d", &n, &x, &y);
	d[1] = x;
	d[2] = x + min(x, y);
	
	for(int i = 3; i <= n; i += 2){
		d[i + 1] = d[(i + 1) / 2] + y;
		d[i] = min(d[i - 1], d[i + 1]) + x;
		d[i + 1] = min(d[i + 1], d[i] + x);
	}
	
	printf("%I64d\n", d[n]);
	return 0;
}