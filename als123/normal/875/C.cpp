#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
#include<iostream>
#include<queue>
using namespace std;
const int N=100005;
int n,m;
int len[N];
vector<int> s[N],e[N];
int fl[N];//
int d[N];
bool vis[N];
int main()
{
	memset(fl,-1,sizeof(fl));
	scanf("%d%d",&n,&m);
	for (int u=1;u<=n;u++)
	{
		scanf("%d",&len[u]);
		for (int i=1;i<=len[u];i++)
		{
			int x;
			scanf("%d",&x);
			s[u].push_back(x);
		}
		if (u==1) continue;
		int o=min(len[u-1],len[u]);
		int i;
		for (i=0;i<o;i++)
		{
			if (s[u-1][i]>s[u][i])// 
			{
				if (fl[s[u-1][i]]==0) {printf("No\n");return 0;}
				fl[s[u-1][i]]=1;
				if (fl[s[u][i]]==1) {printf("No\n");return 0;}
				fl[s[u][i]]=0;
				break;
			}
			else if (s[u-1][i]<s[u][i])
			{
				e[s[u][i]].push_back(s[u-1][i]);
				d[s[u-1][i]]++;
				break;
			}
		}
		if (i==o)
		{
			if (len[u-1]>len[u])
			{
				printf("No\n");
				return 0;
			}
		}
	}
	queue<int> q;
	for (int u=1;u<=m;u++) if (d[u]==0) q.push(u);
	for (int u=1;u<=m;u++)
	{
		if (fl[u]==1)//
			vis[u]=true; 
		else vis[u]=false;
	}
	while (!q.empty())
	{
		int x=q.front();q.pop();
		int SZ=e[x].size();
		for (int u=0;u<SZ;u++)
		{
			int y=e[x][u];
			vis[y]=(vis[y]|vis[x]);
			d[y]--;
			if (d[y]==0)	q.push(y);
		}
	}
	for (int u=1;u<=m;u++)
		if (fl[u]==0&&vis[u]==true)
		{
			printf("No\n");
			return 0;
		}
	printf("Yes\n");
	int ans=0;
	for (int u=1;u<=m;u++)
		if (vis[u]==true)
			ans++;
	printf("%d\n",ans);
	for (int u=1;u<=m;u++)
		if (vis[u]==true)
			printf("%d ",u);
	return 0;
}