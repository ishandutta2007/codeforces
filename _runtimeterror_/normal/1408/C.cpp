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
    ll n,l;
    cin>>n>>l;
    vector<int> v(n+1);
    for(int i=0;i<n;++i)
        cin>>v[i+1];
    v[0] = 0;
    v.pb(l);
    ld sum = 0;
    for(int i=n;i>=0;--i)
    {
        sum += 1.0*(v[i+1]-v[i])/(n+1-i);
    }
    ld sum2=0;
    cout<<fixed<<setprecision(10);
    for(int i=0;i<=n;++i)
    {
        sum -= 1.0*(v[i+1]-v[i])/(n+1-i);
        if(sum2<=sum)
        {
            ld v1 = i+1;
            ld v2 = n-i+1;
            ld dis = v[i+1]-v[i];
            dis -= (sum-sum2)*v1;
            if(dis>=-1e-9)
            {
                cout<<(dis)/(v1+v2)+sum<<"\n";return 0;
            }
        }
        else if(sum<=sum2)
        {
            ld v1 = i+1;
            ld v2 = n-i+1;
            ld dis = v[i+1]-v[i];
            dis -= (sum2-sum)*v2;
            if(dis>=-1e-9)
            {
                cout<<+(dis)/(v1+v2)+sum2<<"\n";return 0;
            }
        }
        sum2 += 1.0*(v[i+1]-v[i])/(i+1);
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