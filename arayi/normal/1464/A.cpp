//Arayi
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <queue>
#include <stack>
#include <vector>
#include <ctime>
#include <set>
#include <bitset>
#include <map>
#include <unordered_map>
#include <unordered_set>
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
ld dist(ld x1, ld y1, ld x2, ld y2)
{
    return ((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}
lli S(lli a)
{
    return (a * (a + 1LL)) / 2LL;
}
mt19937 rnd(363542);
char vow[] = { 'a', 'e', 'i', 'o', 'u' };
int dx[] = { 0, -1, 0, 1, -1, -1, 1, 1, 0 };
int dy[] = { -1, 0, 1, 0, -1, 1, -1, 1, 0 };


const int N = 1e6 + 20;
const lli mod = 2e9 + 7;
const ld pi = acos(-1);
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



int t, n, m;
int mp[N], mp1[N];
int x[N], y[N];
vector<int> g[N];
bool col[N];
itn pat;
void dfs(int v)
{
    col[v] = 1, pat++;
    for (auto p : g[v])
    {
        if (col[p]) continue;
        dfs(p);
    }
}
int main()
{
    fastio;
    cin >> t;
    while (t--)
    {
        cin >> n >> m;
        pat = 0;
        for (int i = 0; i < m; i++)
        {
            cin >> x[i] >> y[i];
            if (x[i] == y[i])
            {
                col[i] = 1;
                continue;
            }
            if (mp1[x[i]])
                g[i].ad(mp1[x[i]] - 1), g[mp1[x[i]] - 1].ad(i);
            if (mp[y[i]])
                g[i].ad(mp[y[i]] - 1), g[mp[y[i]] - 1].ad(i);
            mp[x[i]] = i + 1, mp1[y[i]] = i + 1;
        }
        for (int i = 0; i < m; i++)
        {
            if (!col[i] && g[i].size() <= 1)
                dfs(i);
        }
        /*for (int i = 0; i < m; i++)
        {
            cout << i << "-";
            for (auto p : g[i]) cout << p << " ";
            cout << endl;
        }*/
        for (int i = 0; i < m; i++)
            if (!col[i]) pat++, dfs(i);
        cout << pat << endl;
        for (int i = 0; i <= n; i++)
        {
            x[i] = y[i] = mp[i] = mp1[i] = col[i] = 0;
            g[i].clear();
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