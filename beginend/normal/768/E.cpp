#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

int n,a[105];

int main()
{
	int tot=0;
	for (int i=1;i<=11;i++)
		for (int j=1;j<=i+1;j++)
			a[++tot]=i;
	scanf("%d",&n);
	int ans=0;
	for (int i=1;i<=n;i++)
	{
		int x;scanf("%d",&x);
		ans^=a[x];
	}
	puts(ans?"NO":"YES");
	return 0;
}