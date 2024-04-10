#include<bits/stdc++.h>
using namespace std;
int n,m,a[1005],x;
int main()
{
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;++i)
	{
		scanf("%d",&x);
		if (!a[x])
			a[x]=i;
	}
	while (m--)
	{
		scanf("%d",&x);
		printf("%d\n",a[x]);
		for (int i=1;i<=50;++i)
			if (a[i]<a[x])
				++a[i];
		a[x]=1;
	}
	return 0;
}