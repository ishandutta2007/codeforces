#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
const int N=1005;
int n,m;
int a[N],b[N];
int main()
{
	scanf("%d%d",&n,&m);
	for (int u=1;u<=n;u++)	scanf("%d",&a[u]);
	for (int u=1;u<=m;u++) scanf("%d",&b[u]);
	int i=1,j=1;
	int ans=0;
	while (i<=n&&j<=m)
	{
		if (a[i]<=b[j])
		{
			i++;j++;
			ans++;
		}
		else i++;
	}
	printf("%d\n",ans);
	return 0;
}