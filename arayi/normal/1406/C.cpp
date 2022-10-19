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


const int N = 1e5 + 30;
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

int t, n;
int sz[N];
vii g[N];
int c1, c2, d1, d2;
void dfs0(int v, int par)
{
    sz[v] = 1;
    for (auto p : g[v])
    {
        if (p == par) continue;
        dfs0(p, v);
        sz[v] += sz[p];
    }
}
void dfs1(int v, int par)
{
    c1 = v;
    for (auto p : g[v])
    {
        if (p == par) continue;
        if (sz[p] > (n + 1) / 2) dfs1(p, v);
    }
    if (c1 == v)
    {
        for (auto p : g[v])
        {
            if (p == par) continue;
            d1 = p;
        }
    }
}
void dfs2(int v, int par)
{
    c2 = v;
    for (auto p : g[v])
    {
        if (p == par) continue;
        if (sz[p] >= (n + 1) / 2) dfs2(p, v);
    }
    if (c2 == v)
    {
        for (auto p : g[v])
        {
            if (p == par) continue;
            d2 = p;
        }
        if (g[v].size() == 1) d2 = par;
    }
}
int main()
{
    fastio;
    cin >> t;
    while (t--)
    {
        cin >> n;
        for (int i = 0; i < n - 1; i++)
        {
            int a, b;
            cin >> a >> b;
            g[a].ad(b);
            g[b].ad(a);
        }
        dfs0(1, 1);
        dfs1(1, 1);
        dfs2(1, 1);
        cout << c2 << " " << d2 << endl;
        cout << c1 << " " << d2 << endl;
        for (int i = 0; i <= n; i++) g[i].clear();
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