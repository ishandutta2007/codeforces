#include<bits/stdc++.h>
#define mod 998244353
using namespace std;
int d[1000005],f[1000005],s[1000005];
int main()
{
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		int tt=n/i;
		for(int j=1;j<=tt;j++)d[i*j]++;
	}
	f[1]=s[1]=1;
	for(int i=2;i<=n;i++)
	{
		f[i]=(d[i]+s[i-1])%mod;
		s[i]=(f[i]+s[i-1])%mod;
	}
	cout<<f[n]<<endl;
	return 0;
}