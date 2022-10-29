#include <stdio.h>

int main(void)
{
	int n, m;
	scanf("%d %d", &n, &m);
	for(int i = 1; i < 4000000; i++)
	{
		if(i % 2 == 0 && i % 3 == 0 && (n != 0 && m != 0))
		{
			if(2*n > 3*m)
				n--;
			else
				m--;
		}
		else if(i % 2 == 0 && n != 0)
			n--;
		else if(i % 3 == 0 && m != 0)
			m--;
		if(n == 0 && m == 0)
		{
			printf("%d\n", i);
			return 0;
		}
	}
}