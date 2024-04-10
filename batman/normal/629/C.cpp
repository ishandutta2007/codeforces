#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
inline ll tavan(ll a,ll n,ll mod) {ll p=1;while(n>0){if(n%2){p=p*a;p%=mod;}n>>=1;a*=a;a%=mod;}return p%mod;}
#define MOD ((ll)1e9+7)
#define INF ((ll)1e9)
#define N (21*1000)

string s;
ll n,m,p,q,res,fact[N];

ll calc(ll x,ll y,ll dif)
{
	ll ans=0;
	ans=(((fact[x+y]*tavan(fact[x],MOD-2,MOD))%MOD)*tavan(fact[y],MOD-2,MOD))%MOD;
	y-=dif+1;x+=dif+1;
	if(y<0)return ans;
	ans-=(((fact[x+y]*tavan(fact[x],MOD-2,MOD))%MOD)*tavan(fact[y],MOD-2,MOD))%MOD;ans+=MOD;ans%=MOD;
	return ans;
}

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>n>>m>>s;
	fact[0]=1;
	for(int i=1;i<N;i++)fact[i]=fact[i-1]*i,fact[i]%=MOD;
	if(n%2==1)return cout<<0,0;
	ll maxi_dif=0;
	for(int i=0;i<m;i++)
	{
		if(s[i]=='(')p++;
		else q++;
		maxi_dif=max(maxi_dif,q-p);
	}
	ll ex1=n/2-p,ex2=n/2-q;
	for(ll i=0;i<=ex1;i++)
		for(ll j=0;j<=min(ex2,(ll)i);j++)
			if(i-j>=maxi_dif)
			{
				ll h=n/2-p-i,g=n/2-q-j;
				//cout<<i<<" "<<j<<" "<<calc(i,j,0)<<" "<<calc(h,g,p+i-q-j)<<"\n";
				res+=calc(i,j,0)*calc(h,g,p+i-q-j);res%=MOD;
			}
	cout<<res;
	return 0;
}