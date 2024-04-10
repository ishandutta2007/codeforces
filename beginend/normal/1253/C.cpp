#include<bits/stdc++.h>

typedef long long LL;

const int N=200005;

int n,m;
LL a[N],s[N],ans[N];

int main()
{
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++) scanf("%lld",&a[i]);
	std::sort(a+1,a+n+1);
	for (int i=1;i<=n;i++)
	{
		ans[i]=ans[i-1];
		s[i%m]+=a[i];
		ans[i]+=s[i%m];
		printf("%lld ",ans[i]);
	}
	return 0;
}