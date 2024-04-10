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

const int N = 100005;

vector<int> v[N];
int a[N], sub[N];

int t = 0;
bool ans = false;

int dfs(int s,int p) {
    sub[s] = a[s];
    int cnt = 0;
    for(auto &j:v[s]) {
        if(j == p) {
            continue;
        }
        cnt += dfs(j, s);
        sub[s] ^= sub[j];
    }
    if(cnt >= 2) {
        ans = true;
    }
    if(sub[s] == 0 && cnt >= 1) {
        ans = true;
    }   
    // debug(s, sub[s]);
    cnt += sub[s] == t;
    return cnt > 0;
}

int _runtimeTerror_()
{
    int n,k;
    cin >> n >> k;
    t = 0;
    ans = false;
    for(int i=1;i<=n;++i) {
        cin >> a[i];
        v[i].clear();
        sub[i] = 0;
        t ^= a[i];
    }
    for(int i=1;i<=n-1;++i) {
        int x,y;
        cin >> x >> y;
        v[x].push_back(y),v[y].push_back(x);
    }
    if(t == 0) {
        cout << "YES\n";
        return 0;
    }
    if(k == 2) {
        cout << "NO\n";
        return 0;
    }
    dfs(1,0);
    cout << (ans ? "YES" : "NO") << "\n";
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