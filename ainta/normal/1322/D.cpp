#include<cstdio>
#include<algorithm>
#include<vector>
#define N_ 4010
#define pii pair<int,int>
using namespace std;
int n, m, w[N_], cost[N_], O[20];
long long G[N_], S[N_], D[N_][4096], MM[N_];
void UDT(int a, int b, long long c) {
	if (D[a][b] < c)D[a][b] = c;
	if (MM[a] < c)MM[a] = c;
}
int main() {
	int n, m, i, j;
	for (i = 0; i < N_; i++)for (j = 0; j < 4096; j++)D[i][j] = -1e15;
	scanf("%d%d", &n, &m);
	for (i = 1; i <= n; i++) {
		scanf("%d", &w[i]);
	}
	for (i = 1; i <= n; i++) {
		scanf("%d", &cost[i]);
	}
	for (i = 1; i <= n + m; i++) {
		scanf("%lld", &G[i]);
		S[i] = S[i - 1] + G[i];
	}
	UDT(0, 1, 0);
	for (i = n; i >= 1; i--) {
		int x = w[i];
		for (j = x; j >= x-11&&j>=0; j--) {
			for (int k = 4095; k >= 0; k--) {
				long long t = D[j][k] + G[x] - cost[i];
				if (t < -1e14)continue;
				for (int l = 0; l < 15; l++)O[l] = 0;
				for (int l = 0; l < 12; l++) {
					if ((k >> l) & 1)O[l] = 1;
				}
				O[x - j]++;
				for (int l = x - j; l < 13; l++) {
					if (O[l] != 2)break;
					O[l] = 0;
					O[l + 1]++;
					t += G[j + l + 1];
				}
				int mask = 0;
				for (int l = x - j; l < 13; l++) {
					if (O[l]) mask |= 1 << (l - x + j);
				}
				UDT(x, mask, t);
			}
		}
		long long t = 0;
		for (j = 0; j <= x - 12; j++) {
			t = max(t, MM[j]);
		}
		UDT(x, 1, t + G[x] - cost[i]);
	}
	long long res = 0;
	for (i = 0; i <= n + m; i++)res = max(res, MM[i]);
	printf("%lld\n", res);
}