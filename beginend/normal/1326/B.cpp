#include<bits/stdc++.h>

typedef long long LL;

const int N=200005;

int n;
LL a[N],b[N];

int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%lld",&b[i]);
	LL mx=0;
	for (int i=1;i<=n;i++) a[i]=b[i]+mx,mx=std::max(mx,a[i]);
	for (int i=1;i<=n;i++) printf("%d ",a[i]);
	return 0;
}