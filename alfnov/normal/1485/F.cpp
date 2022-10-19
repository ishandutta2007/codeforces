#include<bits/stdc++.h>
using namespace std;
long long b[200005],f[200005],g[200005],h[200005];
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		for(int i=1;i<=n;i++)scanf("%lld",&b[i]),b[i]+=b[i-1];
		map<long long,long long>mp;
		for(int i=0;i<=n;i++)f[i]=g[i]=h[i]=0;
		g[1]=h[1]=1;
		long long he=0;
		for(int i=2;i<=n;i++)
		{
			g[i]=h[i-1];
			if(b[i-1])f[i]=1;
			f[i]+=he-mp[b[i-1]];
			f[i]%=1000000007;
			mp[b[i-1]]+=f[i];
			he+=f[i];
			h[i]=(f[i]+g[i])%1000000007;
		}
		cout<<h[n]<<endl;
	}
	return 0;
}