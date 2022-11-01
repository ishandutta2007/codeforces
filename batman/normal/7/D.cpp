#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
inline ll tavan(ll a,ll n,ll mod) {ll p=1;while(n>0){if(n%2){p=p*a;p%=mod;}n>>=1;a*=a;a%=mod;}return p%mod;}
#define N (5001*1000)
#define INF ((ll)1e16)
#define MOD ((ll)1e9+17)
#define HASH (101)

string s;
ll hash_l[N],hash_r[N],n,tvn[N],ans=1,dp[N];

ll calc_hash_l(ll l,ll r)
{
	ll ex=0;
	if(l)ex=hash_l[l-1];
	ex*=tvn[r-l+1],ex%=MOD;
	return ((hash_l[r]-ex)+MOD)%MOD;
}

ll calc_hash_r(ll l,ll r)
{
	ll ex=0;
	if(r!=n-1)ex=hash_r[r+1];
	ex*=tvn[r-l+1],ex%=MOD;
	return ((hash_r[l]-ex)+MOD)%MOD;
}

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);
	tvn[0]=1;
	for(int i=1;i<N;i++)tvn[i]=tvn[i-1]*HASH,tvn[i]%=MOD;
	cin>>s;
	n=s.size();
	hash_l[0]=s[0]-'0'+2;
	for(int i=1;i<n;i++)
		hash_l[i]=hash_l[i-1]*HASH+(s[i]-'0'+2),hash_l[i]%=MOD;
	hash_r[n-1]=s[n-1]-'0'+2;
	for(int i=n-2;i>=0;i--)
		hash_r[i]=hash_r[i+1]*HASH+(s[i]-'0'+2),hash_r[i]%=MOD;
	dp[0]=1;	
	for(int i=1;i<n;i++)
		if(calc_hash_l(0,(i-1)/2)==calc_hash_r(i-((i-1)/2),i))
			dp[i]=dp[(i-1)/2]+1,ans+=dp[i];
	cout<<ans;
    return 0;
}