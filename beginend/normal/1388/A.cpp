#include<bits/stdc++.h>
using namespace std;

int main()
{
	int a[4] = {6, 10, 14, 15};
	int T; scanf("%d", &T);
	while (T--)
	{
		int n; scanf("%d", &n);
		if (n > 30 && n - 30 != 6 && n - 30 != 10 && n - 30 != 14)
		{
			puts("YES");
			printf("%d %d %d %d\n", 6, 10, 14, n - 30);
		}
		else if (n > 35 && n - 35 != 6 && n - 35 != 14 && n - 30 != 15)
		{
			puts("YES");
			printf("%d %d %d %d\n", 6, 15, 14, n - 35);
		}
		else if (n > 39 && n - 39 != 10 && n - 39 != 14 && n - 39 != 15)
		{
			puts("YES");
			printf("%d %d %d %d\n", 15, 10, 14, n - 39);
		}
		else if (n > 31 && n - 31 != 6 && n - 31 != 10 && n - 31 != 15)
		{
			puts("YES");
			printf("%d %d %d %d\n", 6, 10, 15, n - 31);
		}
		else puts("NO");
	}
	return 0;
}