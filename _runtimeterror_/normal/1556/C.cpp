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

template<typename T, typename U> static inline void amin(T &x, U y){ if(y<x) x=y; }
template<typename T, typename U> static inline void amax(T &x, U y){ if(x<y) x=y; }

#ifdef LOCAL
#define debug(...) debug_out(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...) 2351
#endif


int _runtimeTerror_()
{
    int n;
    cin >> n;
    ll ans = 0;
    vector<ll> c(n+1);
    vector<ll> sum(n+1,0);
    for(int i=1;i<=n;++i)
    {
        cin >> c[i];
        sum[i] = sum[i-1];
        sum[i] += c[i] * (i % 2 == 1 ? 1 : -1);
    }
    // debug(sum);
    for(int i=1;i<=n;i+=2)
    {
        ll mn = 0;
        for(int j=i+1;j<=n;j+=2)
        {
            ll l = c[i], r = c[j];
            if(-mn > l)
                continue;
            ll cur = sum[j-1] - sum[i];
            cur -= mn;
            --cur;
            --r;
            l += mn;
            if(mn == 0)
                --l, ++cur;
            // debug(i,j,l,r,cur);
            if(cur >= 0) {
                if(r >= cur) {
                    ans += min(l, r - cur) + 1;
                }
            }
            else if(cur < 0) {
                cur *= -1;
                if(l >= cur) {
                    ans += min(r, l - cur) + 1;
                }
            }
            amin(mn,sum[j] - sum[i]);
        }
    }
    cout << ans << "\n";
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
    int TESTS = 1;
    //cin >> TESTS;
    while(TESTS--)
        _runtimeTerror_();
    return 0;
}