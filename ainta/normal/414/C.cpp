#pragma warning(disable:4996)
#include<stdio.h>
int n, m;
int w[1048577], TP[1048577], w2[1048577];
long long D[2098000], S[25], S2[25];
void DFS(int dep, int a, int rev, long long Gap){
	if (dep == n + 1){
		D[a] = Gap;
		return;
	}
	if (rev & 1){
		DFS(dep + 1, a, rev, Gap + S2[dep]);
		DFS(dep + 1, a + (1 << dep), rev + 1, Gap + S[dep]);
	}
	else{
		DFS(dep + 1, a, rev, Gap + S[dep]);
		DFS(dep + 1, a + (1 << dep), rev + 1, Gap + S2[dep]);
	}
}
int main()
{
	int i, j, T, pv1, pv2, ed1, ed2, c, cnt, T2, Q, r = 0;
	long long tp;
	scanf("%d", &n);
	m = 1 << n;
	for (i = 0; i < m; i++){
		scanf("%d", &w[i]);
	}
	for (i = 0; i < m; i++)w2[i] = w[m - i - 1];
	S[n] = 0;
	for (i = 1; i <= n; i++){
		T = 1 << i;
		T2 = 1 << (n - i);
		for (j = 0; j < m / T; j++){
			c = pv1 = j*T, pv2 = ed1 = j*T + T / 2, ed2 = j*T+T;
			cnt = 0;
			while (pv1 < ed1 && pv2 < ed2){
				if (w[pv1] <= w[pv2]){
					TP[c++] = w[pv1];
					S[n - i] += cnt;
					pv1++;
				}
				else {
					TP[c++] = w[pv2];
					cnt++, pv2++;
				}
			}
			while (pv1 < ed1){
				TP[c++] = w[pv1];
				S[n - i] += cnt;
				pv1++;
			}
			while (pv2 < ed2){
				TP[c++] = w[pv2];
				cnt++, pv2++;
			}
		}
		for (j = 0; j < m; j++)w[j] = TP[j];
	}
	S2[n] = 0;
	for (i = 1; i <= n; i++){
		T = 1 << i;
		T2 = 1 << (n - i);
		for (j = 0; j < m / T; j++){
			c = pv1 = j*T, pv2 = ed1 = j*T + T / 2, ed2 = j*T + T;
			cnt = 0;
			while (pv1 < ed1 && pv2 < ed2){
				if (w2[pv1] <= w2[pv2]){
					TP[c++] = w2[pv1];
					S2[n - i] += cnt;
					pv1++;
				}
				else {
					TP[c++] = w2[pv2];
					cnt++, pv2++;
				}
			}
			while (pv1 < ed1){
				TP[c++] = w2[pv1];
				S2[n - i] += cnt;
				pv1++;
			}
			while (pv2 < ed2){
				TP[c++] = w2[pv2];
				cnt++, pv2++;
			}
		}
		for (j = 0; j < m; j++)w2[j] = TP[j];
	}
	DFS(0, 0, 0, 0);
	scanf("%d", &Q);
	while (Q--){
		scanf("%d", &c);
		c = n - c;
		r ^= (1 << c);
		printf("%lld\n", D[r]);
	}
	return 0;
}