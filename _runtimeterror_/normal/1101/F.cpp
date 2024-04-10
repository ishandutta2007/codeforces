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

const int N = 405;
int n,m;
ll a[N];
struct node {
    ll f,c,r;
};
vector<node> q[N];

ll dp[N][N];

int _runtimeTerror_()
{
    cin>>n>>m;
    for(int i=1;i<=n;++i)
        cin>>a[i];
    for(int i=1;i<=m;++i)
    {
        node x;
        int t;
        cin>>t>>x.f>>x.c>>x.r;
        q[t].pb(x);
    }
    ll ans = -INF;
    for(int l=1;l<=n;++l)
    {
        for(int r=l;r<=n;++r)
        {
            dp[r][0]=a[r]-a[l];
        }
        for(int j=1;j<=n;++j)
        {
            int cur = l;
            for(int r=l;r<=n;++r)
            {
                if(r==l)
                {
                    dp[r][j] = 0;
                    continue;
                }
                while(cur+1<r && max(dp[cur][j-1],a[r]-a[cur])>max(dp[cur+1][j-1],a[r]-a[cur+1]))
                    ++cur;
                //cout<<r<<" "<<cur<<"\n";
                dp[r][j] = max(dp[cur][j-1] , a[r]-a[cur]);
            }
            //cout<<"\n";
        }
        for(node x:q[l])
        {
            amax(ans,dp[x.f][x.r]*x.c);
            //cout<<x.f<<" "<<x.r<<" "<<x.c<<" "<<dp[x.f][x.r]<<"\n";
        }
    }
    //cout<<dp[4][1]<<"\n";
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