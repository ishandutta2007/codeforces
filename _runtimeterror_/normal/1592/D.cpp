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

const int N = 1005;
vector<int> v[N];

int _runtimeTerror_()
{
    int n;
    cin >> n;
    for(int i=1;i<=n-1;++i) {
        int x, y;
        cin >> x >> y;
        v[x].push_back(y),v[y].push_back(x);
    }
    vector<int> bfs = {1}, vis(n+1,0), par(n+1,0);
    vis[1] = 1;
    for(int i=0;i<bfs.size();++i) {
        int u = bfs[i];
        for(auto &j:v[u]) {
            if(vis[j]) {
                continue;
            }
            bfs.push_back(j);
            vis[j] = 1;
            par[j] = u;
        }
    }
    auto query = [&](int id) {
        cout << "? ";
        cout << id + 1 << " ";
        for(int i=0;i<=id;++i) {
            cout << bfs[i] << " ";
        }
        cout << "\n" << flush;
        int x;
        cin >> x;
        return x;
    };
    int lo = 1, hi = n-1, ans = -1;
    int val = query(n - 1);
    while(lo <= hi) {
        int mid = (lo + hi)/2;
        if(query(mid) == val) {
            ans = mid;
            hi = mid - 1;
        }
        else {
            lo = mid + 1;
        }
    }
    assert(ans != -1);
    cout << "! ";
    cout << bfs[ans] << " " << par[bfs[ans]] << "\n" << flush;
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