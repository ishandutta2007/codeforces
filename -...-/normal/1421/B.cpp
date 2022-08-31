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
    vector<string> v(n);
    for(int i=0;i<n;++i)
        cin>>v[i];
    int x = v[0][1]-'0', y = v[1][0]-'0';
    int z = v[n-1][n-2]-'0', w = v[n-2][n-1]-'0';
    int cnt1 = (x!=0) + (y!=0) + (z!=1) + (w!=1);
    int cnt2 = (x!=1) + (y!=1) + (z!=0) + (w!=0);
    vector<pll> ans;
    if(cnt1<=2)
    {
        if(x!=0)
            ans.pb({1,2});
        if(y!=0)
            ans.pb({2,1});
        if(z!=1)
            ans.pb({n,n-1});
        if(w!=1)
            ans.pb({n-1,n});
    }
    else
    {
        assert(cnt2<=2);
        if(x!=1)
            ans.pb({1,2});
        if(y!=1)
            ans.pb({2,1});
        if(z!=0)
            ans.pb({n,n-1});
        if(w!=0)
            ans.pb({n-1,n});
    }
    cout<<sz(ans)<<"\n";
    for(auto j:ans)
        cout<<j.F<<" "<<j.S<<"\n";
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