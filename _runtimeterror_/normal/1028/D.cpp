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
    int n;
    cin>>n;
    set<ll> buy,sell,both;
    ll ans = 1;
    auto inbuy = [&](ll x)
    {
        if(buy.empty())
            return false;
        return *buy.rbegin()>x;
    };
    auto insell = [&](ll x)
    {
        if(sell.empty())
            return false;
        return x>*sell.begin();
    };
    for(int i=1;i<=n;++i)
    {
        string s;
        ll p;
        cin>>s>>p;
        if(s=="ADD")
        {
            if(inbuy(p))
                buy.insert(p);
            else if(insell(p))
                sell.insert(p);
            else
                both.insert(p);
        }
        else
        {
            if(buy.count(p))
            {
                if(*buy.rbegin()!=p)
                {
                    ans = 0;
                    break;
                }
                else buy.erase(p);
                while(!both.empty())
                    sell.insert(*both.begin()),both.erase(*both.begin());
            }
            else if(sell.count(p))
            {
                if(*sell.begin()!=p)
                {
                    ans = 0;
                    break;
                }
                else
                    sell.erase(p);
                while(!both.empty())
                    buy.insert(*both.begin()),both.erase(*both.begin());
            }
            else
            {
                ans = (ans*2)%M;
                while(!both.empty() && *both.begin()<p)
                    buy.insert(*both.begin()),both.erase(both.begin());
                both.erase(both.begin());
                while(!both.empty())
                    sell.insert(*both.begin()),both.erase(both.begin());
            }
        }
    }
    ans = (ans * (sz(both)+1))%M;
    cout << ans << "\n";
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