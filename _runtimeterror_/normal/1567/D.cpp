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

//RNG based on mersenne_twister 
mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

int _runtimeTerror_()
{
    ll n,s;
    n = rng() % 100 + 1;
    s = n + rng() % 100000000;
    cin >> s >> n;
    // debug(s,n);
    vector<ll> pw(15,1);
    for(int i=1;i<15;++i)
        pw[i] = pw[i-1] * 10;
    vector<ll> ans;
    while(n)
    {
        bool got = false;
        for(int i=9;i>=0;--i)
        {
            for(int j=1;j>=1;--j)
            {
                ll x = j * pw[i];
                if(s - x >= n - 1) {
                    got = true;
                    ans.push_back(x);
                    s -= x;
                }
            }   
            if(got)
                break;
        }
        --n;
    }
    ans.back() += s;
    for(auto &j:ans)
        cout << j << " ";
    cout << "\n";
    // ll sum = accumulate(all(ans),0ll);
    // cout << sum << "\n";
    // cout << "\n";
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
    cin >> TESTS;
    while(TESTS--)
        _runtimeTerror_();
    return 0;
}