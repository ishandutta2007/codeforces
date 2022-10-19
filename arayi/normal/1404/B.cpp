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
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
char vow[] = { 'a', 'e', 'i', 'o', 'u' };
int dx[] = { 0, -1, 0, 1, -1, -1, 1, 1, 0 };
int dy[] = { -1, 0, 1, 0, -1, 1, -1, 1, 0 };


const int N = 2e6 + 30;
const lli mod = 1e9 + 7;
const ld pi = acos(-1);
const int T = 238;
const ld e = 1e-13;

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
struct pt
{
    lli x, y;
    int ind;
    int bl;
    bool operator==(const pt& a)
    {
        return ind == a.ind;
    }
    bool operator<(const pt& b)
    {
        if (x == b.x) return y < b.y;
        return x < b.x;
    }
};






int t, n, a, b, da, db;
vii g[N];
int dp[N][2], pat;
int dst;
void dfs1(int v, int par, int d)
{
    if (v == b) dst = d;
    dp[v][0] = 1;
    for (auto p : g[v])
    {
        if (p == par) continue;
        dfs1(p, v, d + 1);
        dp[v][0] = max(dp[v][0], dp[p][0] + 1);
    }
}
void dfs(int v, int par)
{
    pat = max(pat, dp[v][0] + dp[v][1]);
    int mx = 0;
    for (auto p : g[v])
    {
        if (p == par) continue;
        dp[p][1] = max(dp[p][1], max(mx + 1, dp[v][1] + 1));
        mx = max(mx, dp[p][0]);
    }
    mx = 0;
    for (int i = g[v].size() - 1; i >= 0; i--)
    {
        auto p = g[v][i];
        if (p == par) continue;
        dp[p][1] = max(dp[p][1], mx + 1);
        mx = max(mx, dp[p][0]);
    }
    for (auto p : g[v])
    {
        if (p == par) continue;
        dfs(p, v);
    }
}
int main()
{
    fastio;
    cin >> t;
    while (t--)
    {
        for (int i = 1; i <= n; i++) g[i].clear(), dp[i][0] = dp[i][1] = 0;
        pat = 0, dst = 0;
        cin >> n >> a >> b >> da >> db;
        for (int i = 0; i < n - 1; i++)
        {
            int a, b;
            cin >> a >> b;
            g[a].ad(b);
            g[b].ad(a);
        }
        if (da * 2 >= db)
        {
            cout << "Alice\n";
            continue;
        }
        dfs1(a, a, 0);
        dfs(a, a);
        //cout << pat << " " << dst << endl;
        if (da * 2 >= pat - 1 || dst <= da)
        {
            cout << "Alice\n";
            continue;
        }
        else cout << "Bob\n";
    }
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