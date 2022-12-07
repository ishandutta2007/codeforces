#include <bits/stdc++.h>

using namespace std;

int gh;
long long c1, c2, c3, c4, c5, c6, x, y;

void solve()
{
	scanf("%lld %lld\n", &x, &y);
	scanf("%lld%lld%lld%lld%lld%lld", &c1, &c2, &c3, &c4, &c5, &c6);
	if(x==0)
	{
		if(y==0)
		{
			printf("0\n");
		}
		else if(y<0)
		{
			printf("%lld\n", min(c5*abs(y), (c4+c6)*abs(y)));
		}
		else
		{
			printf("%lld\n", min(c2*y, (c1+c3)*y));
		}
	}
	else if(x<0)
	{
		if(y==0)
		{
			printf("%lld\n", min(c3*abs(x), (c2+c4)*abs(x)));
		}
		else if(y<0)
		{
			x=abs(x);
			y=abs(y);
			if(x<y)
			{
				printf("%lld\n", min(x*c3+y*c5, min(x*c4+(y-x)*c5, y*c4+(y-x)*c6)));
			}
			else
			{
				printf("%lld\n", min(x*c3+y*c5, min(y*c4+(x-y)*c3, x*c4+(x-y)*c2)));
			}
		}
		else
		{
			x=abs(x);
			y=abs(y);
			printf("%lld\n", min(x*c3+y*c2, min(x*c4+(x+y)*c2, y*c1+(x+y)*c3)));
		}
	}
	else
	{
		if(y==0)
		{
			printf("%lld\n", min(c6*x, (c1+c5)*x));
		}
		else if(y<0)
		{
			x=abs(x);
			y=abs(y);
			printf("%lld\n", min(x*c6+y*c5, min(y*c4+(x+y)*c6, x*c1+(x+y)*c5)));
		}
		else
		{
			x=abs(x);
			y=abs(y);
			if(x<y)
			{
				printf("%lld\n", min(x*c6+y*c2, min(x*c1+(y-x)*c2, y*c1+(y-x)*c3)));
			}
			else
			{
				printf("%lld\n", min(x*c6+y*c2, min(y*c1+(x-y)*c6, x*c1+(x-y)*c5)));
			}
		}
	}
}

int main()
{
	scanf("%d", &gh);
	while(gh--)
	{
		solve();
	}
	return 0;
}