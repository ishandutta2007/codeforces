#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
int n, K, P[2010], w[2010], chk[2010], bef = -1;
int main() {
	int i, a, b, turn;
	scanf("%d%d", &n, &K);
	for (i = 1; i <= 2*n; i++) {
		scanf("%d", &w[i]);
	}
	for (i = 0; i < K; i++) {
		scanf("%d%d", &a, &b);
		P[a] = b, P[b] = a;
	}
	scanf("%d", &turn);
	n *= 2;
	for (int T = 0; T < n; T++) {
		if (turn == 2) {
			scanf("%d", &a);
			chk[a] = 1;
			bef = a;
			turn = 1;
			continue;
		}
		else {
			turn = 2;
			if (bef != -1 && P[bef] && !chk[P[bef]]) {
				printf("%d\n", P[bef]);
				fflush(stdout);
				chk[P[bef]] = 1;
				continue;
			}
			int ck = 0;
			for (i = 1; i <= n; i++) {
				if (P[i] && !chk[i] && (w[i] >= w[P[i]])) {
					printf("%d\n", i);
					fflush(stdout);
					chk[i] = 1;
					ck = 1;
					break;
				}
			}
			if (!ck) {
				int Mx = -1, pv = -1;
				for (i = 1; i <= n; i++){
					if (!chk[i] && Mx < w[i]) {
						Mx = w[i];
						pv = i;
					}
				}
				printf("%d\n", pv);
				fflush(stdout);
				chk[pv] = 1;
			}
		}
	}
}