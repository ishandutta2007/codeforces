#include <stdio.h>

int a[1123456];

int main(void)
{
	int n, q, x, y;
	scanf("%d %d", &n, &q);
	for(int i = (1 << n); i < (1 << (n+1)); i++)
		scanf("%d", &a[i]);

	for(int j = n-1; j >= 0; j--)
		for(int i = (1 << j); i < (1 << (j+1)); i++)
		{
			if((n-j) % 2 == 1)
				a[i] = (a[2*i+1] | a[2*i]);
			else
				a[i] = (a[2*i+1] ^ a[2*i]);
		}
	while(q--)
	{
		scanf("%d %d", &x, &y);
		x = (1 << n) + x - 1;
		a[x] = y;
		for(int j = n-1; j >= 0; j--)
		{
			x >>= 1;
			if((n-j) % 2 == 1)
				a[x] = (a[2*x+1] | a[2*x]);
			else
				a[x] = (a[2*x+1] ^ a[2*x]);
		}
		printf("%d\n", a[1]);
	}
}