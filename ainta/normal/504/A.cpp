#include<stdio.h>
int Deg[101000], n, XSum[101000], Q[101000], h, t, x;
int Ans[101000][2], cnt;
int main()
{
	int i, tp;
	scanf("%d", &n);
	for (i = 0; i < n; i++){
		scanf("%d%d", &Deg[i], &XSum[i]);
		if (Deg[i] == 1){
			Q[++t] = i;
		}
	}
	while (h < t){
		x = Q[++h];
		if (!Deg[x])continue;
		tp = XSum[x];
		Ans[cnt][0] = x;
		Ans[cnt][1] = tp;
		cnt++;
		Deg[x]--;
		Deg[tp]--;
		if (Deg[tp] == 1)Q[++t] = XSum[x];
		XSum[tp] ^= x;
		XSum[x] = 0;
	}
	printf("%d\n", cnt);
	for (i = 0; i < cnt; i++)printf("%d %d\n", Ans[i][0], Ans[i][1]);
}