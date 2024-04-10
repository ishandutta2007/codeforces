#include<bits/stdc++.h>
using namespace std;
int t,n,f[1005];
int main()
{
	scanf("%d",&t);
	while (t--)
	{
		scanf("%d",&n);
		for (int i=0;i<=100;++i)
			f[i]=0;
		for (int i=1,x;i<=n;++i)
		{
			scanf("%d",&x);
			f[abs(x)]++;
		}
		int ans=min(1,f[0]);
		for (int i=1;i<=100;++i)
			ans+=min(2,f[i]);
		cout<<ans<<endl;
	}
	return 0;
}