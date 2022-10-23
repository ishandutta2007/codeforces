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
    int n,q;
    cin>>n;
    map<int,int> m;
    vector<int> cnt(1e5+2,0);
    for(int i=0;i<n;++i)
    {
        int x;
        cin>>x;
        cnt[x]++;
    }
    for(int i=1;i<=1e5;++i)
    {
        if(cnt[i]>=8)
            ++m[8];
        if(cnt[i]>=6)
            ++m[6];
        if(cnt[i]>=4)
            ++m[4];
        if(cnt[i]>=2)
            ++m[2];
    }
    auto del=[&](int i) {

        if(cnt[i]>=8)
            --m[8];
        if(cnt[i]>=6)
            --m[6];
        if(cnt[i]>=4)
            --m[4];
        if(cnt[i]>=2)
            --m[2];
    };
    cin>>q;
    auto add=[&](int i) {
        if(cnt[i]>=8)
            ++m[8];
        if(cnt[i]>=6)
            ++m[6];
        if(cnt[i]>=4)
            ++m[4];
        if(cnt[i]>=2)
            ++m[2];
    };
    for(int i=0;i<q;++i)
    {
        char c;
        int x;
        cin>>c>>x;
        del(x);
        if(c=='+')
            ++cnt[x];
        else --cnt[x];
        add(x);
        if(m[8]>0 || (m[6]>0 && m[2]>1) || (m[4]>=2) || (m[4]>0 && m[2]>=3))
            cout<<"YES\n";
        else
            cout<<"NO\n";
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