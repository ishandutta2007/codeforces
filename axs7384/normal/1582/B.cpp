#include<bits/stdc++.h>
using namespace std;
int n,t;
int main()
{
	scanf("%d",&t);
	while (t--)
	{
		scanf("%d",&n);
		long long p0=0,p1=0;
		for (int i=1,x;i<=n;++i)
		{
			scanf("%d",&x);
			if (x==0)
				++p0;
			if (x==1)
				++p1;
		}
		p1<<=p0;
		printf("%lld\n",p1);
	}
	return 0;
}