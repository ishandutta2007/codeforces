#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define ri register int
const long double PI=3.141592653589793238462643383279;
const int M=998244353,N=500005;
int n,r,b,k;
int gcd(int a,int b)
{
	if(!b)
		return a;
	return gcd(b,a%b);
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	scanf("%d",&n);
	while(n--)
	{
		scanf("%d %d %d",&r,&b,&k);
		if(r>b)
			swap(r,b);
		int g=gcd(r,b);
		puts((b-g-1)/r+1<k?"OBEY":"REBEL");
	}
}