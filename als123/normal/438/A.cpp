#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
const int N=1005;
int n,m;
int a[N];
int main()
{
	scanf("%d%d",&n,&m);
	for (int u=1;u<=n;u++)	scanf("%d",&a[u]);
	int ans=0;
	for (int u=1;u<=m;u++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		ans=ans+min(a[x],a[y]);
	}
	printf("%d\n",ans);
	return 0;
}