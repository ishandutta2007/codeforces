#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
const int N=1005;
int n,m;
int c[N];
int main()
{
	scanf("%d%d",&n,&m);
	for (int u=1;u<=m;u++)
	{
		int x;
		scanf("%d",&x);
		c[x]++;
	}
	int ans=m;
	for (int u=1;u<=n;u++)	ans=min(ans,c[u]);
	printf("%d\n",ans);
	return 0;
}