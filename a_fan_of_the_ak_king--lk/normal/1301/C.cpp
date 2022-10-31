#include<bits/stdc++.h>
using namespace std;
const int N=200005;
const int M=1000000007;
typedef long double lb;
int n,m,i,j,t;
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d %d",&n,&m);
		n-=m;
		int x=n/(m+1);
		int y=n-n/(m+1)*(m+1);
		printf("%lld\n",1ll*(n+m)*(n+m+1)/2-1ll*(m+1-y)*x*(x+1)/2-1ll*y*(x+1)*(x+2)/2);
	}
}