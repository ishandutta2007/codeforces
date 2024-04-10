#include<bits/stdc++.h>
using namespace std;
int t,n,x,ans;
int main()
{
	scanf("%d",&t);
	while (t--)
	{
		scanf("%d",&n);
		ans=0;
		for (int i=1;i<=n;++i)
		{
			scanf("%d",&x);
			if (x!=2)
				++ans;
		}
		printf("%d\n",ans);
	}
	return 0;
}