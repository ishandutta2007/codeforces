#include<cstdio>
#include<algorithm>
#include<map>
using namespace std;
int S[201000];
map<int, int>Map;
int n, K, M;
int main() {
	int i, a;
	scanf("%d%d", &n,&K);
	M = (1 << K) - 1;
	for (i = 1; i <= n; i++) {
		scanf("%d", &a);
		S[i] = (S[i - 1] ^ a);
	}
	for (i = 0; i <= n; i++) {
		Map[min(S[i], S[i] ^ M)]++;
	}
	long long res = 0;
	res = 1ll * n*(n + 1) / 2;
	for (auto &t : Map) {
		long long c = t.second;
		long long c1 = c / 2, c2 = c - c / 2;
		res -= c1*(c1 - 1) / 2;
		res -= c2*(c2 - 1) / 2;
	}
	printf("%lld\n", res);
}