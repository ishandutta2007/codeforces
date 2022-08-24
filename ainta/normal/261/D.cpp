#pragma warning(disable:4996)
#include<stdio.h>
#include<algorithm>
using namespace std;
int T, n, m, w[501000];
int D[501000];
struct order{
	int a, num;
	bool operator<(const order &p)const{
		return a < p.a;
	}
}ord[501000];
int main()
{
	int maxb, i, cnt, j, k, x, Res = 0;
	scanf("%d%d%d%d", &T, &n, &maxb, &m);
	while (T--){
		for (i = 1; i <= n; i++){
			scanf("%d", &ord[i].a);
			ord[i].num = i;
		}
		sort(ord + 1, ord + n + 1);
		cnt = 0;
		for (i = 1; i <= n; i++){
			if (i == 1 || ord[i].a != ord[i - 1].a)++cnt;
			w[ord[i].num] = cnt;
		}
		if (cnt <= m){
			printf("%d\n", cnt);
			continue;
		}
		for (i = 1; i <= n; i++)D[i] = 0;
		for (i = 1; i <= m; i++){
			for (j = 1; j <= n; j++){
				x = w[j];
				if (D[x] < D[x - 1] + 1)D[x] = D[x - 1] + 1;
				while (x<cnt && D[x] > D[x + 1]){
					D[x + 1] = D[x];
					x++;
				}
			}
		}
		printf("%d\n", D[cnt]);
	}
}