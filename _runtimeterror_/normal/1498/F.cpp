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

const int N = 100005;

int dp[N][20][2];
int n,k;


int ans[N][20][2];

int win[N],a[N];

vector<int> v[N];
// basic nim game
int dep[N];

void dfs(int s,int p)
{
    for(auto &j:v[s])
    {
        if(j!=p)
            dfs(j,s);
    }
    dp[s][0][0] = a[s];
    for(auto &j:v[s])
    {
        if(j == p)
            continue;
        for(int l=0;l<k-1;++l)
        {
            dp[s][l+1][0] ^= dp[j][l][0];
            dp[s][l+1][1] ^= dp[j][l][1];
        }
        dp[s][0][0] ^= dp[j][k-1][1];
        dp[s][0][1] ^= dp[j][k-1][0];
    }
}

void reroot(int s,int p)
{
    int x = 0;
    for(int i=0;i<k;++i)
        x ^= ans[s][i][1];
    win[s] = x > 0;
    for(auto &j:v[s])
    {
        if(j == p)
            continue;
        for(int i=0;i<k;++i)
        {
            ans[j][i][0] = ans[s][i][0],ans[j][i][1] = ans[s][i][1];
            if(i == 0)
                ans[j][i][0] ^= dp[j][k-1][1],ans[j][i][1] ^= dp[j][k-1][0];
            else
                ans[j][i][0] ^= dp[j][i-1][0], ans[j][i][1] ^= dp[j][i-1][1];
        }
        // if(j == 2)
        // {
        //     for(int i=0;i<k;++i)
        //     {
        //         cout<<ans[2][i][0]<<" "<<ans[2][i][1]<<"\n";
        //     }
        //     cout<<"---\n";
        // }
        int ux = ans[j][k-1][0],vx = ans[j][k-1][1];
        for(int i=k-1;i>=0;--i)
            ans[j][i][0] = ans[j][i-1][0],ans[j][i][1] = ans[j][i-1][1];
        // if(j == 2)
        // {
        //     for(int i=0;i<k;++i)
        //     {
        //         cout<<ans[2][i][0]<<" "<<ans[2][i][1]<<"\n";
        //     }
        //     cout<<"---\n";
        // }
        ans[j][0][0] = vx,ans[j][0][1] = ux;
        for(int i=0;i<k;++i)
            ans[j][i][0] ^= dp[j][i][0],ans[j][i][1] ^= dp[j][i][1];
        reroot(j,s);
    }
}

int _runtimeTerror_()
{
    cin>>n>>k;
    for(int i=0;i<n-1;++i)
    {
        int x,y;
        cin>>x>>y;
        v[x].push_back(y),v[y].push_back(x);
    }
    for(int i=1;i<=n;++i)
        cin >> a[i];
    dfs(1,0);
    for(int i=0;i<k;++i)
    {
        ans[1][i][0] = dp[1][i][0];
        ans[1][i][1] = dp[1][i][1];
    }
    reroot(1,0);
    // for(int i=0;i<k;++i)
    // {
    //     cout<<ans[1][i][0]<<" "<<ans[1][i][1]<<"\n";
    // }
    // cout<<"---\n";
    // for(int i=0;i<k;++i)
    // {
    //     cout<<ans[2][i][0]<<" "<<ans[2][i][1]<<"\n";
    // }
    for(int i=1;i<=n;++i)
        cout<<win[i]<<" ";
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