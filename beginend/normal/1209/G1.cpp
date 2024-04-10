#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

const int N=200005;

int n,q,a[N],f[N],ls[N],s[N],t[N];

int find(int x)
{
	if (f[x]==x) return x;
	else return f[x]=find(f[x]);
}

int main()
{
	scanf("%d%d",&n,&q);
	int mx=0;
	for (int i=1;i<=n;i++) scanf("%d",&a[i]),mx=std::max(mx,a[i]),s[a[i]]++;
	for (int i=1;i<=mx;i++) f[i]=i;
	for (int i=1;i<=n;i++)
	{
		if (ls[a[i]]) t[ls[a[i]]+1]++,t[i+1]--;
		ls[a[i]]=i;
	}
	for (int i=1;i<=n;i++) t[i]+=t[i-1];
	for (int i=1;i<=n;i++)
		if (t[i]&&a[i]!=a[i-1]&&i>1)
		{
			int x=find(a[i]),y=find(a[i-1]);
			if (x!=y) s[y]=std::max(s[y],s[x]),f[x]=y;
		}
	memset(ls,0,sizeof(ls));
	memset(t,0,sizeof(t));
	for (int i=n;i>=1;i--)
	{
		if (ls[a[i]]) t[ls[a[i]]-1]++,t[i-1]--;
		ls[a[i]]=i;
	}
	for (int i=n;i>=1;i--) t[i]+=t[i+1];
	for (int i=n;i>=1;i--)
	{
		if (t[i]&&a[i]!=a[i+1]&&i<n)
		{
			int x=find(a[i]),y=find(a[i+1]);
			if (x!=y) s[y]=std::max(s[y],s[x]),f[x]=y;
		}
		if (!ls[a[i]]) ls[a[i]]=i;
	}
	int ans=n;
	for (int i=1;i<=mx;i++) if (f[i]==i) ans-=s[i];
	printf("%d\n",ans);
	return 0;
}