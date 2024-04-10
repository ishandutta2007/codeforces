#include<cstdio>
#include<algorithm>
using namespace std;
int n, w[60], vis[60], P[60], UF[60];
long long D[60], INF = 1e18+123, F[60];
int Find(int a) {
	if (a == UF[a])return a;
	return UF[a] = Find(UF[a]);
}
long long Calc(int m) {
	int i, cnt = 0, j;
	for (i = 1; i <= n; i++)vis[i] = 0;
	for (i = 1; i <= m; i++) {
		if (vis[w[i]])return 0ll;
		vis[w[i]] = 1;
		if (w[P[cnt]] < w[i]) {
			P[++cnt] = i;
		}
	}
	for (i = 1; i < cnt; i++) {
		if (w[P[i]] != P[i + 1] - 1)return 0ll;
	}
	for (i = 1; i <= n; i++)vis[i] = 0;
	for (i = 1; i < P[cnt]; i++) vis[w[i]] = 1;
	for (i = 1; i < P[cnt]; i++)if (!vis[i])return 0ll;
	int b = P[cnt], e = w[P[cnt]];
	for (i = 1; i <= n; i++)vis[i] = 0;
	if (e == m) return D[n - m];

	if (Find(m) == Find(w[m]))return 0ll;

	long long z1 = F[e - m - 1];
	long long z2 = D[n - e];
	if (z1 > INF / z2)return INF;
	return z1 * z2;
}
void Solve() {
	int i, j;
	long long K;
	scanf("%d%lld", &n, &K);
	if (D[n] < K) {
		puts("-1");
		return;
	}
	for (i = 1; i <= n; i++)w[i] = 0, UF[i] = i;
	for (i = 1; i <= n; i++) {
		for (j = 1; j <= n; j++) {
			w[i] = j;
			long long t = Calc(i);
			if (K > t) {
				K -= t;
				w[i] = 0;
			}
			else break;
		}
		int a = Find(i), b = Find(w[i]);
		UF[a] = b;
	}
	for (i = 1; i <= n; i++)printf("%d ", w[i]);
	puts("");
}
int main() {
	int i, j, TC, k;
	D[0] = 1;
	F[0] = 1;
	for (i = 1; i <= 50; i++) {
		if (F[i - 1] > INF / i) F[i] = INF;
		else F[i] = F[i - 1] * i;
		for (j = 0; j < i; j++) {
			long long t = D[j];
			for (k = 1; k <= i - j - 2; k++) {
				if (t > INF / k)t = INF;
				else t *= k;
			}
			D[i] = min(D[i] + t,INF);
		}
	}
	scanf("%d", &TC);
	while (TC--) {
		Solve();
	}
}