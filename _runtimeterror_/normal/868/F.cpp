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

const int N = 100005;
ll dp[N][22];
ll a[N];
int f[N];

ll n,k;

int curL = 1,curR = 0;

struct Node
{
    int l,r,optl,optr;
};
queue<Node> q;

ll ans = 0;

void go_(int k)
{
    int curLevel = -1;

    auto add=[&](int i)
    {
        ans += f[a[i]];
        ++f[a[i]];
    };
    auto del = [&](int i)
    {
        --f[a[i]];
        ans -= f[a[i]];
    };
    while(!q.empty())
    {
        Node u = q.front();
        q.pop();
        if(u.l>u.r)
            continue;
        int mid = (u.l+u.r)/2;
        pll mx = {INF,mid};
        while(curR>mid)
            del(curR--);
        while(curR<mid)
            add(++curR);
        while(curL<u.optl)
            del(curL++);
        while(curL>u.optl)
            add(--curL);
        while(curL<=min(mid,u.optr+1))
        {
            mx = min(mx,make_pair(ans + dp[curL-1][k-1],(ll)curL));
            del(curL++);
        }
        dp[mid][k] = mx.F;
        Node x;
        x.l = u.l,x.r = mid-1,x.optl = u.optl,x.optr = mx.S;
        q.push(x);
        x.l = mid+1,x.r = u.r,x.optl = mx.S,x.optr = u.optr;
        q.push(x);
    }
}

int _runtimeTerror_()
{
    cin>>n>>k;
    for(int i=1;i<=n;++i)
        for(int j=0;j<=k;++j)
            dp[i][j]=INF;

    dp[0][0]=0;

    for(int i=1;i<=n;++i)
        cin>>a[i];

    for(int i=1;i<=k;++i)
    {
        Node u;
        u.l = 1,u.r = n,u.optl = 1,u.optr = n;
        q.push(u);
        go_(i);
        assert(q.empty());
    }
    cout << dp[n][k] <<"\n";
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