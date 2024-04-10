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
#define debug(...) 2401
#endif

const int N = 4e7 + 2e5;

int mp[N];
const int sh = 4e7;

int _runtimeTerror_()
{
    int n = 1e5;
    cin >> n;
    vector<int> a(n, 1);
    int ans = 1;
    for(int i=0;i<n;++i) {
        cin >> a[i];
    }
    auto solve = [&](vector<int> &a) {
        int sq = 350;
        // sq = 2;
        for(int i=0;i<=sq;++i) {
            for(int j=0;j<n;++j) {
                ++mp[a[j] - j * i + sh];
                amax(ans, mp[a[j] - j * i + sh]);
            }
            for(int j=0;j<n;++j) {
                --mp[a[j] - j * i + sh];
            }
        }
        if(ans == n) {
            return;
        }
        vector<int> cnt(1e5 + 1, 0);
        for(int i=0;i<n;++i) {
            for(int j=i+1;j<min(n, i+(100000/sq) + 1);++j) {
                if(a[j] > a[i] && (a[j] - a[i]) % (j - i) == 0) {
                    int tmp = (a[j] - a[i]) / (j - i);
                    ++cnt[tmp];
                    amax(ans, cnt[tmp] + 1);
                }
            }
            for(int j=i+1;j<min(n, i+(100000/sq) + 1);++j) {
                if(a[j] > a[i] && (a[j] - a[i]) % (j - i) == 0) {
                    int tmp = (a[j] - a[i]) / (j - i);
                    --cnt[tmp];
                }
            }
        }
    };

    solve(a);
    reverse(all(a));
    solve(a);
    cout << n - ans << "\n";
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
    //cin >> TESTS;
    while(TESTS--) {
        _runtimeTerror_();
    }
    return 0;
}