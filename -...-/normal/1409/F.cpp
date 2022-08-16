#include<bits/stdc++.h>
using namespace std ;

#define ll long long 
#define pb push_back
#define mem0(a) memset(a,0,sizeof(a))
#define mem1(a) memset(a,-1,sizeof(a))
#define memf(a) memset(a,false,sizeof(a))
#define all(v) v.begin(),v.end()
#define sz(a) (ll)a.size()
#define F first
#define S second
#define INF 2000000000000000000
#define endl "\n"
#define _time_ 1.0 * clock() / CLOCKS_PER_SEC
#define popcount(x) __builtin_popcountll(x)
#define pll pair<ll,ll> 
#define ld long double

const int M=1000000007;
const int MM=998244353;
const long double PI = acos(-1);

ll power(ll b,ll e,ll m)
{
    if(e==0) return 1;
    if(e&1) return b*power(b*b%m,e/2,m)%m;
    return power(b*b%m,e/2,m);
}
ll power( ll b, ll e)
{
    if(e==0) return 1;
    if(e&1) return b*power(b*b,e/2);
    return power(b*b,e/2);
}
template<typename T, typename U> static inline void amin(T &x, U y){ if(y<x) x=y; }
template<typename T, typename U> static inline void amax(T &x, U y){ if(x<y) x=y; }
template<typename T, typename U> ostream& operator<<(ostream &os, const pair<T, U> &p)
{ 
    return os<<'('<<p.F<< ","<<p.S<<')'; 
}

const int N = 205;
ll dp[N][N][N];

int _runtimeTerror_()
{
    // if t are equal
    ll n,k;
    string s,t;
    cin>>n>>k>>s>>t;
    for(int i=0;i<=n;++i)
        for(int j=0;j<=n;++j)
            for(int l=0;l<=k;++l)
                dp[i][j][l] = -INF;

    if(t[0]==t[1])
    {
        int cnt = 0;
        for(int i=0;i<n;++i)
            cnt += s[i]==t[0];
        ll x = min(n,cnt+k);
        cout<<(x*(x-1)/2)<<"\n";
        return 0;
    }
    dp[0][0][0] = 0;
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<=n;++j)
        {
            for(int l=0;l<=k;++l)
            {
                if(dp[i][j][l] == -INF)
                    continue;
                // chod dia
                if(s[i]==t[1])
                    amax(dp[i+1][j][l],dp[i][j][l]+j);
                else if(s[i]==t[0])
                    amax(dp[i+1][j+1][l],dp[i][j][l]);
                else
                    amax(dp[i+1][j][l],dp[i][j][l]);
                if(l==k)
                    continue;
                // first me kara
                if(s[i]==t[1])
                    amax(dp[i+1][j+1][l+1],dp[i][j][l]);
                else if(s[i]!=t[0])
                    amax(dp[i+1][j+1][l+1],dp[i][j][l]);
                // second me kara
                if(s[i]==t[0])
                    amax(dp[i+1][j][l+1],dp[i][j][l]+j);
                else if(s[i]!=t[1])
                    amax(dp[i+1][j][l+1],dp[i][j][l]+j);

            }
        }
    }
    // for(int i=1;i<=n;++i)
    // {
    //     for(int j=0;j<=n;++j)
    //     {
    //         for(int l=0;l<=k;++l)
    //             cout<<dp[i][j][l]<<" ";
    //         cout<<"\n";
    //     }
    //     cout<<"\n";
    // }
    ll ans = 0;
    for(int i=0;i<=n;++i)
        for(int j=0;j<=k;++j)
            amax(ans,dp[n][i][j]);
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
    //cin>>TESTS;
    while(TESTS--)
        _runtimeTerror_();
    return 0;
}