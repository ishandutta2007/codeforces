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
    return (a * (a + 1LL)) / 2LL;
}
mt19937 rnd(363542);
char vow[] = { 'a', 'e', 'i', 'o', 'u' };
int dx[] = { 0, -1, 0, 1, -1, -1, 1, 1, 0 };
int dy[] = { -1, 0, 1, 0, -1, 1, -1, 1, 0 };


const int N = 1e6 + 30;
const lli mod = 998244353;
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


int n, m, k;
vector <int> g[N];
vector <pir> g1[N];
int cl[N], col[N], xr[N], ka[N];
int cl1[N], i1, col1[N], a[N], b[N];
lli ans;
void dfs(int v, int c, int x)
{
    col[v] = 2;
    cl1[v] = i1;
    xr[v] = x;
    for (auto p : g[v])
    {
        if (cl[p] != c || col[p] == 1) continue;
        else if (col[p] == 2)
        {
            if ((xr[v] - xr[p]) % 2 == 0) ka[c] = 1;
        }
        else
            dfs(p, c, x + 1);
    }
    col[v] = 1;
}
int cool[N], xrr[N], bl;
void dfs1(int v, int xr)
{
    cool[v] = 2;
    xrr[v] = xr;
    for (auto p : g1[v])
    {
        if (cool[p.fr] == 1) continue;
        else if (cool[p.fr] == 2)
        {
            if ((xrr[v] - xrr[p.fr] + p.sc) % 2 == 1) bl = 1;
        }
        else dfs1(p.fr, xr + p.sc);
    }
    cool[v] = 1;
}
int main()
{
    fastio;
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++)
    {
        cin >> cl[i];
    }
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        g[a].ad(b);
        g[b].ad(a);
        if (cl[a] > cl[b]) swap(a, b);
        ::a[i] = a;
        ::b[i] = b;
    }
    for (int i = 1; i <= n; i++)
    {
        if (!col[i])
        {
            i1++;
            col1[i1] = cl[i];
            dfs(i, cl[i], 0);
        }
    }
    //for (int i = 1; i <= n; i++) cout << cl1[i] << " " << xr[i] << endl;
    vector < pair<pir, pair<pir, int> > > fp;
    lli k1 = 0;
    for (int i = 1; i <= k; i++) if (ka[i]) k1++;
    ans -= k1 * 1LL * (lli)(k - k1);
    ans -= k1 * (k1 - 1LL) / 2LL;
    //cout << endl;
    for (int i = 0; i < m; i++)
    {
        if (cl1[a[i]] != cl1[b[i]] && !ka[cl[a[i]]] && !ka[cl[b[i]]])
        {
            fp.ad(MP(MP(cl[a[i]], cl[b[i]]), MP(MP(cl1[a[i]], cl1[b[i]]), (xr[a[i]] + xr[b[i]]) % 2)));
        }
    }
    sort(all(fp));
    vii s;
    for (itn i = 0; i < fp.size(); i++)
    {
        auto p = fp[i].sc;
        //cout << p.fr.fr << " " << p.fr.sc << " " << p.sc << enl;
        s.ad(p.fr.fr);
        s.ad(p.fr.sc);
        g1[p.fr.fr].ad(MP(p.fr.sc, p.sc));
        g1[p.fr.sc].ad(MP(p.fr.fr, p.sc));
        if (i == (int)fp.size() - 1 || fp[i].fr != fp[i + 1].fr)
        {
            bl = 0;
            for(auto p : s) if(!cool[p]) dfs1(p, 0);
            for (auto p : s) cool[p] = 0, xrr[p] = 0, g1[p].clear();
            s.clear();
            ans -= bl;
            //if (bl) cout << fp[i].fr << endl;
        }
    }
    k1 = k;
    ans += k1 * (k1 - 1LL) / 2LL;
    cout << ans << endl;
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