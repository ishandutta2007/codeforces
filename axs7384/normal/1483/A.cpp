#include<bits/stdc++.h>
using namespace std;
const int N=100005;
int a[N],f[N],ans[N],n,m,t,x,sx;
vector<int> v[N];
int main()
{
	scanf("%d",&t);
	while (t--)
	{
		scanf("%d%d",&n,&m);
		for (int i=1;i<=m;++i)
		{
			scanf("%d",&a[i]);
			for (int j=1;j<=a[i];++j)
			{
				scanf("%d",&x);
				v[i].push_back(x);
			}
			if (a[i]==1)
			{
				++f[v[i][0]];
				ans[i]=v[i][0];
			}
		}
		bool b=1;
		sx=(m+1)/2;
		for (int i=1;i<=m;++i)
			if (a[i]!=1)
			{
				for (int j=0;j<a[i];++j)
					if (f[v[i][j]]<sx)
					{
						++f[v[i][j]];
						ans[i]=v[i][j];
						break;
					}
			}
		for (int i=1;i<=n;++i)
			if (f[i]>sx)
				b=0;
		if (b)
		{
			puts("YES");
			for (int i=1;i<=m;++i)
				printf("%d ",ans[i]);
			puts("");
		}
		else
			puts("NO");
		for (int i=1;i<=n;++i)
			f[i]=0;
		for (int i=1;i<=m;++i)
			v[i].clear();
	}
}