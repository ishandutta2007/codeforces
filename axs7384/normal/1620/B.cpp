#include<bits/stdc++.h>
using namespace std;
#define ll long long
int a[1000005];
int t,w,h,k;
int main()
{
	scanf("%d",&t);
	while (t--)
	{
		scanf("%d%d",&w,&h);
		ll ans=0;
		for (int p=1;p<=4;++p)
		{
			scanf("%d",&k);
			for (int i=1;i<=k;++i)
				scanf("%d",&a[i]);
			ans=max(ans,(ll)(a[k]-a[1])*(((p<=2)?h:w)));
		}
		cout<<ans<<endl;
	}
}