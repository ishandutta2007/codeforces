#include<bits/stdc++.h>
using namespace std;
const int N=205;
int col[N*N];
int n,k,m,f[N],used[N];
pair<int,int> ans[N];
int main()
{
	scanf("%d%d",&n,&k);
	for (int i=1;i<=n*k;++i)
	{
		scanf("%d",&col[i]);
		// a[x][++v[col[i]]]=i;
	}
	m=(n-1)/(k-1)+1;
	for (int t=1;t<=m;++t)
	{
		for (int i=1;i<=n;++i)
			f[i]=0;
		for (int i=1;i<=n*k;++i)
			if (!used[col[i]])
			{
				if (f[col[i]])
				{
					ans[col[i]]=make_pair(f[col[i]],i);
					for (int j=1;j<=n;++j)
						f[j]=0;
					used[col[i]]=1;
				}
				else
					f[col[i]]=i;
			}
	}
	for (int i=1;i<=n;++i)
		printf("%d %d\n",ans[i].first,ans[i].second);
	return 0;
}