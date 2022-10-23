// Har Har Mahadev
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
#define debug(...) 2401
#endif

const int N = 200005;

int m[N], k[N];

ll cnt[N];

int _runtimeTerror_()
{
    int n;
    cin >> n;
    for(int i=1;i<=n;++i) {
        cin >> m[i] >> k[i];
    }
    ld mx = 0;
    vector<int> ans;
    for(int i=1;i<=20;++i) {
        for(int j=1;j<=n;++j) {
            cnt[m[j]] += min(k[j], i);
        }
        vector<pii> A;
        for(int j=1;j<=2e5;++j) {
            A.push_back({cnt[j],j});
        }
        sort(all(A));
        reverse(all(A));
        ll f = 0;
        vector<int> tmp;
        for(int j=0;j<i;++j) {
            f += A[j].F;
            tmp.push_back(A[j].S);
        }
        if(f * 1.0 / i > mx) {
            mx = f * 1.0/i;
            ans = tmp;
        }
        for(int j=1;j<=2e5;++j) {
            cnt[j] = 0;
        }
    }
    cout << sz(ans) << "\n";
    for(auto &j:ans) {
        cout << j << " ";
    }
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