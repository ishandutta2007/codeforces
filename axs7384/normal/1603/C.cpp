#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=100005;
const int mod=998244353;
int t,n,a[N];
int f[N],g[N],h[N];
ll ans;
int main()
{
	scanf("%d",&t);
	while (t--)
	{
		scanf("%d",&n);
		for (int i=1;i<=n;++i)
			scanf("%d",&a[i]);
		for (int i=1;i<=n;++i)
		{
			f[i]=0;
			g[i]=a[i];
			h[i]=0;
		}
		ans=0;
		for (int i=2;i<=n;++i)
		{
			for (int j=i-1;j>=1;--j)
			{
				int fb=(a[j]-1)/g[j+1]+1;
				if (f[j]==fb-1)
				{
					for (int k=j+1;k<=i;++k)
						h[k]=(h[k-1]+(ll)f[k]*k)%mod;
					break;
				}
				g[j]=a[j]/fb;
				f[j]=fb-1;
				if (j==1)
				{
					for (int k=1;k<=i;++k)
						h[k]=(h[k-1]+(ll)f[k]*k)%mod;
				}
			}
			// cout<<i<<"! "<<g[1]<<' '<<g[2]<<' '<<g[3]<<' '<<g[4]<<endl;
			// cout<<i<<"? "<<f[1]<<' '<<f[2]<<' '<<f[3]<<' '<<f[4]<<endl;
			// cout<<h[i]<<endl;
			// cout<<i<<' '<<f[i]<<endl;
			(ans+=h[i])%=mod;
		}
		cout<<ans<<endl;
	}
	return 0;
}