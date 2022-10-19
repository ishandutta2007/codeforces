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
    return (a * (a - 1LL)) / 2;
}
mt19937 rnd(363542);
char vow[] = { 'a', 'e', 'i', 'o', 'u' };
int dx[] = { 0, -1, 0, 1, -1, -1, 1, 1, 0 };
int dy[] = { -1, 0, 1, 0, -1, 1, -1, 1, 0 };


const int N = 3e5 + 30;
const lli mod = 1e15 + 7;
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
void maxi(lli& a, lli b)
{
    a = max(a, b);
}

int n;
vii g[N];
int a[N][101], b[N][101];
lli pat;
lli dfs(int v, int par)
{
    lli mx = 0, qn = 0;
    for (auto p : g[v])
    {
        if (p == par) continue;
        qn++;
        mx = max(mx, dfs(p, v));
        for (int i = 1; i <= min(n,70); i++) b[v][i] = max(b[v][i], b[p][i]);
    }
    mx = max(mx, qn);
    if (n >= 71)
    {
        if (mx >= 71) pat += 2LL * (mx - 70) + n - mx;
        else pat += (lli)(n - 70);
    }
    for (int i = 1; i <= min(n, 70); i++)
    {
        if (qn < i)
        {
            a[v][i] = 1;
            b[v][i] = max(b[v][i], a[v][i]);
            pat += b[v][i];
            continue;
        }
        vii fp;
        for (auto p : g[v])
        {
            if (p == par) continue;
            fp.ad(-a[p][i]);
        }
        nth_element(fp.begin(), fp.begin() + i - 1, fp.end());
        a[v][i] = -fp[i - 1] + 1;
        b[v][i] = max(b[v][i], a[v][i]);
        pat += b[v][i];
    }
    return mx;
}
lli dfs1(int v, int par)
{
    lli mx = 0;
    vii fp;
    for (auto p : g[v])
    {
        if (p == par) continue;
        mx = max(mx, dfs1(p, v));
        fp.ad(g[p].size() - 1);
    }
    sort(all(fp));
    reverse(all(fp));
    bool bl = 0;
    for (int i = 0; i < fp.size(); i++)
    {
        if (fp[i] < i + 1)
        {
            bl = 1;
            mx = max(mx, (lli)i);
            break;
        }
    }
    if (!bl) mx = max(mx, (lli)fp.size());
    pat += max(0LL, mx - 70);
    return mx;
}
int main()
{
    fastio;
    cin >> n;
    for (int i = 0; i < n - 1; i++)
    {
        itn a, b;
        cin >> a >> b;
        g[a].ad(b);
        g[b].ad(a);
    }
    dfs(1, 1);
    dfs1(1, 1);
    cout << pat << endl;
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