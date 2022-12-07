#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<vector>
using namespace std;
typedef long long LL;
const int N=3005;
int T;
int a[N];
bool in[N];
int f[N][N];
int sum[N];
int suf[N][N];
int h[N][N];
int main()
{
	scanf("%d",&T);
	while (T--)
	{
		int n;
		scanf("%d",&n);
		for (int u=0;u<=n+1;u++)
		for (int i=0;i<=n+1;i++)
		{
			f[u][i]=n+1;suf[u][i]=n+1;h[u][i]=0;
		}
		for (int u=1;u<=n;u++) scanf("%d",&a[u]);
		int tot=0;
		for (int u=n;u>=1;u--)
		{
			in[u]=false;
			if (a[u]+u>=n) in[u]=true;
			else
			{
				for (int i=u+1;i<=a[u]+u;i++) if (in[i]) in[u]=true;
			}
			if (in[u]==false) tot++;
		}
		for (int u=n;u>=1;u--)
		{
			for (int i=1;i<=a[u]+u;i++) h[u][i]++;
			for (int i=1;i<=n;i++) h[u][i]=h[u][i]+h[u+1][i];
		}
		for (int u=1;u<=n;u++) if (a[u]+u>=n) 
		{
			f[u][n]=h[u+1][n]-h[n][n];
			for (int i=1;i<=n;i++) suf[u][i]=f[u][n];
		}
		int u=1;
		for (int u=n;u>=1;u--) if (in[u])
		{
			for (int i=a[u]+u;i>u;i--) if (in[i])
			{
				f[u][i]=min(f[u][i],suf[i][a[u]+u+1]+h[u+1][i]-h[i][i]);
			}
			for (int i=n;i>=1;i--) suf[u][i]=min(f[u][i],suf[u][i+1]);
		}
		int ans=n;
		for (int u=2;u<=n;u++) if (in[u]) ans=min(ans,f[1][u]);
		printf("%d\n",ans);
	}
	return 0;
}