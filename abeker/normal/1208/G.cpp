#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e6 + 5;

int N, K;
int phi[MAXN];
	
int main() {
	scanf("%d%d", &N, &K);
	
	if (K == 1) {
		puts("3");
		return 0;
	}
	
	for (int i = 1; i <= N; i++) {
		phi[i] += i;
		for (int j = 2 * i; j <= N; j += i)
			phi[j] -= phi[i];
	}
	
	sort(phi + 3, phi + N + 1);
	
	long long ans = 2;
	for (int i = 0; i < K; i++)
		ans += phi[i + 3];
	
	printf("%lld\n", ans);
	
	return 0;
}