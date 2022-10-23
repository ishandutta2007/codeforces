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
    vector<int> a(n+1), cnt(n+1);
    vector<int> b;
    for(int i=1;i<=n;++i) {
        cin >> a[i];
        if(a[i] <= n && a[i] >= 1 && cnt[a[i]] == 0) {
            ++cnt[a[i]];
        }
        else {
            b.push_back(a[i]);
        }
    }
    sort(all(b), greater<ll>());
    int ans = 0;
    for(int i=1;i<=n;++i) {
        if(cnt[i] == 0) {
            if((b.back() - 1) / 2 >= i) {
                b.pop_back();
                ++ans;
            }
            else {
                cout << "-1\n";
                return 0;
            }
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
    cin >> TESTS;
    while(TESTS--)
        _runtimeTerror_();
    return 0;
}