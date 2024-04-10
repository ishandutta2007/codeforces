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

#define runSieve
const int N=1000005;
bool prime[N];
ll pf[N];
void sieve()
{
    int k=sqrt(N-2);
    for(int i=1;i<=N-2;++i)
        prime[i]=true;
    for(int i=2;i<=k;++i)
    {
        if(prime[i])
        {
            for(int k=i*i;k<=N-2;k+=i)
            {
                prime[k]=false;
                pf[k]=i;
            }
        }
    }
}

char s[N];
int a[N], n;

ll dp[N];

vector<map<ll,ll>> st;

int _runtimeTerror_()
{
    cin >> n;
    for(int i=1;i<=n;++i) {
        cin >> a[i];
    }
    for(int i=1;i<=n;++i) {
        cin >> s[i];
    }
    auto get = [&](int x) {
        vector<pii> f;
        while(x > 1 && !prime[x]) {
            int z = pf[x];
            int cnt = 0;
            while(x % z == 0) {
                ++cnt;
                x /= z;
            }
            f.push_back({z, cnt});
        }
        if(x > 1) {
            f.push_back({x, 1});
        }
        return f;
    };
    st.push_back(map<ll,ll>());
    auto add = [&](map<ll,ll> &mp, int x,int c) {
        auto g = get(x);
        for(auto &[j,k]:g) {
            mp[j] += c * k;
        }
    };
    s[n+1] = '/';
    ll ans = 0;
    int prev = n + 1;
    dp[n+1] = n + 1;
    for(int i=n;i>=1;--i) {
        dp[i] = i;
        if(s[i] == '/') {
            continue;
        }
        if(s[i+1] == '/') {
            st.push_back(map<ll,ll>());
        }
        auto &mp = st.back();
        add(mp, a[i], 1);

        dp[i] = dp[i + 1];
        bool no = false;
        while(dp[i] <= n) {
            auto &mp = st.back();
            auto tmp = get(a[dp[i]]);
            for(auto &[j,k]:tmp) {
                if(!mp.count(j) || mp[j] < k) {
                    no = true;
                    break;
                }
            }
            if(no) {
                break;
            }
            add(mp, a[dp[i]], -1);
            if(s[dp[i] + 1] == '*') {                
                assert(sz(st) >= 2);
                auto &mp2 = st[sz(st) - 2];
                for(auto &[j, k]:mp) {
                    mp2[j] += k;
                }
                st.pop_back();
            }
            dp[i] = dp[dp[i] + 1];
        }
        ans += dp[i] - i;
    }
    dp[n+1] = 0;
    for(int i=n;i>=1;--i) {
        if(s[i] == '/') {
            if(a[i] == 1) {
                dp[i] = dp[i + 1] + 1;
                ans += dp[i];
            }
            else {
                dp[i] = 0;
            }
        }
        else {
            dp[i] = dp[i] - i;
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
    //cin >> TESTS;
    while(TESTS--)
        _runtimeTerror_();
    return 0;
}