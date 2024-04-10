#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
const int N=(1<<23);
int n,m;
bool vis[N];
bool f[N];
int a[N];
int s;
void dfs (int x)
{
	if (vis[x]==true) return ;
	vis[x]=true;
	if (f[x]) dfs(x^s);
	for (int u=0;u<n;u++)
		if (((1<<u)&x)!=0)
			dfs(x^(1<<u));
}
int main()
{
	memset(f,false,sizeof(f));
	memset(vis,false,sizeof(vis));
	scanf("%d%d",&n,&m);
	for (int u=1;u<=m;u++)	
	{
		scanf("%d",&a[u]);
		f[a[u]]=true;
	}
	int ans=0;
	s=(1<<n)-1;
	for (int u=1;u<=m;u++)
		if (vis[a[u]]==false)
		{
			ans++;
			dfs(a[u]^s);
		}
	printf("%d\n",ans);
	return 0;
}