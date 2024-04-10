#include <bits/stdc++.h>
#define LL long long
#define p 1000000007
using namespace std;
LL n, k;
LL test(LL x, LL y)
{
	LL total=1;
	while(y)
	{
		if(y&1) total=(total*x)%p;
		x=(x*x)%p; y>>=1;
	}
	return total%p;
}
 
int main()
{
	cin>>n>>k;
	if(n==0) cout<<0;
	else cout<<((n%p*test(2, k))%p+((n-1)%p*test(2, k))%p+1)%p;
 
	return 0;
}