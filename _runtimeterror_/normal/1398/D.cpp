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

const int N=202;

ll R[N],B[N],G[N];
ll dp[N][N][N];

int _runtimeTerror_()
{
    ll r,g,b;
    cin>>r>>g>>b;
    for(int i=1;i<=r;++i)
        cin>>R[i];
    for(int i=1;i<=g;++i)
        cin>>G[i];
    for(int i=1;i<=b;++i)
        cin>>B[i];
    sort(R+1,R+1+r);
    sort(G+1,G+1+g);
    sort(B+1,B+1+b);
    for(int i=0;i<=r;++i)
    {
        for(int j=0;j<=g;++j)
        {
            for(int k=0;k<=b;++k)
            {
                if(i==0 && j==0 && r==0)
                    continue;
                if(i>=1 && j>=1 && k>=1)
                    amax(dp[i][j][k],dp[i-1][j-1][k-1]);
                if(i>=1 && j>=1)
                    amax(dp[i][j][k],R[i]*G[j]+dp[i-1][j-1][k]);
                if(i>=1 && k>=1)
                    amax(dp[i][j][k],R[i]*B[k]+dp[i-1][j][k-1]);
                if(k>=1 && j>=1)
                    amax(dp[i][j][k],B[k]*G[j]+dp[i][j-1][k-1]);
            }
        }
    }
    //cout<<dp[2][1][1]<<"\n";
    cout<<dp[r][g][b]<<"\n";
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