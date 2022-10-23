#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define ld long double
#define pii pair<ll,ll>
#define fi first
#define se second
#define pb push_back
#define arr vector<ll>
const ll maxn=1e5+1,msiz=2,inf=1e18;
ll mod;

bool prime(int n)
{
    if (n==1) return 0;
    for (int i=2;i*i<=n;i++)
        if (n%i==0) return 0;
    return 1;
}

ll product(ll obj1, ll obj2)
{
    return (obj1*obj2)%mod;
}

ll modpow(ll x,ll h)
{
    ll res=1;
    for (;h;h>>=1)
    {
        if (h&1) res=product(res,x);
        x=product(x,x);
    }
    return res;
}

ll inverse(ll x)
{
    return modpow(x,mod-2);
}

int main()
{
    //freopen("ss.inp","r",stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll n;
    cin>>n;
    if (n==1)
    {
        cout<<"YES\n1";
        return 0;
    }
    if (n==4)
    {
        cout<<"YES\n1 3 2 4";
        return 0;
    }
    if (!prime(n))
    {
        cout<<"NO";
        return 0;
    }
    mod=n;
    cout<<"YES\n1 ";
    for (ll i=2;i<n;i++) cout<<(i*inverse(i-1))%mod<<" ";
    cout<<n;
    return 0;
}