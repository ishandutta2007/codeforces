//Arayi
//#define _CRT_SECURE_NO_WARNINGS
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
int dx[] = { 1, -1, 0, 0, -1, -1, 1, 1, 0 };
int dy[] = { 0, 0, 1, -1, -1, 1, -1, 1, 0 };


const int N = 3e5 + 30;
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
int a[N][2];
pir ind[N];
bool col[N];
vector <int> g[N], fp, pat;
void dfs(int v)
{
    col[v] = true;
    fp.ad(v);
    for (auto p : g[v])
    {
        if (!col[p]) dfs(p);
    }
}
void sm(vii fp)
{
    vii b, b1;
    b1.ad(fp[0]);
    for (int i = 1; i < fp.size(); i++)
    {
        int i1 = fp[i] - 1, i2 = fp[i - 1] - 1;
        if (a[i1][0] == a[i2][0] || a[i1][1] == a[i2][1])
        {
            b.ad(i1 + 1);
            swap(a[i1][0], a[i1][1]);
        }
        else
        {
            b1.ad(i1 + 1);
        }
    }
    if ((int)b.size() < (int)b1.size())
    {
        for (auto p : b) pat.ad(p);
    }
    else
    {
        for (auto p : b1) pat.ad(p);
    }
}
int main()
{
    fastio;
    cin >> t;
    while (t--)
    {
        bool bl = true;
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i][0];
            if (!ind[a[i][0]].fr) ind[a[i][0]].fr = i + 1;
            else if (!ind[a[i][0]].sc) ind[a[i][0]].sc = i + 1;
            else bl = false;
        }
        for (int i = 0; i < n; i++)
        {
            cin >> a[i][1];
            if (!ind[a[i][1]].fr) ind[a[i][1]].fr = i + 1;
            else if (!ind[a[i][1]].sc) ind[a[i][1]].sc = i + 1;
            else bl = false;
        }
        if (!bl)
        {
            cout << -1 << endl;
            for (int i = 0; i <= n; i++)
            {
                ind[i] = MP(0, 0);
                g[i].clear();
                col[i] = false;
            }
            continue;
        }
        for (int i = 1; i <= n; i++)
        {
            if (ind[i].fr == ind[i].sc)
            {
                col[ind[i].fr] = true;
                continue;
            }
            g[ind[i].fr].ad(ind[i].sc);
            g[ind[i].sc].ad(ind[i].fr);
        }
        pat.clear();
        for (int i = 1; i <= n; i++)
        {
            if (col[i]) continue;
            dfs(i);
            sm(fp);
            fp.clear();
        }
        cout << pat.size() << endl;
        for (auto p : pat) cout << p << " ";
        cout << endl;
        for (int i = 0; i <= n; i++)
        {
            ind[i] = MP(0, 0);
            g[i].clear();
            col[i] = false;
        }
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