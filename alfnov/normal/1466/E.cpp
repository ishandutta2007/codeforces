#include<bits/stdc++.h>
#define mod 1000000007
using namespace std;
long long x[500005],y[500005];
int w[500005],c1[500005],c2[500005];
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		for(int i=1;i<=n;i++)scanf("%lld",&x[i]),y[i]=x[i];
		for(int i=1;i<=n;i++)c1[i]=c2[i]=0;
		int js=1;
		for(int i=0;i<=60;i++)
		{
			int ff=0;
			for(int j=1;j<=n;j++)w[j]=y[j]&1,y[j]>>=1,ff+=w[j];
			for(int j=1;j<=n;j++)
			{
				if(w[j])c1[j]=(c1[j]+1ll*js*n)%mod;
				else c1[j]=(c1[j]+1ll*js*ff)%mod;
			}
			js=2*js%mod;
		}
		js=1;
		for(int i=0;i<=60;i++)
		{
			int ff=0;
			for(int j=1;j<=n;j++)w[j]=x[j]&1,x[j]>>=1,ff=(ff+1ll*w[j]*c1[j])%mod;
			for(int j=1;j<=n;j++)if(w[j])c2[j]=(c2[j]+1ll*js*ff)%mod;
			js=2*js%mod;
		}
		int ans=0;
		for(int i=1;i<=n;i++)ans=(0ll+ans+c2[i])%mod;
		cout<<ans<<endl;
	}
	return 0;
}