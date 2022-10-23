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

const int N = 100005;
ll a[N];

int _runtimeTerror_()
{
    int n,q;
    cin>>n>>q;
    for(int i=1;i<=n;++i)
        cin>>a[i];
    sort(a+1,a+n+1);
    multiset<ll> s,d;
    for(int i=1;i<=n;++i)
    {
        s.insert(a[i]);
    }
    for(int i=1;i<=n-1;++i)
        d.insert(a[i+1]-a[i]);
    ll ans = *s.rbegin() - *s.begin();
    if(!d.empty())
        ans -= *d.rbegin();
    cout<<ans<<"\n";
    for(int i=0;i<q;++i)
    {
        int tt,x;
        cin>>tt>>x;
        if(tt==1)
        {
            auto it = s.lower_bound(x);
            ll dif = -1;
            if(it!=s.begin() && it!=s.end())
            {
                ll r = *it;
                --it;
                ll l = *it;
                d.erase(d.find(r-l));
                d.insert(r-x);
                d.insert(x-l);
            }
            else
            {
                if(it==s.begin() && sz(s)>0)
                    d.insert(*s.begin()-x);
                else if(it==s.end() && sz(s)>0)
                    d.insert(x-*s.rbegin());
            }
            s.insert(x);
        }
        else
        {
            auto it = s.lower_bound(x);
            ll dif = -1;
            if(x!=*s.begin() && x!=*s.rbegin())
            {
                ++it;
                ll r = *it;
                --it;
                --it;
                ll l = *it;
                d.erase(d.find(x-l));
                d.erase(d.find(r-x));
                d.insert(r-l);
                s.erase(x);
            }
            else
            {
                if(x==*s.begin() && sz(s)>1)
                {
                    s.erase(x);
                    d.erase(d.find(*s.begin()-x));
                }
                else if(x==*s.rbegin() && sz(s)>1)
                {
                    s.erase(x);
                    d.erase(d.find(x-*s.rbegin()));
                }
                s.erase(x);
            }
        }
        ll ans = 0;
        if(!s.empty())
            ans += *s.rbegin() - *s.begin();
        if(!d.empty())
            ans -= *d.rbegin();
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
    //cin>>TESTS;
    while(TESTS--)
        _runtimeTerror_();
    return 0;
}