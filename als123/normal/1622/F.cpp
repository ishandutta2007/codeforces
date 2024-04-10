#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<vector>
#include<map>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL; 
const int N=1000005;
ULL R ()	{return (ULL)rand()*(ULL)rand()*(ULL)rand()*(ULL)rand()*(ULL)rand();}
ULL p[N],JC[N];
int pri[N],cnt;
bool vis[N];
void Init (int n)
{
	p[1]=0;
	memset(vis,false,sizeof(vis));
	for (int u=2;u<=n;u++)
	{
		if (!vis[u]) {p[u]=R();pri[++cnt]=u;}
		for (int i=1;i<=cnt;i++)
		{
			int j=pri[i];
			if (j*u>n) break;
			vis[j*u]=true;
		//	printf("YES!:%d %d\n",u,j);
			p[j*u]=(p[u]^p[j]);
			if (u%j==0) break;
		}
	}
	JC[0]=JC[1]=0;
	for (int u=2;u<=n;u++) JC[u]=(JC[u-1]^p[u]);
}
map<ULL,int> mp;
bool solve (int n)
{
	ULL sum=0;
	for (int u=1;u<=n;u++) sum^=JC[u];
	if (sum==0)
	{
		printf("%d\n",n);
		for (int u=1;u<=n;u++) printf("%d ",u);
		return 1;
	}
	for (int u=1;u<=n;u++) if (sum==JC[u])
	{
		printf("%d\n",n-1);
		for (int i=1;i<=n;i++) if (i!=u) printf("%d ",i);
		return 1;
	}
	mp.clear();
	for (int u=1;u<=n;u++)
	{
		if (mp.find(JC[u])!=mp.end())
		{
			int p=mp[JC[u]];
			printf("%d\n",n-2);
			for (int i=1;i<=n;i++) if (i!=u&&i!=p) printf("%d ",i);
			return 1;
		}
		mp[JC[u]^sum]=u;
	}
	return 0;
}
int main()
{
	srand(200815147);
	int n;
	scanf("%d",&n);
	Init(n);
//	for (int u=1;u<=n;u++) printf("%llu ",p[u]);printf("\n");
//	for (int u=1;u<=n;u++) printf("%llu ",JC[u]);
	if (!solve(n)) solve(n-1);
	return 0;
}