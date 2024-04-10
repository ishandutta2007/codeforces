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
    ll x, y;
    cin >> x >> y;
    string s, t;
    while(x > 0) {
        s += char(x % 2 + '0');
        x /= 2;
    }
    reverse(all(s));
    while(y > 0) {
        t += char(y % 2 + '0');
        y /= 2;
    }
    reverse(all(t));
    if(s == t) {
        cout << "YES\n";
        return 0;
    }
    auto check = [&](string s, string t) {
        if(sz(s) > sz(t)) {
            return;
        }
        string x = s;
        reverse(all(x));
        for(int i=0;i<sz(t) - sz(s) + 1;++i) {
            if(t.substr(i, sz(s)) == s || t.substr(i, sz(s)) == x) {
                bool good = true;
                for(int k=0;k<i;++k) {
                    if(t[k] == '0') {
                        good = false;
                    }
                }
                for(int k=i+sz(s);k<sz(t);++k) {
                    if(t[k] == '0') {
                        good = false;
                    }
                }
                if(good) {
                    cout << "YES\n";
                    exit(0);
                }
            }
        }
    };
    check(s + "1", t);
    while(s.back() == '0') {
        s.pop_back();
    }
    check(s, t);
    cout << "NO\n";
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