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

int _runtimeTerror_()
{
    int n,W;
    cin>>n>>W;
    vector<int> cnt(21,0);
    for(int i=1;i<=n;++i)
    {
        int x;
        cin>>x;
        int pw = 0;
        while(x > 1)
            x /= 2,++pw;
        ++cnt[pw];
    }
    ll ans = 0;
    int rem = n;
    while(rem)
    {
        ll cur = W;
        for(int i=20;i>=0;--i)
        {
            if(cnt[i] == 0)
                continue;
            while(cnt[i] && (1ll<<i) <= cur)
            {
                cur -= 1ll<<i;
                --cnt[i];
                --rem;
            }
        }
        ++ans;
    }
    cout<<ans<<"\n";
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
    cin>>TESTS;
    while(TESTS--)
        _runtimeTerror_();
    return 0;
}