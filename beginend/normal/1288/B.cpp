#include<bits/stdc++.h>

typedef long long LL;

int main()
{
	int T;scanf("%d",&T);
	while (T--)
	{
		int a,b;scanf("%d%d",&a,&b);
		LL ans=0;
		for (int i=10;i<=(int)1e9;i*=10)
			if (i-1<=b) ans+=a;
		printf("%lld\n",ans);
	}
	return 0;
}