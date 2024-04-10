#pragma warning(disable:4996)
#include<stdio.h>
#include<algorithm>
using namespace std;
int w[100010], i, n, ck;
long long Res, G[100010], S;
int main()
{
	scanf("%d", &n);
	n--;
	for (i = 1; i <= n; i++){
		scanf("%d", &w[i]);
	}
	S = 0;
	for (i = n; i >= 1; i--){
		if (w[i] == 1)ck = 1;
		S += w[i] / 2 * 2;
		G[i] = G[i + 1] + (w[i] + 1) / 2 * 2 - 1;
		if (!ck && G[i] < S) G[i] = S;
	}
	S = 0;
	for (i = 0; i <= n; i++){
		Res = max(Res, S + G[i + 1]);
		if (i == n)break;
		S += w[i + 1] / 2 * 2;
		if (w[i + 1] == 1)S = 0;
	}
	printf("%lld\n", Res);
}