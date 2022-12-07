#include <bits/stdc++.h>

using namespace std;

int n, odp=1e9;
int t[100001];

int main()
{
	scanf("%d", &n);
	for(int i=1; i<=n; ++i)
	{
		scanf("%d", &t[i]);
	}
	for(int i=1; i<=n-2; ++i)
	{
		if(__builtin_clz(t[i])==__builtin_clz(t[i+1]) && __builtin_clz(t[i])==__builtin_clz(t[i+2]))
		{
			printf("1\n");
			return 0;
		}
	}
	for(int i=1; i<=n-1; ++i)
	{
		int x=0;
		for(int j=i; j; --j)
		{
			x^=t[j];
			int y=0;
			for(int k=i+1; k<=n; ++k)
			{
				y^=t[k];
				if(x>y)
				{
					odp=min(odp, k-j-1);
				}
			}
		}
	}
	if(odp==1e9)
	{
		printf("-1\n");
		return 0;
	}
	printf("%d\n", odp);
	return 0;
}