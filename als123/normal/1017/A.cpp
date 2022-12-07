#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
using namespace std;
int n;
int a[1005];
int main()
{
	scanf("%d",&n);
	for (int u=1;u<=n;u++)
	{
		for (int i=1;i<=4;i++)
		{
			int x;
			scanf("%d",&x);
			a[u]=a[u]+x;
		}
	}
	int ans=1;
	for (int u=2;u<=n;u++)
		if (a[u]>a[1]) ans++;
	printf("%d\n",ans);
	return 0;
}