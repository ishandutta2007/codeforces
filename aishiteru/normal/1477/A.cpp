#include<bits/stdc++.h>
using namespace std;
const int N=2000005;
const long long M=3799912185593857ll;
int n,t,i;
long long m,x[N];
int main()
{
#ifndef ONLINE_JUDGE 
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d %lld",&n,&m);
		for(i=1;i<=n;++i)
			scanf("%lld",&x[i]);
		sort(x+1,x+1+n);
		long long g=0;
		for(i=1;i<n;++i)
			g=__gcd(g,x[i+1]-x[i]);
		puts((x[1]%g+g)%g==(m%g+g)%g?"YES":"NO");
	}
}