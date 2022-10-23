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

int n, m, got = false;

set<pii> s;

int _runtimeTerror_()
{
    bool sp = false;
    cin >> n >> m;
    if(n > m) {
        swap(n, m);
        sp = 1;
    }
    int Q;
    cin >> Q;
    for(int i=1;i<=Q;++i) {
        int x, y;
        cin >> x >> y;
        if(sp) {
            swap(x, y);
        }
        s.insert({x, y});
    }

    vector<pii> q;
    int dep = 0;
    q.push_back({1, 1});
    while(!q.empty()) {

        vector<pii> new_q;

        for(auto &[x, y]:q) {
            if(x == n && y == m) {
                cout << dep << "\n";
                return 0;
            }
            int next = x + y + s.count({x, y});
            new_q.push_back({x, min(next, m)});
            new_q.push_back({min(next, n), y});
        }
        sort(all(new_q));
        q.clear();
        for(int i=0;i<new_q.size();++i) {
            int cur = i;
            while(i < new_q.size() && new_q[i].F == new_q[cur].F) {
                ++i;
            }
            --i;
            q.push_back(new_q[i]);
        }
        ++dep;
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