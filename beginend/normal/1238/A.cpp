#include<bits/stdc++.h>

typedef long long LL;

int main()
{
	int T;scanf("%d",&T);
	while (T--)
	{
		LL x,y;
		scanf("%lld%lld",&x,&y);
		if (x==y+1) puts("NO");
		else puts("YES");
	}
	return 0;
}