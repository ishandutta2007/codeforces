#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define ri register int
const long double PI=3.141592653589793238462643383279;
const int M=998244353,N=500005;
int c,sum,n;
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	scanf("%d",&n);
	while(n--)
	{
		scanf("%d %d",&c,&sum);
		int a=sum/c;
		int x=-sum+a*c+c;
		printf("%lld\n",1ll*x*a*a+1ll*(c-x)*(a+1)*(a+1));
	}
}