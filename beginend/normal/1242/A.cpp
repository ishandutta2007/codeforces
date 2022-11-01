#include<bits/stdc++.h>

typedef long long LL;

LL n;

int main()
{
	scanf("%lld",&n);
	int p=0;
	for (int i=2;(LL)i*i<=n;i++)
		if (n%i==0)
		{
			p=i;
			break;
		}
	if (!p) printf("%lld\n",n);
	else
	{
		while (n%p==0) n/=p;
		if (n==1) printf("%d\n",p);
		else printf("%d\n",1);
	}
	return 0;
}