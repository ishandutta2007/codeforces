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
    ll a,b,c,d;
    cin>>a>>b>>c>>d;
    vector<int> ans,ans2;
    auto f = [&]() {
        cout << "NO\n";exit(0);
    };
    if(b<a)
    {
        if(b==a-1 && c==0 && d==0)
        {
            cout<<"YES\n";
            while(b--)
                cout<<"0 1 ";
            cout<<"0\n";
            return 0;
        }
        f();
    }
    if(c<d)
    {
        if(c==d-1 && a==0 && b==0)
        {
            cout<<"YES\n";
            while(c--)
                cout<<"3 2 ";
            cout<<"3\n";
            return 0;
        }
        f();
    }
    b-=a;
    while(a--)
        ans.pb(0),ans.pb(1);
    c-=d;
    while(d--)
        ans2.pb(2),ans2.pb(3);
    ++d;
    if(abs(b-c)>1)
        f();
    cout<<"YES\n";
    if(b>c)
        cout<<"1 ",--b;
    else if(c>b)
        ans2.pb(2),--c;
    for(int j:ans)
        cout<<j<<" ";
    assert(b==c);
    while(b--)
        cout<<"2 1 ";
    for(int k:ans2)
        cout<<k<<" ";
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