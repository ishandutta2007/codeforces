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


int _runtimeTerror_()
{
    int n,k;
    cin >> n >> k;
    vector<int> a(n);
    auto query = [&](int i,int j,bool OR)
    {
        cout << (OR ? "or":"and") << " " << i + 1 << " " << j + 1 << "\n" << flush;
        int x;
        cin >> x;
        return x;
    };
    vector<int> c(n),d(n);
    for(int i=1;i<n;++i) {
        c[i] = query(i,0,1);
        d[i] = query(i,0,0);
    }
    int sp = query(1,2,0);
    for(int i=29;i>=0;--i)
    {
        int cnt = 0;
        for(int j=1;j<n;++j)
            cnt += (c[j] & (1 << i)) > 0;
        if(cnt < n - 1) {
            for(int j=1;j<n;++j) {
                if(c[j] & (1 << i))
                    a[j] |= 1 << i;
            }
        }
        else
        {
            cnt = 0;
            for(int j=1;j<n;++j)
                cnt += (d[j] & (1 << i)) > 0;
            if(cnt == n-1) {
                for(int j=0;j<n;++j) {
                    a[j] |= 1 << i;
                }
            }
            else if(cnt > 0)
            {
                a[0] |= 1 << i;
                for(int j=1;j<n;++j) {
                    if(d[j] & (1 << i)) {
                        a[j] |= (1 << i);
                    }
                }
            }
            else {
                if(sp & (1 << i)) {
                    for(int j=1;j<n;++j) {
                        a[j] |= (1 << i);
                    }
                }
                else {
                    a[0] |= (1 << i);
                }
            }
        }
    }
    sort(all(a));
    cout << "finish " << a[k-1] << "\n" << flush;
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