#include<bits/stdc++.h>

typedef long long LL;

const int N=100005;

int n,a[N];
LL s[N];

int main()
{
	int T;scanf("%d",&T);
	while (T--)
	{
		scanf("%d",&n);
		for (int i=1;i<=n;i++) scanf("%d",&a[i]),s[i]=s[i-1]+a[i];
		LL mx=0,mn=0;
		for (int i=1;i<n;i++)
		{
			mn=std::min(mn,s[i]);
			mx=std::max(mx,s[i]-mn);
			mx=std::max(mx,s[n]-s[i]);
		}
		if (s[n]>mx) puts("YES");
		else puts("NO");
	}
	return 0;
}