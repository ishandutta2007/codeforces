#pragma warning(disable:4996)
#include<stdio.h>
#define INF 999999999
long long D[2][150001], Deq[150001][2], n, m, i, j, tt[301], x, ed, h, t, L, a, b, tm, d, be;
long long  ab(long long a){ return a < 0 ? -a : a; }
int main()
{
	scanf("%lld%lld%lld", &n, &m, &d);
	for (i = 0; i < m; i++){
		x = !x;
		scanf("%lld%lld%lld", &a, &b, &tt[i]);
		if (i == 0){
			for (j = 1; j <= n; j++){
				D[x][j] = b - ab(a - j);
			}
			continue;
		}
		tm = tt[i] - tt[i - 1];
		h = 1, t = 0;
		L = tm * d;
		if (L > n)L = n;
		for (j = 1; j <= n + L; j++){
			if (h <= t && Deq[h][1] == j - 2 * L - 1)h++;
			if (j <= n){
				while (h <= t && Deq[t][0] <= D[!x][j])t--;
				Deq[++t][0] = D[!x][j];
				Deq[t][1] = j;
			}
			if (j >= L + 1){
				D[x][j - L] = Deq[h][0] + b - ab(a - (j - L));
			}
		}
	}
	long long Res = INF;
	Res = -Res*Res;
	for (i = 1; i <= n; i++){
		if (D[x][i] > Res)Res = D[x][i];
	}
	printf("%lld\n", Res);
}