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
const long double PI = acos(-1);

template<typename T, typename U> static inline void amin(T &x, U y){ if(y<x) x=y; }
template<typename T, typename U> static inline void amax(T &x, U y){ if(x<y) x=y; }
template<typename T, typename U> ostream& operator<<(ostream &os, const pair<T, U> &p)
{ 
    return os<<'('<<p.F<< ","<<p.S<<')'; 
}

int _runtimeTerror_()
{
    string s;
    cin>>s;
    int n = sz(s);
    vector<vector<int>> dp(n+1,vector<int>(4,1e8));
    if(n == 1)
    {
        cout<<"0\n";return 0;
    }
    if(s[0]!=s[1])
        dp[2][0] = 0;
    dp[2][1] = dp[2][2] = 1;
    dp[2][3] = 2;
    for(int i=3;i<=n;++i)
    {   
        // nothing
        if((s[i-1] != s[i-2]))
        {
            amin(dp[i][0],dp[i-1][2]);
            if(s[i-3]!=s[i-1] && s[i-3]!=s[i-2])
                amin(dp[i][0],dp[i-1][0]);
        }
        dp[i][3] = min(dp[i-1][1]+1,dp[i-1][3]+1);
        amin(dp[i][2],dp[i-1][3]);
        if(s[i-1]!=s[i-3])
        {
            amin(dp[i][2],dp[i-1][1]);
        }
        dp[i][1] = min({1+dp[i-1][0],1+dp[i-1][1],1+dp[i-1][2],1+dp[i-1][3]});
    }
    int ans = 1e8;
    for(int i=0;i<4;++i)
        amin(ans,dp[n][i]);
    cout<<ans<<"\n";
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
    int TESTS=1;
    cin>>TESTS;
    while(TESTS--)
        _runtimeTerror_();
    return 0;
}