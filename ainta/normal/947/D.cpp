#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
vector<int>A[3], B[3];
char p[101000], q[101000];
int n, m, U[2][101000], C[2][101000];
int main() {
	int i, Q;
	scanf("%s%s", p + 1, q + 1);
	scanf("%d", &Q);
	for (i = 1; p[i]; i++) {
		C[0][i] = C[0][i - 1];
		if (p[i] == 'A')U[0][i] = U[0][i - 1];
		else U[0][i] = i, C[0][i]++;
	}
	n = i - 1;
	for (i = 1; q[i]; i++) {
		C[1][i] = C[1][i - 1];
		if (q[i] == 'A')U[1][i] = U[1][i - 1];
		else U[1][i] = i, C[1][i]++;
	}
	m = i - 1;
	while (Q--) {
		int b1, e1, b2, e2;
		scanf("%d%d%d%d", &b1, &e1, &b2, &e2);
		int pv = U[1][e2];
		pv = max(pv, b2 - 1);
		if (pv < b2) {
			if (U[0][e1] < b1 && e1 - b1 + 1 >= e2 - b2 + 1 && (e1 - b1 + 1) % 3 == (e2 - b2 + 1) % 3) printf("1");
			else printf("0");
			continue;
		}
		int L = e2 - pv;
		if (e1 - b1 + 1 < L || e1 - U[0][e1] < L) {
			printf("0");
			continue;
		}
		e2 = pv;
		e1 -= L;
		if (e1 < b1) {
			printf("0");
			continue;
		}
		int t1 = C[0][e1] - C[0][b1 - 1];
		int t2 = C[1][e2] - C[1][b2 - 1];
		if (t1 == t2) {
			if ((e1 - U[0][e1]) % 3 != 0)printf("0");
			else printf("1");
			continue;
		}
		if (t1 % 2 == t2 % 2 && t1 <= t2) {
			printf("1");
		}
		else printf("0");
	}
}