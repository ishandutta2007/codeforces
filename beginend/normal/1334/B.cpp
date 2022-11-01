#include<bits/stdc++.h>

typedef long long LL;

const int N=100005;

int n;
LL x,a[N];

int main()
{
	int T;scanf("%d",&T);
	while (T--)
	{
		scanf("%d%lld",&n,&x);
		for (int i=1;i<=n;i++) scanf("%lld",&a[i]);
		std::sort(a+1,a+n+1);
		int ans=0;LL s=0;
		for (int i=n;i>=1;i--)
		{
			s+=a[i];
			if (s<(LL)(n-i+1)*x) break;
			else ans++;
		}
		printf("%d\n",ans);
	}
	return 0;
}