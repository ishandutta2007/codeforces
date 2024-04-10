#include<bits/stdc++.h>
using namespace std;
const int N=4000005;
#define ll long long
int n,mod,nows;
int f[N],g[N],h[N];
int main()
{
	scanf("%d%d",&n,&mod);
	f[1]=1;
	nows=0;
	for (int i=1;i<=n;++i)
	{
		nows+=h[i];
		nows%=mod;
		if (f[i]!=1)
			f[i]=(nows+g[i-1])%mod;
		g[i]=(f[i]+g[i-1])%mod;
		nows=(nows+f[i])%mod;
		for (int j=i;j<=n;j+=i)
			(h[j]+=f[i])%=mod;
		for (int j=i+1;j<=n;j+=i+1)
			(h[j]+=mod-f[i])%=mod;
		// cout<<nows<<' '<<f[i]<<endl;
	}
	printf("%d\n",f[n]);
	return 0;
}