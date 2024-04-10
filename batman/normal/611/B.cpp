#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
inline ll tavan(ll a,ll n) {ll p=1;while(n>0){if(n%2){p=p*a;}n>>=1;a*=a;}return p;}
inline ll tavan(ll a,ll n,ll mod) {ll p=1;while(n>0){if(n%2){p=p*a;p%=mod;}n>>=1;a*=a;a%=mod;}return p%mod;}
#define N (301*1000)
#define INF ((ll)1e9)
#define MOD ((ll)1e9+7)

ll l,r,n;

ll num(ll x)
{
    ll ans=1;
    for(ll i=2;i<=64;i++)
    {
        ll p=tavan(2ll,i)-1;
        for(ll j=i-2;j>=0;j--)
        {
            ll q=tavan(2ll,j);
            if(x<p-q)
                return ans;
            ans++;  
        }
    }
    return ans;
}

int main ()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>l>>r;
    cout<<num(r)-num(l-1);
    return 0;
}