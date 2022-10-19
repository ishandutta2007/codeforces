#include<bits/stdc++.h>
using namespace std;
const int mod=1e9+7,N=20;
int a[N][N],f[N][N],u[N],n,m,K,Log[5000];
inline int lb(int x)
{
	return x&(-x);
}
int dfs(int x,int y)
{
	if (y==m+1)
	{
		++x;
		y=1;
	}
	if (x==n+1)
		return 1;
	int p=-1,k=f[x-1][y]|f[x][y-1],sum=0;
	for (int i=(~k)&((1<<(K+1))-2);i;i-=lb(i))
	{
		int t=Log[lb(i)];
		if (!a[x][y]||a[x][y]==t)
		{
			f[x][y]=k|(1<<t);
			++u[t];
			if (u[t]==1)
			{
				if (p==-1)
					p=dfs(x,y+1);
				sum+=p;
			}
			else
				sum+=dfs(x,y+1);
			sum%=mod;
			--u[t];
		}
	}
	return sum;
}
int main()
{
	//freopen("e.in","r",stdin);
	scanf("%d%d%d",&n,&m,&K);
	if (n+m-1>K)
	{
		putchar('0');
		return 0;
	}
	for (int i=1;i<=n;++i)
		for (int j=1;j<=m;++j)
		{
			scanf("%d",&a[i][j]);
			++u[a[i][j]];
		}
	for (int i=1;i<=K;++i)
		Log[1<<i]=i;
	cout<<dfs(1,1);
}