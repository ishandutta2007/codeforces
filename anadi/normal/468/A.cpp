#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n; cin >> n;
	if (n % 2 == 0)
	{
		if (n < 4)
			puts("NO");
		else
		{
			puts("YES");
			printf("1 * 2 = 2\n2 * 3 = 6\n6 * 4 = 24\n");
			for (int i = 6; i <= n; i += 2)
				printf("%d - %d = 1\n24 * 1 = 24\n", i, i-1);
		}
	}
	else
	{
		if (n < 5)
			puts("NO");
		else
		{
			puts("YES");
			printf("1 * 2 = 2\n3 + 4 = 7\n7 + 5 = 12\n2 * 12 = 24\n");
			for (int i = 7; i <= n; i += 2)
				printf("%d - %d = 1\n24 * 1 = 24\n", i, i-1);
		}
	}
	return 0;	
}