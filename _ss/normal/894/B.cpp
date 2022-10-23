#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define ld long double
#define pii pair<int,int>
#define fi first
#define se second
#define pb push_back
const ll maxn=1e5+1,mod=1e9+7;

ll product(ll a,ll b) {return (a*b)%mod;}

ll modpow(ll a,ll h)
{
    ll ans=1;
    for (;h;h/=2)
    {
        if (h&1) ans=product(ans,a);
        a=product(a,a);
    }
    return ans;
}

int main()
{
    ll n,m,k;
    cin>>n>>m>>k;
    if ((n+m)%2==1 && k==-1) cout<<0;
    else cout<<modpow(modpow(2,n-1),m-1);
    return 0;
}