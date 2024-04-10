#include<cstdio>
#include<algorithm>
#include<map>
#include<set>
using namespace std;
long long P[71][71], U[31][71][71], D[71], TD[71];
int Next[71][9], Num[256], ReNum[71];
int m, K, L, n, cost[10], cnt;
map<int, int>CC;
set<int>Set;
void Make(long long(*A)[71], long long(*B)[71], long long(*C)[71]) {
	int i, j, k;
	for (i = 1; i <= cnt; i++)for (j = 1; j <= cnt; j++)C[i][j] = -1;
	for (i = 1; i <= cnt; i++) {
		for (k = 1; k <= cnt; k++) {
			for (j = 1; j <= cnt; j++) {
				if (A[i][k] == -1 || B[k][j] == -1)continue;
				if (C[i][j] == -1 || C[i][j] > A[i][k] + B[k][j])C[i][j] = A[i][k] + B[k][j];
			}
		}
	}
}
void Go(int T) {
	int i, j, k;
	for (i = 0; i <= 30; i++) {
		if ((T >> i) & 1) {
			for (j = 1; j <= cnt; j++)TD[j] = 1e18;
			for (j = 1; j <= cnt; j++) {
				for (k = 1; k <= cnt; k++) {
					if (U[i][j][k] == -1)continue;
					TD[k] = min(TD[k], D[j] + U[i][j][k]);
				}
			}
			for (j = 1; j <= cnt; j++)D[j] = TD[j];
		}
	}
}
int main() {
	int i, j, a, b, k;
	scanf("%d%d%d%d", &m, &K, &L, &n);
	for (i = 1; i <= K; i++) {
		scanf("%d", &cost[i]);
	}
	for (i = 0; i < n; i++) {
		scanf("%d%d", &a, &b);
		CC[a] = b;
		for (j = max(a - K, 1); j <= min(a, L - m + 1); j++)Set.insert(j);
	}
	Set.insert(1);
	Set.insert(L - m + 1);
	for (i = 0; i < (1 << K); i++) {
		int c = 0;
		for (j = 0; j < K; j++)if ((i >> j) & 1)c++;
		if (c != m)continue;
		Num[i] = ++cnt;
		ReNum[cnt] = i;
	}
	for (i = 1; i <= cnt; i++)for (j = 1; j <= cnt; j++)P[i][j] = -1;
	for (i = 1; i <= cnt; i++) {
		int x = ReNum[i];
		if (x & 1) {
			for (j = 1; j <= K; j++) {
				if ((x >> j) & 1)continue;
				Next[i][j] = Num[(x + (1 << j)) >> 1];
				P[i][Next[i][j]] = cost[j];
			}
		}
		else {
			P[i][Num[x >> 1]] = 0;
		}
	}
	for (i = 1; i <= cnt; i++)for (j = 1; j <= cnt; j++)U[0][i][j] = P[i][j];
	for (i = 1; i <= 30; i++)Make(U[i-1], U[i-1], U[i]);
	for (i = 1; i <= cnt; i++)D[i] = 1e18;
	D[1] = 0;
	int cur = 1;
	for (auto &tp : Set) {
		if (tp == cur)continue;
		if (tp > cur + 30) {
			Go(tp - cur);
			cur = tp;
			continue;
		}
		for (i = cur; i < tp; i++) {
			for (j = 1; j <= cnt; j++)TD[j] = 1e18;
			for (j = 1; j <= cnt; j++) {
				int x = ReNum[j];
				if (x & 1) {
					for (k = 1; k <= K; k++) {
						if ((x >> k) & 1)continue;
						int t = Num[(x + (1 << k)) >> 1];
						TD[t] = min(TD[t], D[j] + cost[k] + CC[i + k]);
					}
				}
				else {
					int t = Num[x >> 1];
					TD[t] = min(TD[t], D[j]);
				}
			}
			for (j = 1; j <= cnt; j++)D[j] = TD[j];
		}
		cur = tp;
	}
	printf("%lld\n", D[1]);
}