#include<bits/stdc++.h>

int n,a[105];

int main()
{
	int T;scanf("%d",&T);
	while (T--)
	{
		scanf("%d",&n);
		for (int i=1;i<=n;i++) scanf("%d",&a[i]);
		std::sort(a+1,a+n+1);
		for (int i=n;i>=1;i--) printf("%d ",a[i]);
		puts("");
	}
	return 0;
}