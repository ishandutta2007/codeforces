#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<vector>
using namespace std;
typedef long long LL;
const int N=300005;
int p[N];
int T;
int n,m;
int cnt[N];
int get (int x,int y)
{
	if (x<=y) return y-x;
	return y+n-x;
}
vector<int> ans;
int b[N];
int id[N],vis[N];
bool check (int x)
{
//	printf("%d\n",x);
	for (int u=1;u<=n;u++)
	{
		if (u+x<=n) b[u+x]=u;
		else b[u+x-n]=u;
	}
	for (int u=1;u<=n;u++) id[b[u]]=u;
	for (int u=1;u<=n;u++) vis[u]=false;
	int tot=0;
	for (int u=1;u<=n;u++) if (vis[u]==false)
	{
		tot++;int now=u;
		while (vis[now]==false)
		{
			vis[now]=true;
			now=id[p[now]];
		}
	}
	return n-tot<=m;
}
int main()
{
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d%d",&n,&m);
		for (int u=1;u<=n;u++) cnt[u]=0;
		for (int u=1;u<=n;u++) 
		{
			scanf("%d",&p[u]);
			//printf("%d\n",get(p[u],u));
			cnt[get(p[u],u)]++;
		}
		ans.clear();
		for (int u=0;u<n;u++) if (cnt[u]>=n-2*m)
		{
			if (check(u)) ans.push_back(u);
		}
		int siz=ans.size();
		printf("%d ",siz);
		for (int u=0;u<siz;u++) printf("%d ",ans[u]);printf("\n");
	}
	return 0;
}