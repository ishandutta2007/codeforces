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

const int N = 200005;
ll a[N],b[N];

bool Q;
struct Line{
    // mx+c format
    mutable ll m,c,p;// p is the bound of abscissa of the line (right bound)
    bool operator<(const Line& o)const {
        return Q? p<o.p : m<o.m;
    }
};
struct LineContainer : multiset<Line> {
    const bool minmax;
    LineContainer(bool in): minmax(in){}
    const ll inf=LLONG_MAX;
    ll div(ll a,ll b){
        return a/b - ((a^b)<0 && a%b);
    }
    // terminating the lines
    // removing the faaltu lines
    bool isect(iterator x,iterator y)
    {
        if(y==end()){ x->p=inf ; return false;}
        if(x->m == y->m)x->p = x->c > y->c ?inf:-inf;
        else x->p = div(y->c - x->c ,x->m-y->m);
        return x->p>=y->p;
    }
    void add(ll m,ll c)
    {
        // x ke respect me mirror image
        if(minmax)
            m*=-1,c*=-1;
        auto z=insert({m,c,0});
        auto y=z++,x=y;
        while(isect(y,z)) z = erase(z);
        if(x!=begin() && isect(--x,y)) isect(x,y=erase(y));
        while((y=x)!=begin() && (--x)->p>=y->p) isect(x,erase(y));
    }
    ll query(ll x)
    {
        assert(!empty());
        Q=true ; auto l=*lower_bound({0,0,x});Q=false;
        return (minmax?-1:1)*(l.m*x+l.c);
    }
};

int _runtimeTerror_()
{
    ll n;
    cin>>n;
    for(int i=1;i<=n;++i)
        cin>>a[i];
    for(int i=1;i<=n;++i)
        b[i]=b[i-1]+i*a[i];
    for(int i=1;i<=n;++i)
        a[i]+=a[i-1];
    LineContainer hull(false);
    ll ans = 0;
    for(int i=n;i>=0;--i)
    {
        if(i==n)
        {
            hull.add(-a[i],b[i]);
            continue;
        }
        amax(ans,hull.query(i)-b[i]+i*a[i]);
        hull.add(-a[i],b[i]);
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