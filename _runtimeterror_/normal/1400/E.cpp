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

const int N = 5005;
int a[N];
int dp[N][20];
int logn[N];

int minx(int l,int r)
{
    int x = dp[l][logn[r-l+1]],y =dp[r+1-(1<<logn[r-l+1])][logn[r-l+1]];
    return (a[x]<=a[y]?x:y); 
}

int f(int l,int r,int sub)
{
    if(l>r)
        return 0;
    if(l==r)
        return ((a[l]-sub)>0);
    int x = minx(l,r);
    int ans = r-l+1;
    amin(ans,f(l,x-1,a[x])+f(x+1,r,a[x])+((a[x]-sub)));
    //amin(ans,f(l,x-1,sub)+f(x+1,r,sub)+1);
    return ans;
}

int _runtimeTerror_()
{
    ll n;
    cin>>n;
    for(int i=1;i<=n;++i)
        cin>>a[i];
    for(int len=0;len<=13;++len)
    {
        for(int i=1;i<=n;++i)
        {
            logn[i]=log2(i);
            if(i+(1<<len)>n+1)
                continue;
            if(len==0)
                dp[i][0]=i;
            else
            {
                int x = dp[i][len-1],y = dp[i+(1<<(len-1))][len-1];
                dp[i][len]=a[x]<=a[y]?x:y;
            }
        }
    }
    cout<<f(1,n,0);
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