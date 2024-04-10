#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
int n;
long long P1[1010000], P2[1010000], Mod = 998244353;
long long Pow(long long a, long long b) {
	long long r = 1;
	while (b) {
		if (b & 1)r = r * a%Mod;
		a = a * a%Mod; b >>= 1;
	}
	return r;
}
void Solve() {
	int i, K, a;
	long long sum = 0, cnt = 0;
	scanf("%d", &n);
	long long t2 = Pow(n, Mod - 2);
	for (i = 1; i <= n; i++) {
		scanf("%d", &K);
		cnt += K;
		long long t = Pow(K, Mod - 2);
		for (int j = 0; j < K; j++) {
			scanf("%d", &a);
			P1[a] = (P1[a] + t*t2) % Mod;
			P2[a] = (P2[a] + t2) % Mod;
		}
	}
	long long res = 0;
	for (i = 1; i <= 1000000; i++)res = (res + P1[i] * P2[i]) % Mod;
	printf("%lld\n", res);
}
int main() {
	int TC = 1;
	while (TC--) {
		Solve();
	}
}