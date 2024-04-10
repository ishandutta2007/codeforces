#include<bits/stdc++.h>
using namespace std;
int n,m,a[1000],b[1000];
int main()
{
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;++i)
		scanf("%d",&a[i]);
	for (int i=1;i<=m;++i)
		scanf("%d",&b[i]);
	sort(b+1,b+1+m);
	int j=m;
	for (int i=1;i<=n;++i)
	{
		if (a[i]==0)
		{
			a[i]=b[j];
			int k=j;
			while (b[k]==b[j])
				--k;
			if (k==0)
				j=j-1;
			else
				j=k;
		}
		if (a[i]<=a[i-1])
		{
			puts("Yes");
			return 0;
		}
	}
	puts("No");
	return 0;
}