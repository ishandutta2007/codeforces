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

template<typename T, typename U> static inline void amin(T &x, U y){ if(y < x) x = y; }
template<typename T, typename U> static inline void amax(T &x, U y){ if(x < y) x = y; }

#ifdef LOCAL
#define debug(...) debug_out(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...) 3000
#endif


int _runtimeTerror_()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i=0;i<n;++i) {
        cin >> a[i];
    }
    sort(all(a));
    auto check = [&](int f) {
        vector<int> c, d;
        for(int i=0;i<f;++i) {
            c.push_back(a[i]);
        }
        for(int i=f;i<n;++i) {
            d.push_back(a[i]);
        }
        vector<int> t;
        if(sz(c) == sz(d)) {
            for(int i=0;i<f;++i) {
                t.push_back(c[i]);
                t.push_back(d[i]);
            }
        }
        else {
            if(sz(d) > sz(c)) {
                swap(c, d);
            }
            t.push_back(c[0]);
            for(int i=0;i<f;++i) {
                t.push_back(d[i]);
                t.push_back(c[i + 1]);
            }
        }
        for(int i=0;i<n;++i) {
            int prev = (i - 1 + n) % n, nxt = (i + 1) % n;
            if(t[i] > t[prev] and t[i] > t[nxt]) {
                continue;
            }
            if(t[i] < t[prev] and t[i] < t[nxt]) {
                continue;
            }
            return vector<int>(1, -1);
        }
        return t;
    };
    auto f = check(n / 2), g = check((n + 1) / 2);
    if(f[0] == -1) {
        f = g;
    }
    if(f[0] == -1) {
        cout << "NO\n";
        return 0;
    }
    cout << "YES\n";
    for(auto i:f) {
        cout << i << " ";
    }
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
        initncr();
    #endif
    int TESTS = 1;
    cin >> TESTS;
    while(TESTS--) {
        _runtimeTerror_();
    }
    return 0;
}