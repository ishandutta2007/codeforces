#include<bits/stdc++.h>
using namespace std;
int t,n,m;
int a[305];
int main()
{
	scanf("%d",&t);
	while (t--)
	{
		scanf("%d%d",&n,&m);
		int ans=0;
		for (int i=1;i<=m;++i)
			scanf("%d",&a[i]);
		for (int i=1;i<=m;++i)
			for (int j=i+1;j<=m;++j)
				if (a[i]<a[j])
					++ans;
		printf("%d\n",ans);
	}
	return 0;
}