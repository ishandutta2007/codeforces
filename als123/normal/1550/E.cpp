#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<vector>
using namespace std;
typedef long long LL;
const int N=200005;
const int K=20;
int n,k;
char ss[N];
int cnt[N][K];
int f[1<<K];
int nxt[N][K];
bool check (int x)
{
	for (int i=0;i<k;i++) 
	{
		nxt[n+1][i]=n+1;
		nxt[n+2][i]=n+1;
	}
	for (int u=n;u>=1;u--)
	for (int i=0;i<k;i++)
	{
		nxt[u][i]=nxt[u+1][i];
		if (u+x-1<=n&&cnt[u+x-1][i]-cnt[u-1][i]+cnt[u+x-1][k]-cnt[u-1][k]==x) nxt[u][i]=u+x-1;
	}
	f[0]=0;int nn=(1<<k)-1;
	for (int u=1;u<=nn;u++) f[u]=n+1;
	for (int u=0;u<=nn;u++)
	{
	//	printf("%d %d\n",u,f[u]);
		for (int i=0;i<k;i++) if ((u&(1<<i))==0)
		{
			int t=nxt[f[u]+1][i];
			f[u^(1<<i)]=min(f[u^(1<<i)],t);
		}
	}
	return f[nn]<=n;
}
int main()
{
	scanf("%d%d",&n,&k);
	scanf("%s",ss+1);
	for (int u=1;u<=n;u++)
	{
		for (int i=0;i<=k;i++)	cnt[u][i]=cnt[u-1][i];
		if (ss[u]=='?') cnt[u][k]++;
		else cnt[u][ss[u]-'a']++;
	}
//	printf("%d\n",check(10));
	int l=1,r=n;
	int ans=0;
	while (l<=r)
	{
		int mid=(l+r)>>1;
		if (check(mid)) {ans=mid;l=mid+1;}
		else r=mid-1;
	}
	printf("%d\n",ans);
	return 0;
}