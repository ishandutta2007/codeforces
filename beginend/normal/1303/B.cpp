#include<bits/stdc++.h>

typedef long long LL;

int main()
{
	int T;scanf("%d",&T);
	while (T--)
	{
		LL n,g,b;scanf("%lld%lld%lld",&n,&g,&b);
		if (g>=b||g*2>=n) printf("%lld\n",n);
		else
		{
			LL s=((n+1)/2+g-1)/g;
			printf("%lld\n",(n+1)/2+std::max(n/2,(s-1)*b));
		}
	}
	return 0;
}