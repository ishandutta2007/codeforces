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

const int N = 42;

bool dp[N][N][N][N];

int _runtimeTerror_()
{
    int n, A, B;
    cin >> n >> A >> B;
    string s;
    cin >> s;
    for(int l=0;l<=n;++l) {
        for(int i=0;i<=n;++i) {
            for(int j=0;j<A;++j) {
                for(int k=0;k<B;++k) {
                    dp[l][i][j][k] = 0;
                }
            }
        }
    }
    dp[0][0][0][0] = 1;
    for(int i=0;i<n;++i) {
        for(int j=0;j<=i;++j) {
            for(int k=0;k<A;++k) {
                for(int l=0;l<B;++l) {
                    if(!dp[i][j][k][l]) {
                        continue;
                    }
                    // to A
                    dp[i+1][j+1][(k * 10 + s[i] - '0') % A][l] = 1;
                    // to B
                    dp[i+1][j][k][(l * 10 + s[i] - '0') % B] = 1;
                }
            }
        }
    }
    int a_cnt = -1, amod = -1, bmod = -1;
    for(int i=1;i<n;++i) {
        if(dp[n][i][0][0]) {
            if(a_cnt == -1) {
                a_cnt = i,amod = 0, bmod = 0;
            }
            else if(abs(2 * i - n) < abs(2 * a_cnt - n)) {
                a_cnt = i,amod = 0, bmod = 0;   
            }
        }
    }
    if(a_cnt == -1) {
        cout << "-1\n";
        return 0;
    }
    // debug(a_cnt,amod,bmod);
    string ans(n,'R');

    for(int i=n;i>=1;--i) {
        bool done = false;
        for(int j=0;j<=a_cnt;++j) {
            for(int k=0;k<A;++k) {
                for(int l=0;l<B;++l) {
                    if(dp[i-1][j][k][l] == 0 || abs(j - a_cnt) > 1) {
                        continue;
                    }
                    int geta = (k * 10 + s[i-1] - '0') % A;
                    int getb = (l * 10 + s[i-1] - '0') % B;
                    if(geta == amod && j == a_cnt - 1 && l == bmod) {
                        ans[i-1] = 'R';
                        amod = k, a_cnt = j;
                        done = true;
                        // debug(i,j,k,l);
                        break;
                    }
                    else if(getb == bmod && j == a_cnt && k == amod) {
                        ans[i-1] = 'B';
                        bmod = l, a_cnt = j;
                        done = true;
                        // debug(i,j,k,l);
                        break;
                    }
                }
                if(done) {
                    break;
                }
            }
            if(done) {
                break;
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