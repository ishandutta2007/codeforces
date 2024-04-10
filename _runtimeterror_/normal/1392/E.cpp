#include<bits/stdc++.h>
using namespace std ;

#define ll long long
#define int long long 
#define pb push_back
#define mem0(a) memset(a,0,sizeof(a))
#define mem1(a) memset(a,-1,sizeof(a))
#define memf(a) memset(a,false,sizeof(a))
#define all(v) v.begin(),v.end()
#define sz(a) (ll)a.size()
#define F first
#define S second
#define INF 2000000000000000000
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

ll a[30][30],n;

void dfs(int i,int j,ll k)
{
    cout<<i<<" "<<j<<endl;
    if(i==n && j==n)
        return ;
    if(i==n)
    {
        dfs(i,j+1,k);
        return ;
    }
    if(j==n)
    {
        dfs(i+1,j,k);
        return ;
    }
    ll onx=i,ony=j,onox=i,onoy=j;
    if(a[i+1][j]>0)
        onx=i+1,ony=j,onox=i,onoy=j+1;
    else
        onx=i,ony=j+1,onox=i+1,onoy=j;
    if(k&(1LL<<a[onx][ony]))
        dfs(onx,ony,k);
    else
        dfs(onox,onoy,k);
}

int _runtimeTerror_()
{
    cin>>n;
    for(int i=1;i<=25;++i)
    {
        int u = 54-i;
        for(int j=1;j<=25;++j)
        {
            if(j&1)
                a[i][j]=0;
            else a[i][j]=u,u-=2;
            //a[i][j]=(1LL<<a[i][j]);
        }
    }
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=n;++j)
        {
            cout<<(1LL<<a[i][j])<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    int q;
    cin>>q;
    while(q--)
    {
        ll k;
        cin>>k;
        dfs (1,1,k);
        cout<<endl;
    }
    return 0;
}

signed main()
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