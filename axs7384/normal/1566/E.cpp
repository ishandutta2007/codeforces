#include<bits/stdc++.h>
using namespace std;
const int N=200005;
int si[N];
int ans;
vector<int> v[N];
int t,n;
inline void dfs(int x,int y)
{
	si[x]=1;
	int sum=0;
	for (int z:v[x])
		if (z!=y)
		{
			dfs(z,x);
			sum+=si[z];
		}
	if (x==1)
		ans+=max(sum,1);
	else
	{
		if (sum!=0)
		{
			si[x]=0;
			ans+=sum-1;
		}
	}
}
int main()
{
	scanf("%d",&t);
	while (t--)
	{
		scanf("%d",&n);
		ans=0;
		for (int i=1;i<=n;++i)
			v[i].clear();
		for (int i=1,x,y;i<n;++i)
		{
			scanf("%d%d",&x,&y);
			v[x].push_back(y);
			v[y].push_back(x);
		}
		dfs(1,0);
		printf("%d\n",ans);
	}
	return 0;
}