#include <bits/stdc++.h>

using namespace std;

typedef long double T;
typedef long long int LL;

#define st first
#define nd second
#define PLL pair <LL, LL>
#define PII pair <int, int>

const int N = 1e6 + 7;
const int MX = 1e9 + 7;
const LL INF = 1LL * MX * MX;

int n;
int in[N];
int cnt[N];

int main(){
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i){
		scanf("%d", &in[i]);
		for(int p = 1; p * p <= in[i]; ++p)
			if(in[i] % p == 0){
				cnt[p]++;
				if(in[i] != p * p)
					cnt[in[i] / p]++;
			}
	}

	LL ans = 1;
	for(int i = 2; i < N; ++i)
		if(cnt[i] >= n - 1){
//			printf("%d ", i);
			ans = ans * i / __gcd(ans, 1LL * i);
		}
	
	printf("%lld\n", ans);
	return 0;
}