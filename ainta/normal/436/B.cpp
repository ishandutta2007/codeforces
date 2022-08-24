#pragma warning(disable:4996)
#include<stdio.h>
char p[2010];
int n, m, w[2010], k;
int main()
{
	int i, j;
	scanf("%d%d%d", &n, &m, &k);
	for (i = 0; i < n; i++){
		scanf("%s", p);
		for (j = 0; j < m; j++){
			if (p[j] == 'L'){
				if (j>=i)w[j - i]++;
			}
			if (p[j] == 'R'){
				if (j + i < m)w[j + i]++;
			}
			if (p[j] == 'U'){
				if (i % 2 == 0)w[j]++;
			}
			if (p[j] == 'D'){
				if (i == 0)w[j] += n;
			}
		}
	}
	for (i = 0; i < m; i++)printf("%d ", w[i]);
}