#include<bits/stdc++.h>
using namespace std;
#define ll long long
int t,ans;
ll x,y;
int main()
{
	scanf("%d",&t);
	while (t--)
	{
		scanf("%lld",&x);
		y=205000000000000000;
		ans=0;
		while (y>=2050)
		{
			while (x>=y)
			{
				x-=y;
				++ans;
			}
			y/=10;
		}
		printf("%d\n",x==0?ans:-1);
	}
	return 0;
}