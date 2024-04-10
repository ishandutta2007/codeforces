#pragma warning(disable:4996)
#include<stdio.h>
#include<algorithm>
using namespace std;
long long SX[1000100], SY[1000100], Res;
int n, m, w[1010][1010], K, P;
long long HX[1010], HY[1010], t;
int main()
{
	int i, j;
	scanf("%d%d%d%d", &n, &m, &K, &P);
	for (i = 1; i <= n; i++){
		for (j = 1; j <= m; j++){
			scanf("%d", &w[i][j]);
			HX[i] += w[i][j];
			HY[j] += w[i][j];
		}
	}
	make_heap(HX + 1, HX + n + 1);
	make_heap(HY + 1, HY + m + 1);
	for (i = 1; i <= K; i++){
		t = HX[1];
		pop_heap(HX + 1, HX + n + 1);
		SX[i] = SX[i - 1] + t;
		HX[n] = t - P*m;
		push_heap(HX + 1, HX + n + 1);
	}
	for (i = 1; i <= K; i++){
		t = HY[1];
		pop_heap(HY + 1, HY + m + 1);
		SY[i] = SY[i - 1] + t;
		HY[m] = t - P*n;
		push_heap(HY + 1, HY + m + 1);
	}
	for (i = 0; i <= K; i++){
		if (i == 0)Res = SX[i] + SY[K - i];
		else{
			Res = max(Res, SX[i] + SY[K - i] - (long long)P*i*(K - i));
		}
	}
	printf("%lld\n", Res);
}