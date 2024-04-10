#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
#define ll long long
inline int ksm(int x,int y)
{
	int ans=1;
	for (;y;y/=2,x=(ll)x*x%mod)
		if (y&1)
			ans=(ll)ans*x%mod;
	return ans;
}
int n,m,ans,inv;
int a[22][50005];
int f[100];
int main()
{
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;++i)
		for (int j=1;j<=m;++j)
			scanf("%d",&a[i][j]);
	inv=1;
	for (int i=1;i<=n;++i)
		inv=(ll)inv*i%mod;
	inv=ksm(inv,mod-2);
	for (int i=1;i<=m;++i)
	{
		for (int j=1;j<=n;++j)
			f[j]=0;
		for (int j=1;j<=n;++j)
			++f[n-a[j][i]+2];
		int tmp=1,sum=1;
		for (int j=1;j<=n;++j)
		{
			tmp+=f[j]-1;
			sum=(ll)sum*tmp%mod;
		}
		(ans+=sum)%=mod;
	}
	ans=(ll)ans*inv%mod;
	ans=(m-ans+mod)%mod;
	cout<<ans;
	return 0;
}