#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<vector>
using namespace std;
typedef long long LL;
const int N=15;
int T;
char ss[N];
int ans;
int a[N];
int sum1[N],sum[N];
int check ()
{
//	for (int u=1;u<=10;u++) printf("%c",ss[u]);printf("\n");
	int A=0,B=0;
	for (int u=1;u<=10;u++)
	{
		if (A+sum[u]<B) return u-1;
		if (B+sum1[u]<A) return u-1;
		if (ss[u]=='1')
		{
			if (u&1) A++;
			else B++;
		}
	}
	return 10;
}
void dfs (int x)
{
	if (x>10)	{ans=min(ans,check());return ;}
	if (ss[x]=='?')
	{
		ss[x]='1';dfs(x+1);
		ss[x]='0';dfs(x+1);
		ss[x]='?';
	}
	else dfs(x+1);
}
int main()
{
	for (int u=10;u>=0;u--)
	{
		sum[u]=sum[u+1]+(u&1);
		sum1[u]=sum1[u+1]+(!(u&1));
	}
	int T;
	scanf("%d",&T);
	while (T--)
	{
		scanf("%s",ss+1);ans=10;
		dfs(1);
		printf("%d\n",ans);
	}
	return 0;
}