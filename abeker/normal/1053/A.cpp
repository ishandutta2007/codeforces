#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void out(int x, int y) {
	printf("%d %d\n", x, y);
}

int main() {
	int N, M, K;
	scanf("%d%d%d", &N, &M, &K);
	
	ll tot = (ll)2 * N * M;
	if (tot % K) {
		puts("NO");
		return 0;
	}
	
	puts("YES");
	
	int g1 = __gcd(2 * N, K);
	int g2 = __gcd(2 * M, K);
	
	if (g1 >= 2) {
		out(0, 0);
		out(2 * N / g1, 0);
		out(0, (ll)M * g1 / K);
		return 0;
	}
	
	out(0, 0);
	out((ll)N * g2 / K, 0);
	out(0, 2 * M / g2);
	
	return 0;
}