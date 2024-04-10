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

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

template<typename T>
using ordered_set = tree<T , null_type ,less<T> ,rb_tree_tag ,tree_order_statistics_node_update>;

const int N = 1000005;

vector<int> l[N],r[N];
vector<pll> q[N];

int _runtimeTerror_()
{
    ll n,m;
    cin>>n>>m;
    ll ans=0;
    map<int,pair<int,int>> mp;
    for(int i=1;i<=n;++i)
    {
        int y,lx,rx;
        cin>>y>>lx>>rx;
        l[lx].pb(y);
        r[rx].pb(y);
        mp[y]={lx,rx};
        if(lx==0 && rx==1e6)
            ++ans;
    }
    for(int i=1;i<=m;++i)
    {
        int x,lx,rx;
        cin>>x>>lx>>rx;
        q[x].pb({lx,rx});
        if(lx==0 && rx==1e6)
            ++ans;
    }
    ordered_set<ll> s;
    for(int i=0;i<1e6;++i)
    {
        for(int j:l[i])
            s.insert(j);
        if(q[i].size()==1)
        {
            auto p=q[i][0];
            ans += s.order_of_key(p.S+1)-s.order_of_key(p.F);
        }
        for(int j:r[i])
            s.erase(j);
    }

    cout<<ans+1<<"\n";
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