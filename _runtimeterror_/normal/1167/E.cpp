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

ll n,x;
const int N = 1e6+5;
vector<ll> v[N];

ll pfx[N],sfx[N];

int _runtimeTerror_()
{
    cin>>n>>x;  
    for(int i=1;i<=n;++i)
    {
        int l;
        cin>>l;
        v[l].pb(i);
    }
    for(int i=1;i<=x;++i)
    {
        ll mi = INF,mx = -INF;
        for(int j:v[i])
            amax(mx,j),amin(mi,j);
        if(mi>pfx[i-1])
            pfx[i] = max(mx,pfx[i-1]);
        else 
        {
            pfx[i] = -1;
            for(int j=i+1;j<=x;++j)
                pfx[j] = -1;
            break;
        }
    }
    sfx[x+1]=n+1;
    for(int i=x;i>=1;--i)
    {
        ll mi = INF,mx = -INF;
        for(int j:v[i])
            amax(mx,j),amin(mi,j);
        if(mx<sfx[i+1])
            sfx[i] = min(mi,sfx[i+1]);
        else 
        {
            sfx[i] = -1;
            for(int j=i-1;j>=1;--j)
                sfx[j] = -1;
            break;
        }
    }
    ll ans = 0;
    auto f=[&](int m,int i) {
        return sfx[m+1]>pfx[i-1];
    };
    for(int i=1;i<=x;++i)
    {
        if(pfx[i-1]==-1)
            break;
        int lo=i,hi=x,val=-1;
        while(lo<=hi)
        {
            int m = (lo+hi)/2;
            if(f(m,i))
                val = m,hi=m-1;
            else lo=m+1;
        }
        if(val!=-1)
            ans += 1LL*(x-val+1);
    }
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