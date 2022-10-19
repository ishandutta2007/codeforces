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


const int N = 1e6 + 30;
const lli mod = 998244353;
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



int n, q;
lli pat[N];
vector<pair<int, lli>> fp[N];
vii g[N];
lli t[4 * N];
void upd(int q, lli v, int l = 0, int r = n, int nd = 1)
{
    if (q > r || q < l) return;
    if (l == r)
    {
        t[nd] += v;
        return;
    }
    int mid = (l + r) / 2;
    upd(q, v, l, mid, nd * 2);
    upd(q, v, mid + 1, r, nd * 2 + 1);
    t[nd] = t[nd * 2] + t[nd * 2 + 1];
}
lli qry(int l, int r, int nl = 0, int nr = n, int nd = 1)
{
    if (l > nr || r < nl) return 0;
    if (l == nl && r == nr) return t[nd];
    int mid = (nl + nr) / 2;
    return qry(l, min(mid, r), nl, mid, nd * 2) + qry(max(l, mid + 1), r, mid + 1, nr, nd * 2 + 1);
}
void dfs(int v, int par, int xr)
{
    for (auto p : fp[v])
        upd(min(n, xr + p.fr), p.sc);
    pat[v] = qry(xr, n);
    for (auto p : g[v])
    {
        if (p == par) continue;
        dfs(p, v, xr + 1);
    }
    for (auto p : fp[v])
        upd(min(n, xr + p.fr), -p.sc);
}
int main()
{
    fastio;
    cin >> n;
    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        g[a].ad(b);
        g[b].ad(a);
    }
    cin >> q;
    while (q--)
    {
        int a, d, x;
        cin >> a >> d >> x;
        fp[a].ad(MP(d, x));
    }
    dfs(1, 1, 0);
    for (int i = 1; i <= n; i++) cout << pat[i] << " ";
    cout << endl;
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