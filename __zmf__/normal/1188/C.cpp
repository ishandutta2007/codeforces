//zhouakngyang txdy!
#include<bits/stdc++.h>
using namespace std;
#define int long long
inline int read()
{
	int sum=0,nega=1;char ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')nega=-1;ch=getchar();}
	while(ch<='9'&&ch>='0')sum=sum*10+ch-'0',ch=getchar();
	return sum*nega;
}
const int mod=998244353;
int n,k,a[1009],maxv,res[100009],ans,dp[1009][1009];
int cnt[100009];
signed main()
{
	n=read(),k=read();
	for(int i=1;i<=n;i++)a[i]=read();
	sort(a+1,a+n+1);
	maxv=(a[n]-a[1])/(k-1);
	for(int i=1;i<=n;i++)cnt[a[i]]=i;
	for(int i=1;i<=a[n];i++)
		if(!cnt[i])cnt[i]=cnt[i-1];
//	for(int i=0;i<=a[n];i++)cout<<cnt[i]<<" ";cout<<endl;
	for(int val=maxv;val>=0;val--)
	{
		for(int i=1;i<=n;i++)
			for(int j=1;j<=k;j++)
				dp[i][j]=0;
		for(int i=1;i<=n;i++)dp[i][1]=i;
		for(int i=1;i<=n;i++)
		{
			int to=0;if(a[i]>=val)to=cnt[a[i]-val];
			if(to==i)to=i-1;
	//		cout<<i<<" "<<a[i]-val<<" "<<to<<endl;
			for(int j=2;j<=k&&j<=i;j++)
			{
				dp[i][j]=(dp[i][j]+dp[to][j-1])%mod;
				dp[i][j]=(dp[i][j]+dp[i-1][j])%mod;
			}
		}
		res[val]=dp[n][k]%mod;
	//	cout<<val<<" "<<res[val]<<endl;
	}
	for(int val=maxv;val>=0;val--)ans=(ans+(res[val]-res[val+1]+mod)*val%mod)%mod;
	cout<<ans<<endl;
	return 0;
}