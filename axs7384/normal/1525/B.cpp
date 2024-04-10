#include<bits/stdc++.h>
using namespace std;
int a[1005];
int t,n;
inline bool check0()
{
	for (int i=1;i<n;++i)
		if (a[i]>a[i+1])
			return false;
	return true;
}
int main()
{
	scanf("%d",&t);
	while (t--)
	{
		scanf("%d",&n);
		for (int i=1;i<=n;++i)
			scanf("%d",&a[i]);
		if (check0())
		{
			puts("0");
			continue;
		}
		if (a[1]==1||a[n]==n)
		{
			puts("1");
			continue;
		}
		if (a[1]==n&&a[n]==1)
		{
			puts("3");
			continue;
		}
		puts("2");
	}
}