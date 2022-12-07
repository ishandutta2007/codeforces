#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<vector>
#include<queue>
using namespace std;
typedef long long LL;
const int N=4000005;
int n;
int a[N];
int f[N][2];
int g[N][2];
void Ins (int x,int xx)
{
	if (f[x][0]<xx)		{f[x][1]=f[x][0];f[x][0]=xx;}
	else if (f[x][1]<xx) f[x][1]=xx;
}
int mx=0;
void DP ()
{
	for (int u=20;u>=0;u--)
	{
		for (int i=0;i<=mx;i++)	{g[i][0]=f[i][0];g[i][1]=f[i][1];f[i][0]=0;f[i][1]=0;}
		for (int i=0;i<=mx;i++)
		{
			if (i&(1<<u))	{Ins(i,g[i][0]);Ins(i,g[i][1]);}
			else 
			{
				Ins(i,g[i][0]);		  Ins(i,g[i][1]);
				Ins(i,g[i^(1<<u)][0]);Ins(i,g[i^(1<<u)][1]);
			}
		}
	}
}
int solve (int t,int id)
{
	int ans=0;
	for (int u=20;u>=0;u--)	if (t&(1<<u))
	{
		int xx=(ans|(1<<u));
		//printf("%d %d %d\n",xx,ans,f[xx][id]);
		if (f[xx][1]>id) ans=xx;
	}
	return ans;
}
int main()
{
	mx=(1<<21);
	memset(f,0,sizeof(f));
	scanf("%d",&n);
	for (int u=1;u<=n;u++) 
	{
		scanf("%d",&a[u]);
	}
	for (int u=1;u<=n;u++) Ins(a[u],u);
	DP();
	//printf("YES\n");
	int ans=0;
	for (int u=n;u>=1;u--)
	{
		if (n-u+1>=3) 
		{
			int t=solve(((1<<30)-1)^a[u],u);
			ans=max(ans,t|a[u]);
		}
	}
	printf("%d\n",ans);
	return 0;
}