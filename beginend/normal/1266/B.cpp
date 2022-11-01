#include<bits/stdc++.h>

typedef long long LL;

int n;

bool check(LL x)
{
	for (int i=15;i<=20;i++)
		if (i<=x&&(x-i)%14==0) return 1;
	return 0;
}

int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	{
		LL x;scanf("%lld",&x);
		if (check(x)) puts("YES");
		else puts("NO");
	}
	return 0;
}