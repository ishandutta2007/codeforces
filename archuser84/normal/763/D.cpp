///
///    "Excuse me... What did you say about my hair?!"
///
///                                    -Josuke Higashikata

#define _USE_MATH_DEFINES
#define FAST ios::sync_with_stdio(false),cin.tie(0);
#include <bits/stdc++.h>
#define Loop(x, l, r) for(int x = (l); x < (r); ++x)
#define LoopR(x, l, r) for(int x = (r)-1; x >= (l); --x)
#define all(x) x.begin(), x.end()
#define Kill(x) exit((cout << (x) << '\n', 0))
#define YN(flag) ((flag)? "YES": "NO")
#define F first
#define S second
typedef          long long   ll;
typedef unsigned long long  ull;
typedef std::pair<int,int>  pii;
typedef std::pair<ll ,ll >  pll;
using namespace std;

const ll bs1 = (1<<13)-1;
const ll bs2 = (1<<17)-1;
const int m1 = 1e9 + 7;
const int m2 = 7*17*(1<<23) + 1;
template<int m = m1> ll inv(ll x){return x==1? 1: m - inv<m>(m%x)*(m/x)%m;}

template<int m> ll mypow(ll x, ll y)
{
    ll ans = 1;
    while(y)
    {
        if(y&1) ans = ans*x % m;
        x = x*x % m;
        y >>= 1;
    }
    return ans;
}

const int N = 100010;
map<ll, int> cnt;
ll h1[N], h2[N];
vector<int> A[N];
int n;

void dfs1(int v, int p)
{
    h1[v] = h2[v] = 173487287;
    for(int u : A[v])
    {
        if(u == p) continue;
        dfs1(u, v);
        h1[v] += mypow<m1>(bs1, h1[u]);
        h2[v] += mypow<m2>(bs2, h2[u]);
    }
    h1[v] %= m1; h2[v] %= m2;
    cnt[h1[v]^(h2[v]<<32)]++;
}

int ans, mx;

void dfs2(int v, int p)
{
    for(int u : A[v])
    {
        if(u == p) continue;

        if(!--cnt[h1[v]^(h2[v]<<32)]) cnt.erase(h1[v]^(h2[v]<<32));
        if(!--cnt[h1[u]^(h2[u]<<32)]) cnt.erase(h1[u]^(h2[u]<<32));
        h1[v] = (h1[v]+m1-mypow<m1>(bs1, h1[u])) % m1;
        h2[v] = (h2[v]+m2-mypow<m2>(bs2, h2[u])) % m2;
        h1[u] = (h1[u]+mypow<m1>(bs1, h1[v])) % m1;
        h2[u] = (h2[u]+mypow<m2>(bs2, h2[v])) % m2;
        cnt[h1[v]^(h2[v]<<32)]++;
        cnt[h1[u]^(h2[u]<<32)]++;
        if(cnt.size() > mx) ans = u, mx = cnt.size();

        dfs2(u, v);

        if(!--cnt[h1[v]^(h2[v]<<32)]) cnt.erase(h1[v]^(h2[v]<<32));
        if(!--cnt[h1[u]^(h2[u]<<32)]) cnt.erase(h1[u]^(h2[u]<<32));
        h1[u] = (h1[u]+m1-mypow<m1>(bs1, h1[v])) % m1;
        h2[u] = (h2[u]+m2-mypow<m2>(bs2, h2[v])) % m2;
        h1[v] = (h1[v]+mypow<m1>(bs1, h1[u])) % m1;
        h2[v] = (h2[v]+mypow<m2>(bs2, h2[u])) % m2;
        cnt[h1[v]^(h2[v]<<32)]++;
        cnt[h1[u]^(h2[u]<<32)]++;
    }
}

int main()
{
    FAST;
    cin >> n;
    Loop(i,1,n)
    {
        int v, u;
        cin >> v >> u;
        --v; --u;
        A[v].push_back(u);
        A[u].push_back(v);
    }
    dfs1(0, -1);
    ans = 0, mx = cnt.size();
    dfs2(0, -1);
    cerr << cnt.size() << '\n';
    cout << ans+1 << '\n';
}