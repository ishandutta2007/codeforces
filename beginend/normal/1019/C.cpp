#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<vector>
#define pb push_back

const int N=1000005;

int n,m,vis[N];
bool used[N];
std::vector<int> vec[N];

int main()
{
	scanf("%d%d",&n,&m);
	for (int i=1;i<=m;i++)
	{
		int x,y;scanf("%d%d",&x,&y);
		vec[x].pb(y);
	}
	for (int i=1;i<=n;i++)
		if (!vis[i])
		{
			vis[i]=i;
			for (int j=0;j<vec[i].size();j++)
				if (!vis[vec[i][j]]) vis[vec[i][j]]=i;
			used[i]=1;
		}
	for (int i=n;i>=1;i--)
		if (used[i])
		{
			for (int j=0;j<vec[i].size();j++) used[vec[i][j]]=0;
		}
	int ans=0;
	for (int i=1;i<=n;i++) if (used[i]) ans++;
	printf("%d\n",ans);
	for (int i=1;i<=n;i++) if (used[i]) printf("%d ",i);
	return 0;
	return 0;
}