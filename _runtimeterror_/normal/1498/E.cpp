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
    int n;
    cin>>n;
    vector<pii> deg(n+1);
    for(int i=1;i<=n;++i)
    {
        cin>>deg[i].F;
        deg[i].S = i+1;
    }
    vector<pair<int,pii>> q;
    for(int i=1;i<=n;++i)
    {
        for(int j=i+1;j<=n;++j)
        {
            int x = i,y = j;
            if(deg[x].F > deg[y].F)
                swap(x,y);
            q.push_back({abs(deg[x].F-deg[y].F),{y,x}});
        }
    }
    sort(all(q));
    reverse(all(q));
    for(auto &[j,k]:q)
    {
        cout<<"? "<<k.F<<" "<<k.S<<"\n"<<flush;
        string u;
        cin>>u;
        if(u == "Yes")
        {
            cout<<"! "<<k.F<<" "<<k.S<<"\n"<<flush;
            return 0;
        }
    }
    cout<<"! 0 0\n"<<flush;
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