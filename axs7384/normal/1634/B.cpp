#include<bits/stdc++.h>
using namespace std;
#define int long long
const int inf=1e9+7;
int t,n,x,y;
signed main()
{
	scanf("%lld",&t);
	while (t--)
	{
		scanf("%lld%lld%lld",&n,&x,&y);
		x&=1;
		y&=1;
		for (int i=1,z;i<=n;++i)
		{
			scanf("%d",&z);
			(x+=z)&=1;
		}
		puts(x==y?"Alice":"Bob");
	}
	return 0;
}