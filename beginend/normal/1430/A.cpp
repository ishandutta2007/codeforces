#include<bits/stdc++.h>
using namespace std;

int main()
{
	int T; scanf("%d", &T);
	while (T--)
	{
		int n; scanf("%d", &n);
		if (n % 3 == 0) printf("%d %d %d\n", n / 3, 0, 0);
		else if (n % 3 == 1)
		{
			if (n < 7) puts("-1");
			else printf("%d %d %d\n", (n - 7) / 3, 0, 1);
		}
		else
		{
			if (n < 5) puts("-1");
			else printf("%d %d %d\n", (n - 5) / 3, 1, 0);
		}
	}
	return 0;
}