//Arayi
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <queue>
#include <stack>
#include <algorithm>
#include <math.h>
#include <vector>
#include <cstring>
#include <ctime>
#include <set>
#include <bitset>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <iomanip>
#include <ctime>
#include <climits>
#include <cassert>
#include <chrono>
#include <random>
#include <complex>

#define fr first
#define sc second
#define MP make_pair
#define ad push_back
#define PB push_back
#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define lli long long int
#define y1 arayikhalatyan
#define j1 jigglypuff
#define ld long double
#define itn int
#define pir pair<int, int>
#define all(x) (x).begin(), (x).end()
#define str string
#define enl endl
#define en endl
#define cd complex<long double>
#define vcd vector<cd>
#define vii vector<int>
#define vlli vector<lli>
using namespace std;

lli gcd(lli a, lli b) { return (b == 0LL ? a : gcd(b, a % b)); }
ld dist(ld x, ld y1, ld x2, ld y2)
{
    return sqrt((x - x2) * (x - x2) + (y1 - y2) * (y1 - y2));
}
lli S(lli a)
{
    return (a * (a + 1LL)) / 2;
}
mt19937 rnd(363542);
char vow[] = { 'a', 'e', 'i', 'o', 'u' };
int dx[] = { 0, -1, 0, 1, -1, -1, 1, 1, 0 };
int dy[] = { -1, 0, 1, 0, -1, 1, -1, 1, 0 };


const int N = 5050 + 30;
const lli mod = 1e17;
const ld pi = acos(-1);
const int T = 550;

lli bp(lli a, lli b = mod - 2LL)
{
    lli ret = 1;
    while (b)
    {
        if (b & 1) ret *= a, ret %= mod;
        a *= a;
        a %= mod;
        b >>= 1;
    }
    return ret;
}
ostream& operator<<(ostream& c, pir a)
{
    c << a.fr << " " << a.sc;
    return c;
}
template<class T>
void maxi(T& a, T b)
{
    a = max(a, b);
}
template <class T>
void mini(T& a, T b)
{
    a = min(a, b);
}



int n;
vii g[N];
lli d[N], c[N], b;
int sz[N], tin[N], tout[N], ti;
vector<pair<lli, int> > ap;
lli dp[N][2][N];
void dfs(int v)
{
    tin[v]=++ti;
    sz[v]=1;
    vector<pir> fp;
    for(auto p : g[v])
    {
        dfs(p);
        fp.ad(MP(sz[p], p));
        sz[v]+=sz[p];
    }
    tout[v]=++ti;
    sort(all(fp));
    reverse(all(fp));
    int i1 = 1;
    for(auto p : ap)
        if(tin[v] <= tin[p.sc] && tout[v] >= tout[p.sc]) dp[v][0][i1]=dp[v][0][i1-1]+p.fr, i1++;
    i1 = 1;
    dp[v][1][1]=c[v]-d[v];
    for(auto p : fp)
    {
       for(int i = i1; i > 0; i--)
           for (int j = 0; j <= p.fr; j++)
               mini(dp[v][1][i+j], dp[v][1][i]+dp[p.sc][1][j]);
       i1+=p.fr;
    }
    for (int i = 0; i <= sz[v]; i++) mini(dp[v][1][i], dp[v][0][i]);
}
int main()
{
    fastio;
    cin >> n >> b;
    cin>>c[1]>>d[1];
    ap.ad(MP(c[1],1));
    for (int i = 2; i <= n; i++)
    {
        cin>>c[i]>>d[i];
        ap.ad(MP(c[i], i));
        int x;
        cin>>x;
        g[x].ad(i);
        for (int j = 1; j <= n; j++) dp[i][1][j]=dp[i][0][j]=mod;
        dp[1][1][i]=dp[1][0][i]=mod;
    }
    sort(all(ap));
    dfs(1);
    for (int i = 0; i <= n; i++)
        if(dp[1][1][i] > b) return cout<<i-1<<endl, 0;
    cout<<n<<endl;
    return 0;
}

/*

    __
  *(><)*
    \/ /
    ||/
  --||
    ||
    /\
   /  \
  /    \

*/