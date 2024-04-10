#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
inline ll tavan(ll a,ll n,ll mod) {ll p=1;while(n>0){if(n%2){p=p*a;p%=mod;}n>>=1;a*=a;a%=mod;}return p%mod;}
#define N (101*1000)
#define INF ((ll)1e9)
#define MOD ((ll)1e9+7)

ll n,k,num,p=1,dp[2][N],fact[N];
map <ll,ll> mp;

bool check(ll x)
{
	while(x)
	{
		if(x%10!=4 && x%10!=7)return 0;
		x/=10;
	}
	return 1;
}

int main()
{
	fact[0]=1;
	for(int i=1;i<N;i++)fact[i]=fact[i-1]*i,fact[i]%=MOD;
	scanf("%I64d%I64d",&n,&k);
	for(int i=0;i<n;i++)
	{
		ll a;
		scanf("%I64d",&a);
		if(!check(a))num++;
		else
			mp[a]++;
	}
	dp[0][0]=dp[1][0]=dp[0][num]=1;
	for(int i=1;i<num;i++)dp[0][i]=(((fact[num]*tavan(fact[i],MOD-2,MOD))%MOD)*tavan(fact[num-i],MOD-2,MOD))%MOD;
	for(map <ll,ll>::iterator it=mp.begin();it!=mp.end();it++,p++)
	{
		ll x=it->second;
		for(int i=1;i<N;i++)
			dp[(p&1)][i]=(x*dp[!(p&1)][i-1]+dp[!(p&1)][i])%MOD;
	}
	printf("%I64d",dp[!(p&1)][k]);
    return 0;
}