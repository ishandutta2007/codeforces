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

const int N = 3001;
vector<int> v[N];
set<pair<pair<int,int>,int>> fb;

ll dis[N][N];
int n,m,k;

int _runtimeTerror_()
{
    cin>>n>>m>>k;
    for(int i=0;i<m;++i)
    {
        int x,y;
        cin>>x>>y;
        v[x].pb(y),v[y].pb(x);
    }
    for(int i=0;i<k;++i)
    {
        int a,b,c;
        cin>>a>>b>>c;
        fb.insert({{a,b},c});
    }
    for(int i=1;i<=n;++i)
        for(int j=1;j<=n;++j)
            dis[i][j] = INF;
    dis[1][1] = 0;
    queue<pll> q;
    q.push({1,1});
    while(!q.empty())
    {
        auto x = q.front();
        q.pop();
        for(int k:v[x.S])
        {
            if(dis[x.S][k]!=INF)
                continue;
            if(fb.count({{x.F,x.S},k}))
                continue;
            dis[x.S][k] = dis[x.F][x.S] + 1;
            q.push({x.S,k});
        }
    }
    int dist = 2e9;
    for(int i=1;i<=n;++i)
    {
        if(dis[i][n]<=dist)
        {
            dist = dis[i][n];
        }
    }
    if(dist>=2e9)
    {
        cout<<"-1\n";return 0;
    }
    vector<ll> ans;
    ans.pb(n);
    while(true)
    {
        if(ans.back()==1)
            break;
        for(int i=1;i<=n;++i)
        {
            if(dis[i][ans.back()]==dist)
            {
                ans.pb(i);
                break;
            }
        }
        --dist;
    }
    reverse(all(ans));
    cout<<sz(ans)-1<<"\n";
    for(auto j:ans)
        cout<<j<<" ";
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