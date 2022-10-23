#include<bits/stdc++.h>
using namespace std ;

#define ll              long long 
#define pb              push_back
#define all(v)          v.begin(),v.end()
#define sz(a)           (ll)a.size()
#define F               first
#define S               second
#define INF             2000000000000000000
#define popcount(x)     __builtin_popcountll(x)
#define pll             pair<ll,ll> 
#define pii             pair<int,int>
#define ld              long double

const int M = 1000000007;
const int MM = 998244353;
const long double PI = acos(-1);

template<typename T, typename U> static inline void amin(T &x, U y){ if(y<x) x=y; }
template<typename T, typename U> static inline void amax(T &x, U y){ if(x<y) x=y; }
template<typename T, typename U> ostream& operator<<(ostream &os, const pair<T, U> &p)
{ 
    return os<<'('<<p.F<< ","<<p.S<<')'; 
}

ll gcd(ll a, ll b, ll& x, ll& y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    ll x1, y1;
    ll d = gcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return d;
}

int _runtimeTerror_()
{
    ll n,m,k;
    cin>>n>>m>>k;
    vector<int> a(n+1),b(m+1);
    vector<int> l(2*max(n,m)+1),r(2*max(n,m)+1);
    for(int i=1;i<=n;++i)
    {
        cin>>a[i];
        l[a[i]] = i;
    }
    for(int i=1;i<=m;++i)
    {
        cin>>b[i];
        r[b[i]] = i;
    }
    const int X = 2*max(n,m)+10;
    vector<ll> ans(X,-1),mod(X);
    ll g = __gcd(n,m);
    ll gx, gy;
    gcd(n,m,gx,gy);
    for(int i=1;i<=X-10;++i)
    {
        if(l[i] == 0 || r[i] == 0)
            continue;
        if(abs(l[i] - r[i]) % g != 0)
            continue;
        mod[i] = n / g * m;
        ans[i] = ((l[i]-1)*m/g*gy + (r[i]-1)*n/g*gx)%mod[i];
        ans[i] = (ans[i] + mod[i])%mod[i];
        ++ans[i];
    }
    auto get = [&](ll x)
    {
        ll val = x;
        for(int i=1;i<=X-10;++i)
        {
            if(l[i] == 0 || r[i] == 0)
                continue;
            if(x >= ans[i] && ans[i] != -1)
            {
                // cout<<i<<" "<<ans[i]<<" "<<mod[i]<<"\n";
                --val;
                ll u = x - ans[i];
                val -= u / mod[i];
            }
        }
        // cout<<val<<"\n";
        return val >= k;
    };
    ll lo = 1,hi = 1e18,answer = -1;
    // cout<<get(5)<<"\n";
    while(lo<=hi)
    {
        ll mid = (lo+hi)/2;
        if(get(mid))
            answer = mid,hi = mid-1;
        else
            lo = mid+1;
    }
    cout<<answer<<"\n";
    return 0;
}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    #ifdef runSieve
        sieve();
    #endif
    #ifdef NCR
        initialize();
    #endif
    int TESTS=1;
    //cin>>TESTS;
    while(TESTS--)
        _runtimeTerror_();
    return 0;
}