#include <bits/stdc++.h>
using namespace std;
#define ld long double
#define ll long long
ll tavan(ll a,ll n,ll mod){ll res=1;while(n)res*=(n&1)?a:1,res%=mod,a*=a,a%=mod,n/=2;return res;}
const ll N=101*1000;
const ll MOD=((ll)1e9+7);
const ll INF=((ll)2e9);
 
ll n,k,now,ans,fact[N];
string s;

ll C(ll x,ll y)
{
	ll res=fact[x]*tavan(fact[y],MOD-2,MOD);res%=MOD;
	res*=tavan(fact[x-y],MOD-2,MOD);
	return res%MOD;
}
 
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>k>>s;
    fact[0]=1;
    for(ll i=1;i<N;i++)fact[i]=fact[i-1]*i,fact[i]%=MOD;
    for(ll i=n-1,p=1;i>=0;i--,p*=10,p%=MOD)
    {
    	ll ex=now;
    	if(k<=i)ex+=p*C(i,k),ex%=MOD,now+=p*C(i-1,k-1),now%=MOD;
    	ans+=ex*(s[i]-'0');ans%=MOD;
	}
	cout<<ans;
    return 0;
}