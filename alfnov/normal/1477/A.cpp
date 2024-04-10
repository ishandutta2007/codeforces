#include<bits/stdc++.h>
using namespace std;
long long x[200005];
long long gcd(long long a,long long b)
{
	return b==0?a:gcd(b,a%b);
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		long long k;
		cin>>n>>k;
		for(int i=1;i<=n;i++)scanf("%lld",&x[i]);
		k-=x[n];
		for(int i=1;i<n;i++)x[i]-=x[n];
		long long tt=0;
		for(int i=1;i<n;i++)tt=gcd(tt,x[i]);
		if(k%tt==0)puts("YES");
		else puts("NO");
	}
	return 0;
}