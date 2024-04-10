#include<cstdio>
#include<algorithm>
#include<string>
using namespace std;
int inp[1510], w[1510], n, K, P[1510], m, s, chk[1510], D[1510][1510], S[1510];
struct point {
	int b, e;
	bool operator<(const point &p)const {
		return b != p.b ? b < p.b : e>p.e;
	}
}A[1510];
bool Pos(int M) {
	int i, j;
	for (i = 1; i <= n; i++) {
		if (inp[i] <= M)w[i] = 1;
		else w[i] = 0;
		S[i] = S[i - 1] + w[i];
	}
	for (i = 0; i <= s; i++)for (j = 0; j <= s; j++)D[i][j] = 0;
	for (i = 1; i <= s; i++) {
		for (j = i; j >= 1; j--)if (A[j].e < A[i].b)break;
		int pv = j;
		for (j = 0; j <= i; j++)D[i][j] = D[i - 1][j];
		for (j = 0; j <= pv; j++)D[i][j + 1] = max(D[i][j + 1], D[pv][j] + S[A[i].e] - S[A[i].b - 1]);
		for (j = 0; j <= pv + 1; j++)D[i][j + 1] = max(D[i][j + 1], D[pv + 1][j] + S[A[i].e] - S[A[pv + 1].e]);
	}
	int r = 0;
	for (i = 1; i <= m; i++)r = max(r, D[s][i]);
	return r >= K;
}
int main() {
	int i, j;
	scanf("%d%d%d%d", &n,&s,&m, &K);
	for (i = 1; i <= n; i++) {
		scanf("%d", &inp[i]);
		P[i] = inp[i];
	}
	sort(P + 1, P + n + 1);
	for (i = 1; i <= s; i++) {
		scanf("%d%d", &A[i].b, &A[i].e);
	}
	sort(A + 1, A + s + 1);
	for (i = 1; i <= s; i++) {
		for (j = 1; j < i; j++) {
			if (A[i].e <= A[j].e)chk[i] = 1;
		}
	}
	int cnt = 0;
	for (i = 1; i <= s; i++) { if (!chk[i])A[++cnt] = A[i]; }
	s = cnt;
	m = min(m, s);
	int b = 1, e = n, mid, r = -1;
	while (b <= e) {
		mid = (b + e) >> 1;
		if (Pos(P[mid])) {
			r = P[mid];
			e = mid - 1;
		}
		else b = mid + 1;
	}
	printf("%d\n", r);
}