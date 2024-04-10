#include<cstdio>
#include<algorithm>
using namespace std;
long long w[51], S[51];
int n, K, E[51][51], v[51][51];
bool Pos(long long s) {
	int i, j;
	for (i = 0; i < n; i++)for (j = i + 1; j <= n; j++) {
		if (((S[j] - S[i])&s) == s) {
			E[i][j] = 1;
		}
		else E[i][j] = 0;
	}
	for (i = 0; i <= 50; i++)for (j = 0; j <= 50; j++)v[i][j] = 0;
	v[0][0] = 1;
	for (i = 0; i < K; i++) {
		for (j = 0; j < n; j++) {
			for (int k = j + 1; k <= n; k++) {
				if (v[i][j] && E[j][k])v[i + 1][k] = 1;
			}
		}
	}
	if (v[K][n])return true;
	return false;
}
int main() {
	int i;
	scanf("%d%d", &n, &K);
	for (i = 1; i <= n; i++) {
		scanf("%lld", &w[i]);
		S[i] = S[i - 1] + w[i];
	}
	long long s = 0;
	for (i = 60; i >= 0; i--) {
		if (Pos(s + (1ll << i)))s += (1ll << i);
	}
	printf("%lld\n", s);
}