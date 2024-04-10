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
		if(n == 1 || n == 2 || n == 4)
			printf("-1\n");
		else
		{
			if(n % 3 == 0)
				printf("%d 0 0\n", n / 3);
			else if(n % 3 == 1)
				printf("%d 0 1\n", n / 3 - 2);
			else
				printf("%d 1 0\n", n / 3 - 1);
		}
	}
	return 0;
}