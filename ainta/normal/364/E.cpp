#pragma warning(disable:4996)
#include<stdio.h>
int n, m, K, S[2510][2510], p1[7], p2[7];
long long res;
char p[2510][2510];
int Sum(int ax, int ay, int bx, int by){
	return S[bx][by] - S[ax - 1][by] - S[bx][ay - 1] + S[ax - 1][ay - 1];
}
void Do(int ax, int ay, int bx, int by){
	int i, j, m, k;
	if ((bx - ax + 1)*(by - ay + 1) < K)return;
	if (ax == bx && ay == by){
		if (K == (p[ax][ay] == '1'))res++;
		return;
	}
	if (bx - ax>by - ay){
		m = (bx + ax) / 2;
		Do(ax, ay, m, by);
		Do(m + 1, ay, bx, by);
		for (i = ay; i <= by; i++){
			for (j = 0; j <= K; j++)p1[j] = ax, p2[j] = bx;
			for (j = i; j <= by; j++){
				for (k = 0; k <= K; k++){
					while (Sum(p1[k], i, m, j) > k)p1[k]++;
					while (Sum(m + 1, i, p2[k], j) > k)p2[k]--;
				}
				for (k = 1; k < K; k++)res += (p1[k - 1] - p1[k]) * (p2[K - k] - p2[K - k - 1]);
				if (!K)res += (m - p1[0] + 1)*(p2[0] - m);
				else res += (m - p1[0] + 1)*(p2[K] - p2[K - 1]) + (p2[0] - m)*(p1[K - 1] - p1[K]);
			}
		}
	}
	else{
		m = (by + ay) / 2;
		Do(ax, ay, bx, m);
		Do(ax, m + 1, bx, by);
		for (i = ax; i <= bx; i++){
			for (j = 0; j <= K; j++)p1[j] = ay, p2[j] = by;
			for (j = i; j <= bx; j++){
				for (k = 0; k <= K; k++){
					while (Sum(i, p1[k], j, m) > k)p1[k]++;
					while (Sum(i, m + 1, j, p2[k]) > k)p2[k]--;
				}
				for (k = 1; k < K; k++)res += (p1[k - 1] - p1[k]) * (p2[K - k] - p2[K - k - 1]);
				if (!K)res += (m - p1[0] + 1)*(p2[0] - m);
				else res += (m - p1[0] + 1)*(p2[K] - p2[K - 1]) + (p2[0] - m)*(p1[K - 1] - p1[K]);
			}
		}
	}
}
int main()
{
	int i, j;
	scanf("%d%d%d", &n, &m, &K);
	for (i = 1; i <= n; i++){
		scanf("%s", p[i] + 1);
		for (j = 1; j <= m; j++){
			S[i][j] = S[i - 1][j] + S[i][j - 1] - S[i - 1][j - 1];
			if (p[i][j] == '1')S[i][j]++;
		}
	}
	Do(1, 1, n, m);
	printf("%lld\n", res);
}