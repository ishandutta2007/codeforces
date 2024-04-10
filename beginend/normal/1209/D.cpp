#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

const int N=100005;

int n,m,f[N],s[N];
bool vis[N];

int find(int x)
{
	if (f[x]==x) return x;
	else return f[x]=find(f[x]);
}

int main()
{
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++) f[i]=i,s[i]=1;
	int ans=0;
	for (int i=1;i<=m;i++)
	{
		int x,y;scanf("%d%d",&x,&y);
		if (!vis[x]) vis[x]=1,ans++;
		if (!vis[y]) vis[y]=1,ans++;
		if (find(x)!=find(y)) s[find(y)]+=s[find(x)],f[find(x)]=find(y);
	}
	for (int i=1;i<=n;i++)
		if (s[i]>1&&f[i]==i) ans--;
	printf("%d\n",m-ans);
	return 0;
}