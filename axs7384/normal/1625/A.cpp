#include<bits/stdc++.h>
using namespace std;
int t,n,m;
int a[10005];
int main()
{
	scanf("%d",&t);
	while (t--)
	{
		scanf("%d%d",&n,&m);
		for (int i=1;i<=n;++i)
			scanf("%d",&a[i]);
		int ans=0;
		for (int j=0;j<m;++j)
		{
			int p=0;
			for (int i=1;i<=n;++i)
				if (a[i]&(1<<j))
					++p;
			if (p>n/2)
				ans|=1<<j;
		}
		cout<<ans<<endl;
	}
	return 0;
}