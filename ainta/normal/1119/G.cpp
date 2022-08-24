#include<cstdio>
#include<algorithm>
#include<vector>
#define N_ 1010000
using namespace std;
int m, n, w[N_], s, K, chk[N_], V[N_], c, Num[N_], P[N_];
vector<int>U[N_];
int main() {
	int i, j;
	scanf("%d%d", &n, &m);
	for (i = 1; i <= m; i++) {
		scanf("%d", &w[i]);
		s += w[i];
	}
	if (s%n) w[m] += n - s % n;
	s = 0;
	for (i = 1; i <= m; i++) {
		s += w[i];
		V[i] = s % n;
	}
	V[m] = n;
	sort(V, V + m + 1);
	for (i = 0; i < m; i++) {
		P[i] = V[i + 1] - V[i];
	}
	K = s / n;
	int t = 0, pv = 0;
	s = 0;
	for (i = 1; i <= m; i++) {
		s += w[i];
		while (t < s) {
			t += P[pv%m];
			U[pv%m].push_back(i);
			pv++;
		}
	}
	while (pv < m*K) {
		U[pv%m].push_back(m);
		pv++;
	}
	printf("%d\n", K);
	for (i = 0; i < m; i++)printf("%d ", P[i]);
	puts("");
	for (i = 0; i < K; i++) {
		for (int j = 0; j < m; j++) {
			printf("%d ", U[j][i]);
		}
		puts("");
	}
}