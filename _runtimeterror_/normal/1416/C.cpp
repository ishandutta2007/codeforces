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

const int N = 300005;
ll ans = 0;
ll a[N];

map<int,vector<int>> m,mm;

ll u=0,inv=0,inv2;

void go(vector<int> &v,int j,int val)
{
    ll cnt1=0,cnt0=0;
    u += sz(v)*(sz(v)-1)/2;
    for(auto k:v)
    {
        ll x = val + (k&(1<<j));
        mm[x].pb(k);
        if(k&(1<<j))
            ++cnt1,inv2+=cnt0;
        else
            inv += cnt1,++cnt0;
    }
}

int _runtimeTerror_()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;++i)
    {
        cin>>a[i];
        m[0].pb(a[i]);
    }
    ll inver=0,ans=0;
    for(int j=30;j>=0;--j)
    {
        u=0,inv=0,inv2=0;
        for(auto &k:m)
        {
            go(k.S,j,k.F);
        }
        // cout<<j<<" ";
        // cout<<u<<" "<<inv<<"\n";
        u -= inv;
        if(inv2<inv)
            ans |= (1<<j),swap(inv,inv2);
        inver += inv;
        // cout<<inver<<"\n";
        m.clear();
        m = mm;
        mm.clear();
    }
    cout<<inver<<" "<<ans<<"\n";
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