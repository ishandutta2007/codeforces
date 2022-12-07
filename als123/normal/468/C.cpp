#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
using namespace std;
typedef long long LL;
LL M=1e17;
int main()
{
	//solve(0,1e18)= 45 * 18 *1e17 
	LL n;
	scanf("%lld",&n);
	LL l=n-5*(9*(18*M%n)%n)%n;
	printf("%lld %lld\n",l,l+M*10-1);
	return 0;
}