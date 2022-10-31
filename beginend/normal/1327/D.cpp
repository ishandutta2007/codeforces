#include<bits/stdc++.h>

const int N=200005;

int n,p[N],c[N],a[N];
bool vis[N];

bool check(int n,int m)
{
	for (int i=1;i<=m;i++)
	{
		bool flag=0;
		for (int j=i;j<=n;j+=m)
			if (c[a[j]]!=c[a[i]])
			{
				flag=1;
				break;
			}
		if (!flag) return 1;
	}
	return 0;
}

int solve(int n)
{
	int ans=n;
	for (int i=1;i*i<=n;i++)
		if (n%i==0)
		{
			if (check(n,i)) ans=std::min(ans,i);
			if (check(n,n/i)) ans=std::min(ans,n/i);
		}
	return ans;
}

int main()
{
	int T;scanf("%d",&T);
	while (T--)
	{
		scanf("%d",&n);
		for (int i=1;i<=n;i++) scanf("%d",&p[i]);
		for (int i=1;i<=n;i++) scanf("%d",&c[i]);
		int ans=n;
		for (int i=1;i<=n;i++) vis[i]=0;
		for (int i=1;i<=n;i++)
			if (!vis[i])
			{
				int tot=0,x=i;
				while (!vis[x]) a[++tot]=x,vis[x]=1,x=p[x];
				ans=std::min(ans,solve(tot));
			}
		printf("%d\n",ans);
	}
	return 0;
}