#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<vector>
using namespace std;
typedef long long LL;
const int N=100005;
int n,m;
int du[N];
vector<int> vec[N];
int ans[N];
int main()
{
	int T;
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d%d",&n,&m);
		for (int u=1;u<=n;u++) du[u]=0;
		for (int u=1;u<=m;u++)
		{
			vec[u].clear();
			int k,x;
			scanf("%d",&k);
			if (k==1)	{scanf("%d",&x);ans[u]=x;du[x]++;continue;}
			while (k--)
			{
				scanf("%d",&x);
				vec[u].push_back(x);
			}
		}
		for (int u=1;u<=m;u++)
		{
			int siz=vec[u].size();
			if (siz==0) continue;
			ans[u]=vec[u][0];
			for (int i=1;i<siz;i++) if (du[vec[u][i]]<du[ans[u]]) ans[u]=vec[u][i];
			du[ans[u]]++;
		}
		bool tf=true;
		for (int u=1;u<=n;u++) if (du[u]>(m+1)/2) tf=false;
		if (tf)
		{
			printf("YES\n");
			for (int u=1;u<=m;u++) printf("%d ",ans[u]);
			printf("\n");
		}
		else printf("NO\n");
	}
	return 0;
}