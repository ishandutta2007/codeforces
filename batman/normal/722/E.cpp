#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define M ((ll)301*1000)
#define N ((ll)2020)
#define K ((ll)26)
#define MOD ((ll)1e9+7)
ll tavan(ll a,ll b){ll res=1;while(b){res*=b%2?a:1;res%=MOD;a*=a;a%=MOD;b/=2;}return res;}

ll n,m,k,s,dp[N][K],fac[M],dis[N][N];
pair <ll,ll> a[N];

ll C(ll x,ll y){return (fac[x]*tavan((fac[x-y]*fac[y])%MOD,MOD-2))%MOD;}

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m>>k>>s;
	fac[0]=1;
	for(ll i=1;i<M;i++)fac[i]=(fac[i-1]*i)%MOD;
	a[0]={n,m};
	for(int i=1;i<=k;i++)
		cin>>a[i].first>>a[i].second;
	sort(a,a+k+1);
	for(int i=0;i<=k;i++)
		for(int j=0;j<i;j++)
			dis[i][j]=C(a[i].second-a[j].second+a[i].first-a[j].first,a[i].first-a[j].first);
	for(int i=0;i<=k;i++)
	{
		for(int p=1;p<K;p++)
			for(int j=0;j<i;j++)
				if(a[j].second<=a[i].second)
					dp[i][p]+=dp[j][p]*dis[i][j],dp[i][p]%=MOD;
		dp[i][0]=C(a[i].first-1+a[i].second-1,a[i].first-1)-dp[i][1];dp[i][0]%=MOD;dp[i][0]+=MOD;dp[i][0]%=MOD;
		for(int p=1;p<K-1;p++)dp[i][p]-=dp[i][p+1],dp[i][p]%=MOD,dp[i][p]+=MOD,dp[i][p]%=MOD;
		if(i!=k)
		{
			for(ll p=1,last=dp[i][0];p<K;p++)
			{
				ll ex=dp[i][p];
				dp[i][p]=last;
				last=ex;
			}
			dp[i][0]=0;
		}
	}
	ll ans=0,num=0;
	for(ll i=0,x=s;i<K-1;i++,x=(x+1)/2)ans+=dp[k][i]*x,num+=dp[k][i],num%=MOD,ans%=MOD;
	ans+=C(n-1+m-1,n-1)-num;ans%=MOD;ans+=MOD;ans%=MOD;
	ans*=tavan(C(n-1+m-1,n-1),MOD-2);ans%=MOD;
	cout<<ans;
	return 0;
}