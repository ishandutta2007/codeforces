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

template<typename T>
struct fenwick {
    vector<T> bit;
    int n;
    void build(int n_)
    {
        n = n_;
        bit.resize(n+1);
        for(int i=1;i<=n;++i)
            bit[i] = T(0);
    }
    void update(int pos,T val)
    {
        for(;pos<=n;pos+=pos&-pos)
            bit[pos] = (bit[pos] + val)%M;
    }
    T get(int r)
    {
        T x{};
        for(;r;r-=r&-r)
            x = (x+bit[r])%M;
        return x;
    }
    T query(int l,int r)
    {
        return (get(r)-get(l-1)+M)%M;
    }
};

fenwick<ll> fenw1,fenw2;

const int N = 5e5+5;
int b[N];
ll a[N];

int _runtimeTerror_()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;++i)
        cin>>a[i],b[i]=i;
    sort(b+1,b+1+n,[&](int x,int y){return a[x]<a[y];});
    ll ans = 0;
    fenw1.build(n);
    fenw2.build(n);
    for(int i=1;i<=n;++i)
    {
        fenw1.update(b[i],b[i]);
        fenw2.update(b[i],n-b[i]+1);
        ll u = 1LL*(fenw1.get(b[i]))*(n-b[i]+1)%M;
        u += 1LL*b[i]*(fenw2.query(b[i]+1,n))%M;
        u %= M;
        ans += a[b[i]]*1LL*u%M;
        ans %= M;
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