#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;

int n,m,a[15],b[15];

int main()
{
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	for (int i=1;i<=m;i++) scanf("%d",&b[i]);
	int ans=105;
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++)
			if (a[i]==b[j]) ans=min(ans,a[i]);
			else
			{
				int x=min(a[i],b[j]),y=max(a[i],b[j]);
				ans=min(ans,x*10+y);
			}
	printf("%d",ans);
	return 0;
}