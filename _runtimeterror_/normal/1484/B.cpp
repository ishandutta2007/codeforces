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
    vector<ll> a(n+1);
    ll c = -1,mc = -1;
    for(int i=1;i<=n;++i)
        cin>>a[i];
    int mx = a[1];
    for(int i=2;i<=n;++i)
    {
        if(a[i] >= a[i-1])
        {
            if(c == -1)
                c = a[i] - a[i-1];
            else if(a[i] - a[i-1] != c)
            {
                cout<<"-1\n";return 0;
            }
        }
        else
        {
            if(mc == -1)
                mc = a[i-1] - a[i];
            else if(a[i] - a[i-1] != -mc)
            {
                cout<<"-1\n";return 0;
            }
        }
        amax(mx,a[i]);
    }
    if(c != -1 && mc != -1 && c + mc <= mx)
    {
        cout<<"-1\n";return 0;
    }
    if(c == -1 || mc == -1)
    {
        cout<<"0\n";return 0;
    }
    cout<<c+mc<<" "<<c<<"\n";
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