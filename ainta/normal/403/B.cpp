#pragma warning(disable:4996)
#include<stdio.h>
int p[10010], n, m, cnt, w[10010], score[10010], Res, b[10010], inp[10010];
int gcd(int a, int b){
	return b ? gcd(b, a%b) : a;
}
int Gap(int a){
	int i, c = 0;
	for (i = 0; p[i] * p[i] <= a; i++){
		while (a%p[i] == 0){
			a /= p[i];
			c += score[i];
		}
	}
	if (a != 1){
		for (i = 0; i < m; i++){
			if (b[i] == a)break;
		}
		if (i == m) c++;
		else c--;
	}
	return c;
}
int main()
{
	int i, j, G, a, pv = 0, M = 0;
	scanf("%d%d", &n, &m);
	for (i = 2; i <= 32000; i++){
		for (j = 2; j*j <= i; j++)if (i%j == 0)break;
		if (j*j > i)p[cnt++] = i;
	}
	for (i = 1; i <= n; i++){
		scanf("%d", &inp[i]);
	}
	for (i = 0; i < cnt; i++)score[i] = 1;
	for (i = 0; i < m; i++){
		scanf("%d", &a);
		b[i] = a;
		while (p[pv] < a && pv < cnt)pv++;
		if (pv < cnt)score[pv] = -1;
	}
	for (i = 1; i <= n; i++){
		a = inp[i];
		if (i == 1)G = a;
		else G = gcd(a, G);
		Res += Gap(a);
		w[i] = Gap(G);
	}
	for (i = n; i >= 1; i--){
		if (M > w[i])M = w[i];
		Res -= M;
	}
	printf("%d\n", Res);
}