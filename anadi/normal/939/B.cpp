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
const LL INF = 1e18 + 19LL;

LL k;
int n, t = 1;
LL best = 0LL, cnt = 0LL;

int main(){
	scanf("%lld %d", &k, &n);
	for(int i = 1; i <= n; ++i){
		LL a;
		scanf("%lld", &a);

		if((k / a) * a > best){
			best = (k / a) * a;
			t = i;
			cnt = k / a;
		}
	}
	
	printf("%d %lld\n", t, cnt);
	return 0;
}