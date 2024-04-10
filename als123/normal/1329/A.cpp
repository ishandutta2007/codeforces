#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<vector>
using namespace std;
typedef long long LL;
const int N=100005;
int n,m; 
int l[N];
int ans[N];
int mx[N];
int main()
{
	LL cnt=0;
	scanf("%d%d",&n,&m);
	for (int u=1;u<=m;u++) 
	{
		scanf("%d",&l[u]);
		cnt=cnt+l[u];
	}
	if (cnt<n) {printf("-1\n");return 0;}
	for (int u=1;u<=m;u++)
	{
		ans[u]=u;
		//printf("%d %d\n",ans[u],ans[u]+l[u]-1);
		mx[u]=max(mx[u-1],ans[u]+l[u]-1);
	}
//	printf("%d\n",mx[m]); 
	if (mx[m]>n) {printf("-1\n");return 0;}
	if (mx[m]<n)
	{
		for (int u=m;u>=1;u--)
		{
			ans[u]=n-l[u]+1;n-=l[u];
			if (mx[u-1]+1>=ans[u]) break;
		}
	}
	for (int u=1;u<=m;u++) printf("%d ",ans[u]);
	return 0;
}