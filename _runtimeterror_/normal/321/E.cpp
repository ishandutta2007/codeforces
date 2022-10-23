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

int n,k;
const int N = 4005;
int a[N][N],cost[N][N];
int dp[N][802];

void go_(int l,int r,int k,int optl,int optr)
{
    if(l>r)
        return ;
    int mid = (l+r)/2;
    pair<int,int> ans = {1e9,1e9};
    for(int i=optl;i<=min(mid-1,optr);++i)
        amin(ans,make_pair(dp[i][k-1]+cost[i+1][mid],i));
    dp[mid][k] = ans.F;
    go_(l,mid-1,k,optl,ans.S);
    go_(mid+1,r,k,ans.S,optr);
}

int _runtimeTerror_()
{
    cin>>n>>k;
    char c;
    for(int i=1;i<=n;++i)
        for(int j=1;j<=n;++j)
            cin>>c,a[i][j]=c-'0';
    for(int i=1;i<=n;++i)
        for(int j=1;j<=n;++j)
            a[i][j] += a[i-1][j] + a[i][j-1] - a[i-1][j-1];
    for(int i=1;i<=n;++i)
    {
        for(int j=i+1;j<=n;++j)
        {
            cost[i][j]=(a[j][j] - a[i-1][j] - a[j][i-1] + a[i-1][i-1])/2;
        }
    }
    for(int i=1;i<=n;++i)
        for(int j=0;j<=k;++j)
            dp[i][j]=1e9;
    dp[0][0]=0;
    for(int i=1;i<=k;++i)
        go_(1,n,i,0,n);
    cout<<dp[n][k]<<"\n";
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