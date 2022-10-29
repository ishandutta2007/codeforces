#include <stdio.h>

int a[112][112];
int b[112];
int ans[112];

int
main(void)
{
	int n, m = 0;
	scanf("%d ", &n);
	for(int i = 0; i < n; getchar(), i++)
		for(int j = 0; j < n; j++)
			a[i][j] = getchar() - '0';
	for(int i = 0; i < n; i++)
		scanf("%d", &b[i]);
	for(int k = 0; k < n; k++)
	for(int i = 0; i < n; i++)
	{
		if(b[i] == 0)
		{
			ans[m++] = i + 1;
			for(int j = 0; j < n; j++)
				if(a[i][j])
					b[j]--;
			break;
		}
	}
	printf("%d\n", m);
	for(int i = 0; i < m; i++)
		printf("%d\n", ans[i]);
}