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


int _runtimeTerror_()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i=0;i<n;++i) {
        cin >> a[i];
    }
    sort(all(a));
    string s;
    cin >> s;
    vector<int> ans(n+1);
    vector<char> dir(n);
    dir[0] = s[0];
    ans[0] = 0;
    char heavy = s[0];
    for(int i=1;i<n;++i) {
        if(s[i] == heavy) {
            if(i & 1) {
                dir[i] = 'L' ^ 'R' ^ heavy;
                ans[i] += 0;
                ++ans[0];
                --ans[i];
            }
            else {
                dir[i] = heavy;
                ans[i] += 0;
                ++ans[0];
                --ans[i];
            }
        }
        else {
            ans[i] += i;
            dir[i] = s[i];
            ans[i+1] -= i;
        }
        heavy = s[i];
    }
    for(int i=1;i<n;++i) {
        ans[i] += ans[i-1];
    }
    // debug(ans);
    for(int i=0;i<n;++i) {
        cout << a[ans[i]] << " " << dir[i] << "\n";
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