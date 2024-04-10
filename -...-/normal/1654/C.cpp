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

template<typename T, typename U> static inline void amin(T &x, U y){ if(y < x) x = y; }
template<typename T, typename U> static inline void amax(T &x, U y){ if(x < y) x = y; }

#ifdef LOCAL
#define debug(...) debug_out(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...) 2401
#endif


int _runtimeTerror_()
{
    int n;
    cin >> n;
    vector<ll> a(n);
    map<ll, ll> mp;
    ll w = 0;
    for(int i=0;i<n;++i) {
        cin >> a[i];
        ++mp[a[i]];
        w += a[i];
    }
    vector<ll> q = {w};
    int br = 0;
    for(int i=0;i<q.size();++i) {
        ll u = q[i];
        if(mp[u] > 0) {
            --mp[u];
            continue;
        }
        if(u == 1) {
            continue;
        }
        ++br;
        q.push_back(u / 2);
        q.push_back((u + 1)/2);
        if(br >= n) {
            break;
        }
    }
    for(auto &[i, j]:mp) {
        if(j > 0) {
            cout << "NO\n";
            return 0;
        }
    }
    cout << "YES\n";
    return 0;
}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    #ifdef runSieve
        sieve();
    #endif
    #ifdef NCR
        initncr();
    #endif
    int TESTS = 1;
    cin >> TESTS;
    while(TESTS--) {
        _runtimeTerror_();
    }
    return 0;
}