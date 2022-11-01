#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

const int N=2005;
const int MOD=998244353;

int n,m,cnt,last[N],ans,Ans;
int vis[N],col[N];
char str[N];
struct edge{int to,next,w;}e[N*6];

void addedge(int u,int v,int w)
{
	e[++cnt].to=v;e[cnt].w=w;e[cnt].next=last[u];last[u]=cnt;
	e[++cnt].to=u;e[cnt].w=w;e[cnt].next=last[v];last[v]=cnt;
}

void dfs(int x)
{
	vis[x]=1;
	for (int i=last[x];i;i=e[i].next)
		if (!vis[e[i].to]) vis[e[i].to]=1,col[e[i].to]=col[x]^e[i].w,dfs(e[i].to);
		else if (col[e[i].to]^col[x]!=e[i].w) ans=0;
}

void solve()
{
	cnt=0;
	memset(last,0,sizeof(last));
	for (int i=1;i<=n;i++)
	{
		if (i<=m) addedge(i+n,m-i+1+n,0);
		addedge(i,n-i+1,0);
		if (str[i]=='0') addedge(i,n+i,0);
		else if (str[i]=='1') addedge(i,n+i,1);
	}
	memset(vis,0,sizeof(vis));
	ans=1;
	col[n+m]=1;dfs(n+m);
	for (int i=n+m+1;i<=n+n;i++)
	{
		if (vis[i]&&col[i]) return;
		if (!vis[i]) col[i]=0,dfs(i);
	}
	for (int i=1;i<=n+m;i++)
		if (!vis[i])
		{
			dfs(i);
			ans=ans*2%MOD;
		}
	(Ans+=ans)%=MOD;
}

int main()
{
	scanf("%s",str+1);
	n=strlen(str+1);
	std::reverse(str+1,str+n+1);
	for (m=1;m<n;m++) solve();
	printf("%d\n",Ans);
	return 0;
}