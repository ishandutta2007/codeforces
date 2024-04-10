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

const int N=100005,K=20;

int basis[N][K];
int cnt[N];
int a[N];

void insert(int i,int mask)
{
    for(int j=0;j<20;++j)
    {
        if(!(mask&(1<<j)))continue;

        if(!basis[i][j])
        {
            basis[i][j]=mask;
            ++cnt[i];
            break;
        }
        mask^=basis[i][j];
    }
}
bool go_(int i,int mask)
{
    for(int j=0;j<20;++j)
    {
        if(!(mask&(1<<j)))continue;

        if(!basis[i][j])
            return false;
        mask^=basis[i][j];
    }
    return true;
}

int _runtimeTerror_()
{
    int n,q;
    cin>>n>>q;
    for(int i=1;i<=n;++i)
        cin>>a[i];
    for(int i=1;i<=n;++i)
    {
        for(int j=0;j<20;++j)
            basis[i][j]=basis[i-1][j];
        cnt[i]=cnt[i-1];
        insert(i,a[i]);
    }
    for(int i=0;i<q;++i)
    {
        int l,x;
        cin>>l>>x;
        cout<<(go_(l,x)?(power(2,(l-cnt[l]),M)):0)<<"\n";
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