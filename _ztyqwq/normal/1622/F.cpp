#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
	int n;
	scanf("%d", &n);
	if(n == 1)
	{
		printf("1\n1\n");
		return 0;
	}
	if(n & 1)
	{
		ll prod = 1ll * n * ((n >> 1) - 1);
		ll s = sqrt(prod);
		if(s * s == prod)
		{
			printf("%d\n", n - 2);
			int s1 = (n >> 1) - 2, s2 = n - 2;
			for(int i = 1; i <= n; i++)
				if(i != s1 && i != s2)
					printf("%d ", i);
			putchar('\n');
			return 0;
		}
	}
	if(n & 1)
		n--;
	int m = n >> 1;
	if(m & 1)
	{
		int x = 0, k = (m + 1) >> 1, s = sqrt(k);
		if(s * s == k)
			x = m + 1;
		else if(m == 9)
			x = 7;
		if(x)
		{
			printf("%d\n", n - 1);
			for(int i = 1; i <= n; i++)
				if(i != x)
					printf("%d ", i);
			putchar('\n');
		}
		else
		{
			printf("%d\n", n - 2);
			for(int i = 1; i <= n; i++)
				if(i != 2 && i != m)
					printf("%d ", i);
			putchar('\n');
		}
	}
	else
	{
		printf("%d\n", n - 1);
		for(int i = 1; i <= n; i++)
			if(i != m)
				printf("%d ", i);
		putchar('\n');
	}
	return 0;
}