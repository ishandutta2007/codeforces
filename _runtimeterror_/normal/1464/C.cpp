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

int _runtimeTerror_()
{
    ll n,T;
    cin>>n>>T;
    string s;
    cin>>s;
    ll x = (1LL<<(s.back()-'a'));
    T -= x;
    s.pop_back();
    x = (1LL<<(s.back()-'a'));
    T += x;
    s.pop_back();
    n -= 2;
    ll sum = 0;
    for(auto j:s)
        sum += (1LL<<(j-'a'));
    ll p = sum + T;
    if(p%2!=0)
    {
        cout<<"No\n";return 0;
    }
    p/=2;
    if(p==0)
    {
        cout<<"Yes\n";return 0;
    }
    if(p<0)
    {
        cout<<"No\n";return 0;
    }
    vector<int> cnt(61,0);
    for(auto j:s)
        ++cnt[j-'a'];
    for(int i=0;i<60;++i)
    {
        if(p&(1LL<<i))
        {
            if(cnt[i]==0)
            {
                cout<<"No\n";return 0;
            }
            --cnt[i];
            cnt[i+1] += cnt[i]/2;
        }
        else
            cnt[i+1] += cnt[i]/2;
    }
    cout<<"Yes\n";
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