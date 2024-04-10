#pragma warning(disable:4996)
#include<stdio.h>
int main()
{
	int n, p, i, j, t;
	scanf("%d", &t);
	while (t--){
		scanf("%d%d", &n, &p);
		p = 2 * n + p;
		for (i = 1; i * 2 < n; i++){
			for (j = 1; j <= n; j++){
				printf("%d %d\n", j, (j + i - 1) % n + 1);
				p--;
				if (!p)break;
			}
			if (!p)break;
		}
		for (i = 1; i <= n; i++){
			if (!p)break;
			j = (i + n / 2 - 1) % n + 1;
			printf("%d %d\n", i, j);
			p--;
		}
	}
	return 0;
}