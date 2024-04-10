#include <bits/stdc++.h>
using namespace std;
int a[101];
int main()
{
	int t;
	scanf("%d", &t);
	while(t--)
	{
		int n;
		scanf("%d", &n);
		
		for(int i = 1; i <= n; i++)
			scanf("%d", &a[i]);
		for(int i = 1; i <= n - 3; i += 2)
			printf("%d %d ", a[i + 1], -a[i]);
		if(n & 1)
		{
			int x = a[n - 1] - a[n - 2];
			if(x != 0)
				printf("%d %d %d\n", a[n], -a[n], x);
			else if(a[n] != 1)
				printf("%d %d %d\n", a[n] - 1, 1, -a[n - 1]);
			else
				printf("%d %d %d\n", 2, -1, -a[n - 1]);
		}
		else
			printf("%d %d\n", a[n], -a[n - 1]);
	}
	return 0;
}