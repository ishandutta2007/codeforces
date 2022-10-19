#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#ifdef DEBUG
	#define D(x...) printf(x)
#else
	#define D(x...)
#endif
int a[1000000];

int main()
{
	int t;
	scanf("%d", &t);
	for (int i = 0; i < t; i++)
	{
		int n;
		scanf("%d", &n);
		for (int i = 0; i < n; i++)
		{
			scanf("%d", &a[i]);
		}
		int mn = 0;
		int g = 0;
		for (int i = 0; i < n-1; i++)
		{
			g++;
			if (a[i] != a[i+1]) break;
		}
		int s = 0;
		for (int i = g; i < n-1; i++)
		{
			s++;
			if (s > g && a[i] != a[i+1]) break;
		}
		int b = 0;
		for (int i = g+s; i < n-1; i++)
		{
			b++;
			if (a[i] != a[i+1] && b > g && 2*(g+b+s) <= n) 
			{
				mn = b;
			}
		}
		if (mn > g)
		{
			printf("%d %d %d\n", g, s, mn);
		}
		else printf("0 0 0\n");
	}
}