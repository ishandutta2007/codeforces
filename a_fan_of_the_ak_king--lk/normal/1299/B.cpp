#include<bits/stdc++.h>
using namespace std;
const int N=1000005;
int t,n,q,i,x[100005],y[100005],ans;
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	scanf("%d",&n);
	for(i=1;i<=n;++i)
		scanf("%d %d",&x[i],&y[i]);
	if(n&1)
	{
		puts("NO");
		return 0;
	}
	for(i=1;i<=n/2;++i)
	{
		if(1ll*(y[i]-y[i+1])*(x[i+n/2]-x[(i+n/2)%n+1])!=1ll*(x[i]-x[i+1])*(y[i+n/2]-y[(i+n/2)%n+1]))
		{
			puts("NO");
			return 0;
		}
		if(1ll*(y[i]-y[i+1])*(y[i]-y[i+1])+1ll*(x[i]-x[i+1])*(x[i]-x[i+1])!=1ll*(y[i+n/2]-y[(i+n/2)%n+1])*(y[i+n/2]-y[(i+n/2)%n+1])+1ll*(x[i+n/2]-x[(i+n/2)%n+1])*(x[i+n/2]-x[(i+n/2)%n+1]))
		{
			puts("NO");
			return 0;
		}
	}
	puts("YES");
}