#include<bits/stdc++.h>

const int N=100005;

int n,a[N];

int main()
{
	int T;scanf("%d",&T);
	while (T--)
	{
		scanf("%d",&n);
		for (int i=1;i<=n;i++) scanf("%d",&a[i]);
		std::sort(a+1,a+n+1);
		int ans=0;
		for (int i=1;i<=n;i++) if (a[i]!=a[i-1]) ans++;
		printf("%d\n",ans);
	}
	return 0;
}