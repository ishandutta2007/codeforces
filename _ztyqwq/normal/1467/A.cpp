#include <bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	scanf("%d", &t);
	while(t--)
	{
		int n;
		scanf("%d", &n);
		if(n == 1)
			printf("9\n");
		else
		{
			printf("98");
			for(int i = 3, j = 9; i <= n; i++, j = (j + 1) % 10)
				printf("%d", j);
			putchar('\n');
		}
	}
	return 0;
}