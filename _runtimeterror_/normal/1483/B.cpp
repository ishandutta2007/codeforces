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
template<typename T=long long>
struct fenwick {
    T a[N],bit[N];
    int n;
    fenwick() 
    {
        for(int i=1;i<=N-2;++i)
            a[i] = T(0),bit[i] = T(0);
    }
    void build(int n_)
    {
        n = n_;
        for(int i=1;i<=n;++i)
            bit[i] = 0;
    }
    void update(int j,T val)
    {
        for(;j<=n;j+=j&-j)
            bit[j] += val;
    }
    T get(int r)
    {
        T u = 0;
        for(;r;r-=r&-r)
            u += bit[r]; 
        return u;
    }
    T query(int l,int r)
    {
        return get(r)-get(l-1);
    }
};
// call fenw.build(n);

fenwick<int> fenw;

int _runtimeTerror_()
{
    int n;
    cin>>n;
    vector<int> a(n+1);
    for(int i=1;i<=n;++i)
        cin>>a[i];
    vector<int> ans;
    vector<int> l(n+1),r(n+1);
    for(int i=1;i<=n;++i)
        l[i] = i-1;
    l[1] = n;
    for(int i=1;i<=n;++i)
        r[i] = i+1;
    r[n] = 1;
    set<int> bad;
    for(int i=2;i<=n;++i)
    {
        if(__gcd(a[i],a[i-1]) == 1)
            bad.insert(i);
    }
    if(__gcd(a[1],a[n]) == 1)
        bad.insert(1);
    // fenw.build(n);
    // for(int i=1;i<=n;++i)
    //     fenw.update(i,1);
    int rem = n;
    int cur = 2;
    // for(auto &j:bad)
        // cout<<j<<" ";
    // cout<<"\n\n";
    while(!bad.empty())
    {
        auto it = bad.lower_bound(cur);
        if(it == bad.end())
        {
            // assert(false);
            cur = 1;
            continue;
        }
        --rem;
        int id = *it;
        bad.erase(it);
        // cout<<id<<"\n";
        // cout<<fenw.get(id)<<"\n";
        // a[id] = -1;
        ans.push_back(id);
        if(rem == 0)
            break;
        // fenw.update(id,-1);
        // assert(l[id] != id && r[id] != id);
        // cout<<l[id]<<" "<<r[id]<<"\n";
        if(__gcd(a[id],a[r[id]]) == 1)
            bad.erase(r[id]);
        if(__gcd(a[l[id]],a[r[id]]) == 1)
            bad.insert(r[id]);
        l[r[id]] = l[id];
        r[l[id]] = r[id];
        cur = r[r[id]];
    }
    cout<<sz(ans)<<" ";
    for(auto &j:ans)
        cout<<j<<" ";
    cout<<"\n";
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
    cin>>TESTS;
    while(TESTS--)
        _runtimeTerror_();
    return 0;
}