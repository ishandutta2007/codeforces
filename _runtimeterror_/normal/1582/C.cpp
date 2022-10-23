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
    string s;
    cin >> s;
    int ans = -1;
    for(int x=0;x<26;++x) {
        char c = 'a' + x;
        string t;
        vector<int> l(n+1), r(n+1);
        int cnt = 0;
        for(int i=0;i<n;++i) {
            if(s[i] == c) {
                ++l[cnt];
            }
            else {
                ++cnt;
                t += s[i];
            }
        }
        int val = sz(t);
        bool pal = true;
        string tt = t;
        reverse(all(tt));
        if(t != tt) {
            continue;
        }
        cnt = 0;
        for(int i=n-1;i>=0;--i) {
            if(s[i] == c) {
                ++r[cnt];
            }
            else {
                ++cnt;
            }
        }
        for(int i=0;i<=n;++i) {
            val += min(l[i], r[i]);
        }
        if(val > 0) {
            amax(ans, val);
        }
    }
    if(ans == -1) {
        cout << "-1\n";
    }
    else {
        cout << n - ans << "\n";
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
    cin >> TESTS;
    while(TESTS--)
        _runtimeTerror_();
    return 0;
}