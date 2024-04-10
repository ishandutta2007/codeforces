#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int derange[] = {1, 0, 1, 2, 9};

int N, K;

ll choose(int k) {
	ll res = 1;
	for (int i = 0; i < k; i++)
		res *= N - i;
	for (int i = 1; i <= k; i++)
		res /= i;
	return res;
}

int main() {
	scanf("%d%d", &N, &K);
	ll sol = 0;
	for (int i = 0; i <= K; i++)
		sol += choose(i) * derange[i];
	printf("%lld\n", sol);
	return 0;
}