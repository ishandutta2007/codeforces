#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int N, M;

int get(int rem) {
	return N / M + (rem >= 1 && rem <= N % M);
}

int main() {
	scanf("%d%d", &N, &M);
	
	ll ans = 0;
	for (int i = 0; i < M; i++)
		for (int j = 0; j < M; j++) {
			if ((i * i + j * j) % M)
				continue;
			ans += (ll)get(i) * get(j);
		}
		
	printf("%lld\n", ans);
	
	return 0;
}