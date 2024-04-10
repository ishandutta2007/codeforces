#include<bits/stdc++.h>

typedef long long LL;

int main()
{
	int T;scanf("%d",&T);
	while (T--)
	{
		int n,k;scanf("%d%d",&n,&k);
		if (n<k) puts("NO");
		else
		{
			n-=k;
			if ((LL)k*(k-1)<=(LL)n&&n%2==0) puts("YES");
			else puts("NO");
		}
	}
	return 0;
}