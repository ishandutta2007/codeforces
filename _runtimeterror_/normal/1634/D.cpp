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


int _runtimeTerror_()
{
    int n;
    cin >> n;
    map<array<int, 3>, int> mp;
    auto ask = [&](int i, int j, int k) {
        array<int, 3> a = {i, j, k};
        sort(all(a));
        if(mp.count(a)) {
            return mp[a];
        }
        cout << "? " << i << " " << j << " " << k << "\n" << flush;
        int x;
        cin >> x;
        mp[a] = x;
        return x;  
    };
    int mx = 0;
    int id = 3, val = -1;
    for(int i=3;i<=n;++i) {
        if(ask(1, 2, i) > val) {
            val = ask(1, 2, i);
            id = i;
            amax(mx, ask(1, 2, i));
        }
    }
    int id2 = 1;
    val = -1;
    for(int i=3;i<=n;++i) {
        if(i == id) {
            continue;
        }
        if(ask(1, id, i) > val) {
            val = ask(1, id, i);
            id2 = i;
            amax(mx, ask(1, id, i));
        }
    }
    vector<int> a = {1, 2, id, id2};
    sort(all(a));
    // debug(a);
    do{
        int f = ask(a[0], a[1], a[2]);
        int g = ask(a[0], a[1], a[3]);
        if(f == mx && g == mx) {
            cout << "! " << a[0] << " " << a[1] << "\n" << flush;
            return 0;
        }
    }while(next_permutation(all(a)));
    assert(false);
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