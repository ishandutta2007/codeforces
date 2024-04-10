#include<bits/stdc++.h>
#define mod 998244353
using namespace std;
int s[200005],t[200005],a[200005],b[200005];
int mo=13131,bs[200005],m1[200005],m2[200005];
int main()
{
	int n,m,ans=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++)scanf("%d",&s[i]),a[i]=s[i]-s[i-1]+1e9;
	for(int i=1;i<=m;i++)scanf("%d",&t[i]),b[i]=t[i]-t[i-1]+1e9;
	bs[0]=1;
	for(int i=1;i<=n;i++)bs[i]=1ll*bs[i-1]*mo%mod;
	for(int i=1;i<=n;i++)m1[i]=(1ll*m1[i-1]*mo+a[i])%mod;
	for(int i=1;i<=m;i++)m2[i]=(1ll*m2[i-1]*mo+b[i])%mod;
	for(int i=m;i<=n;i++)
		ans+=(m1[i]-1ll*m1[i-m+1]*bs[m-1]%mod+mod)%mod==(m2[m]-1ll*m2[1]*bs[m-1]%mod+mod)%mod;
	cout<<ans<<'\n';
	return 0;
}