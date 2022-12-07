#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<vector>
using namespace std;
typedef long long LL;
const int N=15;
int a[N],n;
int T;
bool tf;
void dfs (int x,int y,int sum)
{
	if (sum==a[y]) 	{tf=true;return ;}
	if (x==y) {dfs(x+1,y,sum);return ;}
	if (x>n) return ;
	dfs(x+1,y,sum);
	dfs(x+1,y,sum+a[x]);
	dfs(x+1,y,sum-a[x]);
}
int main()
{
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d",&n);
		tf=false;
		for (int u=1;u<=n;u++) 
		{
			scanf("%d",&a[u]);
			if (a[u]==0) tf=true;
		}
		for (int u=1;u<=n;u++)
		{
			//printf("YES:%d %d\n",u,tf);
			dfs(1,u,0);
		}
		if (tf)	printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}