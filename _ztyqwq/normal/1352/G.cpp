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
		if(n <= 3)
			printf("-1\n");
		else
		{
			for(int i = n - n % 2; i >= 6; i -= 2)
				printf("%d ", i);
			printf("3 1 4 2 ");
			for(int i = 5; i <= n; i += 2)
				printf("%d ", i);
			putchar('\n');
		}
	}
	return 0;
}