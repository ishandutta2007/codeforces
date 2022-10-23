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


// 

int _runtimeTerror_()
{
    int n, m;
    cin >> n >> m;
    vector<int> x(n+1), y(n+1);
    for(int i=1;i<=n;++i) {
        cin >> x[i] >> y[i];
    }
    vector<int> psum(m+5), last(n+1);
    const int B = 20;
    vector<vector<int>> tmp(B+1,vector<int>(B + 1));
    for(int i=1;i<=m;++i) {
        int op,k;
        cin >> op >> k;
        if(op == 1) {
            if(y[k] + x[k] > B) {
                for(int cur=i+x[k];cur<=m;cur+=x[k] + y[k]) {
                    ++psum[cur];
                    --psum[min(m+1,cur + y[k])];
                }
            }
            else {
                for(int j=x[k];j<=x[k] + y[k] - 1;++j) {
                    ++tmp[x[k] + y[k]][(i + j) % (x[k] + y[k])];
                }
            }
            last[k] = i;
        }
        else {
            if(y[k] + x[k] > B) {
                for(int cur=last[k]+x[k];cur<=m;cur+=x[k] + y[k]) {
                    if(cur + y[k] < i) {
                        continue;
                    }
                    --psum[max(cur,i)];
                    ++psum[min(m+1,cur + y[k])];
                }
            }
            else {
                for(int j=x[k];j<=x[k] + y[k] - 1;++j) {
                    --tmp[x[k] + y[k]][(last[k] + j) % (x[k] + y[k])];
                }
            }
        }
        psum[i] += psum[i-1];
        int ans = psum[i];
        for(int j=1;j<=B;++j) {
            ans += tmp[j][i % j];
        }
        cout << ans << "\n";
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