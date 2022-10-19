#include<bits/stdc++.h>
#define mod 1000000007
using namespace std;
int f[3][3000005],c[3000005];
int powdv(int x,int y)
{
	int ans=1;
	while(y)
	{
		if(y&1)ans=1ll*ans*x%mod;
		y>>=1;
		x=1ll*x*x%mod;
	}
	return ans;
}
int niyuan(int x)
{
	return powdv(x,mod-2);
}
int ny[3000005],fc[3000005];
int main()
{
	int n,q,qwq=niyuan(3);
	cin>>n>>q;
	c[0]=1;
	int BS=1;
	fc[0]=1;
	for(int i=1;i<=3*n+1;i++)BS=1ll*BS*i%mod,fc[i]=BS;
	ny[3*n+1]=niyuan(BS);
	for(int i=3*n;i>=0;i--)ny[i]=1ll*ny[i+1]*(i+1)%mod;
	for(int i=1;i<=3*n;i++)
		c[i]=1ll*c[i-1]*(3*n-i+1)%mod*(1ll*fc[i-1]*ny[i]%mod)%mod;
	f[0][0]=f[1][0]=f[2][0]=n;
	for(int i=1;i<=3*n;i++)
	{
		f[0][i]=1ll*qwq*(c[i+1]-2ll*f[0][i-1]-f[1][i-1])%mod;
		f[1][i]=(f[0][i]+f[0][i-1])%mod;
		f[2][i]=(f[1][i]+f[1][i-1])%mod;
	}
	while(q--)
	{
		int x;
		scanf("%d",&x);
		int ans=(f[0][x]+c[x])%mod+mod;
		ans%=mod;
		printf("%d\n",ans);
	}
	return 0;
}