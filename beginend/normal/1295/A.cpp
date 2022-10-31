#include<bits/stdc++.h>

int a[10]={6,2,5,5,4,5,6,3,7,6},n;

int main()
{
	int T;scanf("%d",&T);
	while (T--)
	{
		scanf("%d",&n);
		if (n%2==0)
		{
			for (int i=1;i<=n/2;i++) putchar('1');
			puts("");
		}
		else
		{
			putchar('7');
			for (int i=1;i<n/2;i++) putchar('1');
			puts("");
		}
	}
	return 0;
}