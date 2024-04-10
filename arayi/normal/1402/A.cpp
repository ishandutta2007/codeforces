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
#define fastio ios_base::sync_with_stdio(false); cin.tie(0);
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






int n, k, t;
int p[N], xr[N], pr[N][20];
bool col[N], cl[N];
queue <pir> q;
vii g[N];
int gp(int x)
{
    if (p[x] == x) return x;
    return p[x] = gp(p[x]);
}
void dfs(int v, int par, int xx)
{
    //cout << v << " " << xx << endl;
    xr[v] = xx;
    pr[v][0] = par;
    for (auto p : g[v])
    {
        if (p == par) continue;
        dfs(p, v, xx + 1);
    }
}
int walk(int u, int d)
{
    for (int i = 0; i < 20; i++)
        if (d & (1 << i)) u = pr[u][i];
    return u;
}
int lca(int v, int u)
{
    if (xr[v] > xr[u]) swap(u, v);
    u = walk(u, xr[u] - xr[v]);
    if (u == v) return u;
    for (int i = 19; i >= 0; i--)
    {
        if (pr[u][i] == pr[v][i]) continue;
        u = pr[u][i];
        v = pr[v][i];
    }
    return pr[u][0];
}
int main()
{
    fastio;
    cin >> n >> k >> t;
    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        g[a].ad(n + i + 1);
        g[n + i + 1].ad(a);
        g[b].ad(n + i + 1);
        g[n + i + 1].ad(b);
    }
    for (int i = 0; i < t; i++)
    {
        int x;
        cin >> x;
        q.push({ x,0 });
        cl[x] = col[x] = 1;
    }
    dfs(1, 1, 0);
    for (int i = 1; i < 20; i++)
        for (int j = 1; j < 2 * n; j++)
            pr[j][i] = pr[pr[j][i - 1]][i - 1], p[j] = j;
    while (!q.empty())
    {
        int v = q.front().fr;
        int d = q.front().sc;
        q.pop();
        if (d == k) continue;
        for (auto p1 : g[v])
        {
            if (col[p1])
            {
                p[gp(p1)] = gp(v);
            }
            else
            {
                col[p1] = 1;
                q.push(MP(p1, d + 1));
                p[p1] = gp(v);
            }
        }
    }
    cin >> t;
    while (t--)
    {
        int a, b;
        cin >> a >> b;
        int c = lca(a, b);
        //cout << a << " " << b << enl << xr[a] << " " << xr[b] << endl;
        if (xr[a] + xr[b] - xr[c] - xr[c] <= k + k)
        {
            cout << "YES\n";
            continue;
        }
        if (xr[a] < xr[b]) swap(a, b);
        a = walk(a, k);
        if (xr[b] - xr[c] < k)
            b = walk(a, xr[a] - xr[c] - k + xr[b] - xr[c]);
        else
            b = walk(b, k);
        //cout << a << " " << b << endl;
        if (gp(a) == gp(b)) cout << "YES\n";
        else cout << "NO\n";
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