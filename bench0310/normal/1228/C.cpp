#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const ll mod=1000000007;

ll fpow(ll b,ll e)
{
    ll res=1;
    while(e)
    {
        if(e&1) res=(res*b)%mod;
        b=(b*b)%mod;
        e/=2;
    }
    return res;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll x,n;
    cin >> x >> n;
    vector<ll> primes;
    for(ll i=2;i*i<=x;i++)
    {
        if((x%i)==0)
        {
            primes.push_back(i);
            while((x%i)==0) x/=i;
        }
    }
    if(x>1) primes.push_back(x);
    ll res=1;
    for(ll p:primes)
    {
        ll now=0;
        ll a=1;
        while(a<=n/p)
        {
            a*=p;
            now+=(n/a);
        }
        res=(res*fpow(p,now))%mod;
    }
    cout << res << "\n";
    return 0;
}