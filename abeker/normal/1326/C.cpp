#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAXN = 2e5 + 5;
const int MOD = 998244353;

int main() {
	int N, K;
	scanf("%d%d", &N, &K);
	
	ll sum = 0;
	int lst = 0, ways = 1;	
	for (int i = 1; i <= N; i++) {
		int x;
		scanf("%d", &x);
		if (x >= N - K + 1) {
			sum += x;
			if (lst)
				ways = (ll)ways * (i - lst) % MOD;
			lst = i;
		}
	}
	
	printf("%lld %d\n", sum, ways);
	
	return 0;
}