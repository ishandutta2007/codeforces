#include<bits/stdc++.h>

const int N=1005;

int n,a[N];

int main()
{
	int T;scanf("%d",&T);
	while (T--)
	{
		scanf("%d",&n);
		for (int i=1;i<=n;i++) scanf("%d",&a[i]);
		std::sort(a+1,a+n+1);
		for (int i=1;i<=n;i++) printf("%d ",a[i]);
		puts("");
		for (int i=1;i<=n;i++) scanf("%d",&a[i]);
		std::sort(a+1,a+n+1);
		for (int i=1;i<=n;i++) printf("%d ",a[i]);
		puts("");
	}
	return 0;
}