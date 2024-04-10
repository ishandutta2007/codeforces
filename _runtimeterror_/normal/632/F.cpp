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

#define pii pair<int,int>

const int N = 2505;
bitset<2501> row[N],col[N];
int a[N][N];

int _runtimeTerror_()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;++i)
        for(int j=1;j<=n;++j)
            cin>>a[i][j];
    vector<pii> v;
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=n;++j)
        {
            if((i==j && a[i][j]) || (a[i][j] != a[j][i]))
            {
                cout<<"NOT MAGIC\n";
                return 0;
            }
            v.pb({i,j});
        }
    }
    sort(all(v),[&](pii x,pii y)
    {
        return a[x.F][x.S]>a[y.F][y.S];
    });
    auto check = [&](int i,int j)
    {
        int x = (row[i]|col[j]).count();
        return x == n;
    };
    int i=0,j=0;
    while(j<n*n)
    {
        while(j<n*n && a[v[j].F][v[j].S]==a[v[i].F][v[i].S])
        {
            row[v[j].F][v[j].S] = 1,col[v[j].S][v[j].F] = 1;
            ++j;
        }
        while(i<j)
        {
            if(!check(v[i].F,v[i].S))
            {
                cout<<"NOT MAGIC\n";
                return 0;
            }
            ++i;
        }
    }
    cout<<"MAGIC\n";
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