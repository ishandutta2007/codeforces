#include <bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	scanf("%d", &t);
	while(t--)
	{
		int n, k;
		scanf("%d %d", &n, &k);
		if(n % 2 == 1 && k % 2 == 0)
			printf("NO\n");
		else
		{
			if(n % 2 == k % 2)
			{
				if(n < k)
					printf("NO\n");
				else
				{
					printf("YES\n");
					for(int i = 1; i < k; i++)
						printf("1 ");
					printf("%d\n", n - (k - 1));
				}
			}
			else
			{
				if(n < 2 * k)
					printf("NO\n");
				else
				{
					printf("YES\n");
					for(int i = 1; i < k; i++)
						printf("2 ");
					printf("%d\n", n - 2 * (k - 1));
				}
			}
		}
	}
	return 0;
}