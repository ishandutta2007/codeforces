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


int _runtimeTerror_()
{
    int n;
    cin >> n;
    vector<ll> a(n);
    for(int i=0;i<n;++i) {
        cin >> a[i];
    }
    vector<ll> ans(n);
    auto b = a;
    if(n % 2 == 0) {
        for(int i=0;i<n;i+=2) {
            ans[i] = a[i+1], ans[i+1] = -a[i];
        }
    }
    else {
        ll g = 0;
        for(int i=0;i<n;++i) {
            g = __gcd(g, abs(a[i]));
        }
        for(int i=0;i<n;++i) {
            a[i] /= g;
        }
        vector<int> id = {0};
        for(int i=1;i<n;++i) {
            if(abs(a[i]) != abs(a[0])) {
                id.push_back(i);
                for(int j=1;j<n;++j) {
                    if(j != i) {
                        id.push_back(j);
                    }
                }
                vector<ll> aa;
                for(int j=0;j<n;++j) {
                    aa.push_back(a[id[j]]);
                }
                a = aa;
                break;
            }
            if(i == n - 1) {
                for(int j=1;j<n;++j) {
                    id.push_back(j);
                }
            }
        }
        bool flip = false;
        if(abs(a[0] + a[1]) <= 1e4 and a[0] + a[1] != 0) {
            a[1] = a[0] + a[1];
        }
        else {
            a[1] = a[0] - a[1];
            flip = true;
        }
        for(int i=1;i<n;i+=2) {
            ans[i] = a[i+1], ans[i+1] = -a[i];
        }
        ans[0] = ans[1];
        if(flip) {
            ans[1] *= -1;
        }
        vector<ll> tmp(n);
        for(int j=0;j<n;++j) {
            tmp[id[j]] = ans[j];
        }
        ans = tmp;
    }
    ll sum = 0;
    for(int i=0;i<n;++i) {
        cout << ans[i] << " ";
        sum += b[i] * ans[i];
        assert(ans[i] != 0);
    }
    assert(sum == 0);
    cout << "\n";
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