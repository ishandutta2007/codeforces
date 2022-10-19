#include<bits/stdc++.h>
using namespace std;
long long x;
int n,y;
int main()
{
	int t;
	scanf("%d",&t);
	while (t--)
	{
		x=1;
		scanf("%d",&n);
		bool b=1;
		for (int i=1;i<=n;++i)
		{
			scanf("%d",&y);
			if (i<=25)
			{
				long long tmp=__gcd(x,(long long)i+1);
				x*=(i+1)/tmp;
				if (y%x==0)
					b=0;
			}
		}
		puts(b?"YES":"NO");
	}
	return 0;
}