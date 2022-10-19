#include<bits/stdc++.h>
using namespace std;
int mod,f[4000005],g[4000005],h[4000005];
int main()
{
	int n;
	cin>>n>>mod;
	f[1]=1,g[1]=0;
	int s=1;
	for(int i=2;i<=n;i++)
	{
		for(int j=2*(i-1);j<=n;j+=i-1)
			h[j]=(0ll+h[j]+f[i-1]-f[i-2]+mod)%mod;
		g[i]=(g[i-1]+h[i])%mod;
		f[i]=(s+g[i])%mod,s=(s+f[i])%mod;
	}
	cout<<f[n]<<endl;
	return 0;
}