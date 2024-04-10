#pragma warning(disable:4996)
#include<stdio.h>
#include<algorithm>
using namespace std;
int w[2010][3], n, H;
bool v[2010];
int Gap(int pv){
	int i, hh = H, R = 0, x, M;
	for (i = 1; i <= n; i++)v[i] = false;
	for (;;)
	{
		M = -1;
		for (i = 1; i <= n; i++){
			if (!v[i] && pv == w[i][0] && hh >= w[i][1]){
				if (M < w[i][2]){
					M = w[i][2];
					x = i;
				}
			}
		}
		if (M == -1)break;
		hh += M;
		v[x] = true;
		pv = !pv;
		R++;
	}
	return R;
}
int main()
{
	int i, t1, t2;
	scanf("%d%d", &n, &H);
	for (i = 1; i <= n; i++){
		scanf("%d%d%d", &w[i][0], &w[i][1], &w[i][2]);
	}
	t1 = Gap(0);
	t2 = Gap(1);
	if (t1 < t2)t1 = t2;
	printf("%d\n", t1);
}