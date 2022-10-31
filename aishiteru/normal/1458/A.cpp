#include<bits/stdc++.h>
using namespace std;
int n,m,i;
long long g,a[200005],b;
int main()
{
	scanf("%d %d",&n,&m);
	for(i=1;i<=n;++i)
		scanf("%lld",&a[i]);
	for(i=2;i<=n;++i)
		g=__gcd(g,abs(a[i]-a[i-1]));
	for(i=1;i<=m;++i)
	{
		scanf("%lld",&b);
		printf("%lld ",__gcd(g,b+a[1]));
	}
}