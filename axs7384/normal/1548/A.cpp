#include<bits/stdc++.h>
using namespace std;
int n,m;
int ans;
int q;
int d[200005];
int main()
{
	scanf("%d%d",&n,&m);
	for (int i=1,x,y;i<=m;++i)
	{
		scanf("%d%d",&x,&y);
		if (x>y)
			swap(x,y);
		++d[x];
	}
	for (int i=1;i<=n;++i)
		if (!d[i])
			++ans;
	scanf("%d",&q);
	for (int i=1,opt,x,y;i<=q;++i)
	{
		scanf("%d",&opt);
		if (opt==3)
			printf("%d\n",ans);
		if (opt==1)
		{
			scanf("%d%d",&x,&y);
			if (x>y)
				swap(x,y);
			if (!d[x])
				--ans;
			++d[x];
		}
		if (opt==2)
		{
			scanf("%d%d",&x,&y);
			if (x>y)
				swap(x,y);
			--d[x];
			if (!d[x])
				++ans;
		}
	}
	return 0;
}