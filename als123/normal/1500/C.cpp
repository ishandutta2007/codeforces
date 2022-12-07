#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<vector>
#include<queue>
using namespace std;
typedef long long LL;
const int N=1505;
int a[N][N],b[N][N];
int n,m;
int o[N];
queue<int> q;
bool cut[N];
vector<int> ans;
int id[N];
int X;
bool cmp (int x,int y)	{return a[x][X]<a[y][X];}
int main()
{
	memset(cut,false,sizeof(cut));
	scanf("%d%d",&n,&m);
	for (int u=1;u<=n;u++)
	for (int i=1;i<=m;i++)
	scanf("%d",&a[u][i]);
	for (int u=1;u<=n;u++)
	for (int i=1;i<=m;i++)
	scanf("%d",&b[u][i]);
	for (int i=1;i<=m;i++)
	for (int u=2;u<=n;u++)
	o[i]=o[i]+(b[u-1][i]>b[u][i]);
	for (int u=1;u<=m;u++) if (o[u]==0) q.push(u);
	while (!q.empty())
	{
		int x=q.front();q.pop();
	//	printf("%d\n",x);
		ans.push_back(x);
		for (int u=2;u<=n;u++)
		{
			if (cut[u]==true) continue;
			if (b[u][x]==b[u-1][x]) continue;
			cut[u]=true;
			for (int j=1;j<=m;j++) 
			{
				if (b[u-1][j]>b[u][j]) 
				{
					o[j]--;
					if (o[j]==0) q.push(j);
				}
			}
		}
	}
	for (int u=1;u<=n;u++) id[u]=u;
	int siz=ans.size();
	for (int u=siz-1;u>=0;u--)
	{
	X=ans[u];
		stable_sort(id+1,id+1+n,cmp);
	}
	//for (int u=1;u<=n;u++) printf("%d ",id[u]);
	for (int u=1;u<=n;u++)
	for (int i=1;i<=m;i++)
	if (a[id[u]][i]!=b[u][i])
	{
		printf("-1\n");
		return 0;
	}
	printf("%d\n",siz);
	for (int u=siz-1;u>=0;u--) printf("%d ",ans[u]);
	return 0;
}