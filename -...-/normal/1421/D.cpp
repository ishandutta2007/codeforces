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

int _runtimeTerror_()
{
    ll x,y;
    cin>>x>>y;
    vector<ll> a(6);
    for(int i=0;i<6;++i)
        cin>>a[i];
    vector<ll> v(6);
    for(int i=0;i<6;++i)
    {
        v[i] = a[i];
        amin(v[i],a[(i+1)%6]+a[(i+5)%6]);
    }
    if(x*y<=0)
    {
        ll ans = 0;
        if(y<0)
            ans -= v[4]*y;
        else
            ans += v[1]*y;
        if(x<0)
            ans -= v[2]*x;
        else
            ans += v[5]*x;
        cout<<ans<<"\n";
    }   
    else
    {
        ll ans = 0;
        if(x<0)
        {
            if(abs(x)>abs(y))
                ans += v[2]*(abs(x)-abs(y));
            else
                ans += v[4]*(abs(y)-abs(x));
            ans += min(abs(x),abs(y))*v[3];
        }
        else
        {
            if(abs(x)>abs(y))
                ans += v[5]*(abs(x)-abs(y));
            else
                ans += v[1]*(abs(y)-abs(x));
            ans += min(abs(x),abs(y))*v[0];
        }
        cout<<ans<<"\n";
    }
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