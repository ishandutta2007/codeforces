#pragma warning(disable:4996)
#include<stdio.h>
#include<algorithm>
using namespace std;
int D[4][1001][1001];
int w[1001][1001];
int n, m, Q;
void make(int op, int p)
{
	int i, be, ed, ad, t = 0;
	if (op == 0) be = 1, ed = m + 1, ad = 1;
	if (op == 1) be = m, ed = 0, ad = -1;
	if (op == 2) be = 1, ed = n + 1, ad = 1;
	if (op == 3) be = n, ed = 0, ad = -1;
	for (i = be; i != ed; i += ad)
	{
		t++;
		if (op < 2){
			if (!w[p][i])t = 0;
			D[op][p][i] = t;
		}
		else
		{
			if (!w[i][p])t = 0;
			D[op][i][p] = t;
		}
	}
}
int Dap(int op, int x, int y)
{
	int M = D[op][x][y], r = 0;
	if (op < 2){
		int pv1 = x, pv2 = x;
		while (M){
			while (D[op][pv1 - 1][y] >= M)pv1--;
			while (D[op][pv2 + 1][y] >= M)pv2++;
			r = max(r, M * (pv2 - pv1 + 1));
			M--;
		}
		return r;
	}
	int pv1 = y, pv2 = y;
	while (M){
		while (D[op][x][pv1 - 1] >= M)pv1--;
		while (D[op][x][pv2 + 1] >= M)pv2++;
		r = max(r, M * (pv2 - pv1 + 1));
		M--;
	}
	return r;
}
int main()
{
	int i, j, op, x, y;
	scanf("%d%d%d", &n, &m, &Q);
	for (i = 1; i <= n; i++){
		for (j = 1; j <= m; j++){
			scanf("%d", &w[i][j]);
		}
	}
	for (i = 1; i <= n; i++){
		make(0,i);
		make(1,i);
	}
	for (i = 1; i <= m; i++){
		make(2,i);
		make(3,i);
	}
	while (Q--){
		scanf("%d%d%d", &op, &x, &y);
		if (op == 1){
			w[x][y] = 1 - w[x][y];
			make(0,x);
			make(1,x);
			make(2,y);
			make(3,y);
			continue;
		}
		printf("%d\n", max(max(Dap(0, x, y), Dap(1, x, y)), max(Dap(2, x, y), Dap(3, x, y))));
	}
}