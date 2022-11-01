#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

const int N=200005;

int n,a[N],d[N],f[N],ans[N],pos[N];
bool vis[N];

bool cmp(int x,int y)
{
	return d[x]>d[y];
}

int find(int x)
{
	if (f[x]==x) return x;
	else return f[x]=find(f[x]);
}

int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&d[i]),a[i]=i;
	std::sort(a+1,a+n+1,cmp);
	for (int i=1;i<=n;i++) f[i]=i;
	int now=0;
	for (int x=1;x<=n;x++)
	{
		int i=a[x];
		if (d[i]<=now) pos[i]=find(n),f[find(n)]=find(n)-1,ans[pos[i]]=i*2-1;
		else
		{
			pos[i]=find(n-d[i]+now+1);
			ans[pos[i]]=i*2-1;
			f[find(n-d[i]+now+1)]=find(n-d[i]+now+1)-1;
			if (pos[i]==n-d[i]+now+1) now++,ans[n+now]=i*2;
		}
	}
	for (int i=1;i<n+now;i++) printf("%d %d\n",ans[i],ans[i+1]);
	for (int i=1;i<=n+now;i++) vis[ans[i]]=1;
	for (int i=1;i<=n;i++)
		if (!vis[i*2]) printf("%d %d\n",ans[pos[i]+d[i]-1],i*2);
	return 0;
}