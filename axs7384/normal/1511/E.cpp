#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int mod=998244353;
const int N=300005;
vector<char> c[N];
inline int ksm(int x,int y)
{
	if (y<0)
		return 0;
	int ans=1;
	for (;y;y/=2,x=(ll)x*x%mod)
		if (y&1)
			ans=(ll)ans*x%mod;
	return ans;
}
int n,m,f[N],S,ans,p;
int main()
{
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;++i)
	{
		c[i].resize(m+2);
		scanf("%s",&c[i][1]);
	}
	for (int i=1;i<=n;++i)
		for (int j=1;j<=m;++j)
			if (c[i][j]=='o')
				++p;
	S=ksm(2,p-2);
	f[0]=1;
	f[1]=ksm(2,mod-2);
	for (int i=3;i<=max(n,m);i+=2)
		f[i]=(f[i-2]+ksm(f[1],i))%mod;
	for (int i=2;i<=max(n,m);i+=2)
		f[i]=(f[i-1]+ksm(f[1],i))%mod;
	for (int i=1;i<=n;++i)
	{
		int len=0;
		for (int j=1;j<m;++j)
			if (c[i][j]=='*')
				len=0;
			else
			{
				if (c[i][j+1]=='o')
					(ans+=(ll)S*f[len]%mod)%=mod;
				++len;
			}
	}
	// cout<<ans<<endl;
	for (int i=1;i<=m;++i)
	{
		int len=0;
		for (int j=1;j<n;++j)
			if (c[j][i]=='*')
				len=0;
			else
			{
				if (c[j+1][i]=='o')
				{
					// cout<<i<<' '<<j<<' '<<len<<endl;
					(ans+=(ll)S*f[len]%mod)%=mod;
				}
				++len;
			}
	}
	cout<<ans;
	return 0;
}