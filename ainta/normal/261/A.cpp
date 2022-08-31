#pragma warning(disable:4996)
#include<stdio.h>
#include<algorithm>
using namespace std;
int m, d=9999999;
int n, w[100010], Res;
int main()
{
	int i, pv;
	scanf("%d", &m);
	while (m--){
		scanf("%d", &i);
		if (d > i)d = i;
	}
	scanf("%d", &n);
	for (i = 1; i <= n; i++){
		scanf("%d", &w[i]);
		Res += w[i];
	}
	sort(w + 1, w + n + 1);
	pv = n;
	while (pv >= 1){
		pv -= d;
		if (pv < 1)break;
		if (pv == 1){
			Res -= w[pv];
			break;
		}
		Res -= (w[pv] + w[pv - 1]);
		pv -= 2;
	}
	printf("%d\n", Res);
}