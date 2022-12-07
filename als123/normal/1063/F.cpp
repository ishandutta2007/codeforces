#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;
const int N=500005;
const int MOD=7000007;
int n;
char ss[N];
int h[N];
bool f[1005][N];
bool ok[MOD];
int main()
{
	scanf("%d",&n);
	scanf("%s",ss+1);
	for (int u=1;u<=n;u++)	h[u]=ss[u]-'a'+1;
	int ans=1;
	memset(f[1],true,sizeof(f[1]));
	memset(ok,false,sizeof(ok));
	for (int u=2;u<=1000;u++)
	{
		if (ans!=u-1) break;
		memset(ok,false,sizeof(ok));
		for (int i=n-u;i>=1;i--)// 
		{
			if (f[u-1][i+u])	ok[h[i+u]]=true;
			if (ok[h[i]]||ok[h[i+1]])
			{
				ans=u;
				f[u][i]=true;
			}
		}
		for (int i=n-u;i>=1;i--)// 
			ok[h[i+u]]=false;;
		for (int i=1;i<=n-u+1;i++)
			h[i]=(h[i]*233+ss[i+u-1]-'a')%MOD;
	}
	printf("%d\n",ans);
	return 0;
}