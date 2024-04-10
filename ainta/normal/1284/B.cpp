#include<cstdio>
#include<algorithm>
using namespace std;
int n, st[101000], ed[101000], w[101000], chk[101000], S[1010000];
long long cnt;
int main() {
	int i, j;
	scanf("%d", &n);
	for (i = 1; i <= n; i++) {
		int K;
		scanf("%d", &K);
		for (j = 0; j < K; j++) {
			scanf("%d", &w[j]);
		}
		st[i] = w[0], ed[i] = w[K - 1];
		for (j = 1; j < K; j++) {
			if (w[j - 1] < w[j]) {
				chk[i] = 1;
			}
		}
		if (chk[i]) {
			cnt++;
		}
		else {
			S[st[i]]++;
		}
	}
	for (i = 1; i <= 1000000; i++)S[i] += S[i - 1];
	long long res = 0;
	for (i = 1; i <= n; i++) {
		if (!chk[i]) {
			res += S[ed[i]];
		}
	}
	res = 1ll*n * n - res;
	printf("%lld\n", res);
}