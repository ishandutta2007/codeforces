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
#define INF 4000000000000000000
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

int _runtimeTerror_()
{
    ll n,m;
    cin>>n>>m;
    vector<pll> v(m);
    for(int i=0;i<m;++i)
        cin>>v[i].S>>v[i].F;
    sort(all(v),greater<pll>());
    ll ans=-INF;
    ll sum=0,cnt=0;
    set<pll> w;
    vector<ll> u;
    for(int i=0;i<m;++i)
    {
        sum+=v[i].S;
        ++cnt;
        u.pb(v[i].S);
        w.insert({v[i].S,i});
    }
    sort(all(u));
    vector<ll> uu(m+1);
    uu[m]=0;
    for(int i=m-1;i>=0;--i)
        uu[i]=uu[i+1]+u[i];
    /*auto f=[&](pll p){
        if(w.count(p))
        {
            sum-=p.S;
            --cnt;
            w.erase(p);
        }
    };*/
    for(int i=0;i<m;++i)
    {
        /*//f(v[i]);
        ll val=0;
        while(!w.empty() && w.size()>n-1 || w.begin()->F<v[i].F)
        {
            sum-=w.begin()->F;
            --cnt;
            w.erase(w.begin());
        }
        amax(ans,val+(n-cnt-1)*v[i].F+sum);
        cout<<ans<<"\n";*/
        auto it=lower_bound(all(u),v[i].F)-u.begin();
        ll val=v[i].S;
        ll rem=m-it;
        if(m-it>=n)
        {
            amax(ans,uu[m-n]);
            continue;
        }
        ll t=n-1-rem;
        //cout<<it<<" "<<it<<"\n";
        //cout<<"t "<<t<<"\n";
        if(v[i].S>=v[i].F)
            ++t,val=0;
        //cout<<"uu "<<uu[it]<<"\n";
        amax(ans,val+uu[it]+t*v[i].F);

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
    cin>>TESTS;
    while(TESTS--)
        _runtimeTerror_();
    return 0;
}