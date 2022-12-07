#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
using namespace std;
const int N=100005;
const int K=105;
const int MOD=998244353;
int n,k,len;
int a[N];
int ans[N];
int f[N][K];
int cnt[K];
int del[K];
int add (int x,int y)	{x=x+y;return x>=MOD?x-MOD:x;}
int dec (int x,int y)	{x=x-y;return x<0?x+MOD:x;}
int main()
{
	scanf("%d%d%d",&n,&k,&len);
	if (len==1)
	{
		printf("0\n");
		return 0;
	}
	for (int u=1;u<=n;u++) scanf("%d",&a[u]);
	ans[0]=1;
	for (int u=1;u<=n;u++)
	{
		for (int i=1;i<=k;i++)
		{
			if (a[u]==i||a[u]==-1)
			{
				f[u][i]=dec(ans[u-1],del[i]);
				ans[u]=add(ans[u],f[u][i]);
				cnt[i]++;
				if (cnt[i]>=len-1) del[i]=dec(ans[u-len+1],f[u-len+1][i]);
			}
			else
			{
				cnt[i]=0;
				del[i]=0;
			}
		}
	}
	printf("%d\n",ans[n]);
	return 0;
}