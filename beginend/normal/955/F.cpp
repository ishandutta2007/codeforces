#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<vector>
#define mp(x,y) make_pair(x,y)
using namespace std;

typedef long long LL;
typedef pair<int,int> pi;

const int N=300005;

int n,cnt,last[N],dep[N],f[N][25],a[N],dp[N],fa[N];
struct edge{int to,next;}e[N*2];
vector<pi> vec[N];
LL ans;

void addedge(int u,int v)
{
	e[++cnt].to=v;e[cnt].next=last[u];last[u]=cnt;
	e[++cnt].to=u;e[cnt].next=last[v];last[v]=cnt;
}

bool cmp(int x,int y)
{
	return x>y;
}

void dfs(int x)
{
	dep[x]=1;f[x][1]=n;
	for (int i=last[x];i;i=e[i].next)
		if (e[i].to!=fa[x]) fa[e[i].to]=x,dfs(e[i].to),dep[x]=max(dep[x],dep[e[i].to]+1);
	ans+=dep[x];
	for (int i=2;i<20;i++)
	{
		int tot=0,k=0;
		for (int j=last[x];j;j=e[j].next) if (e[j].to!=fa[x]) a[++tot]=f[e[j].to][i-1];
		if (!tot) break;
		sort(a+1,a+tot+1,cmp);
		while (k<tot&&a[k+1]>k) k++;
		f[x][i]=k;vec[k].push_back(mp(x,i));
	}
}

int main()
{
	scanf("%d",&n);
	for (int i=1;i<n;i++)
	{
		int x,y;scanf("%d%d",&x,&y);
		addedge(x,y);
	}
	dfs(1);
	int sum=n;
	for (int i=1;i<=n;i++) dp[i]=1;
	for (int k=n;k>1;k--)
	{
		for (int j=0;j<vec[k].size();j++)
		{
			int x=vec[k][j].first,y=vec[k][j].second;
			while (x&&dp[x]<y) sum+=y-dp[x],dp[x]=y,x=fa[x];
		}
		ans+=sum;
	}
	printf("%I64d",ans);
	return 0;
}