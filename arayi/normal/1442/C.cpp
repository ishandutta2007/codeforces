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

int n, m;
vii g[N], g1[N];
priority_queue<pair<int, pir > > q;
lli dp[N][23];
pair<lli, lli> d[N][2];
priority_queue<pair<pir, int> > q1;
int main()
{
    fastio;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        g[a].ad(b);
        g1[b].ad(a);
    }
    for (int i = 1; i <= n; i++)
        for (int j = 0; j < 23; j++)
            dp[i][j] = mod, d[i][0] = d[i][1] = MP(mod, mod);
    q.push(MP(0, MP(1, 0)));
    while (!q.empty())
    {
        auto p = q.top();
        q.pop();
        if (dp[p.sc.fr][p.sc.sc] != mod) continue;
        dp[p.sc.fr][p.sc.sc] = -p.fr;
        int i1 = 1;
        if (p.sc.sc % 2 == 0) i1 = 0;
        if (p.sc.sc + i1 < 23)
        {
            for (auto p1 : g[p.sc.fr])
                if (dp[p1][p.sc.sc + i1] == mod)
                    q.push(MP(p.fr - (i1 << p.sc.sc) - 1, MP(p1, p.sc.sc + i1)));
        }
        i1 = 1 - i1;
        if (p.sc.sc + i1 < 23)
        {
            for (auto p1 : g1[p.sc.fr])
                if (dp[p1][p.sc.sc + i1] == mod)
                    q.push(MP(p.fr - (i1 << p.sc.sc) - 1, MP(p1, p.sc.sc + i1)));
        }
    }
    lli mn = mod;
    for (int i = 0; i < 23; i++)
        mn = min(mn, dp[n][i]);
    if (mn != mod) return cout << mn << endl, 0;
    q1.push(MP(MP(0, 0), 1));
    while (!q1.empty())
    {
        auto p = q1.top();
        q1.pop();
        int s = (-p.fr.fr) % 2;
        if (d[p.sc][s].fr != mod) continue;
        d[p.sc][s] = MP(-p.fr.fr, -p.fr.sc);
        int i1 = 1;
        if ((-p.fr.fr) % 2 == 0) i1 = 0;
        for (auto p1 : g[p.sc])
            if (d[p1][(s + i1) % 2].fr == mod)
                q1.push(MP(MP(p.fr.fr - i1, p.fr.sc - 1), p1));
        i1 = 1 - i1;
        for (auto p1 : g1[p.sc])
            if (d[p1][(s + i1) % 2].fr == mod)
                q1.push(MP(MP(p.fr.fr - i1, p.fr.sc - 1), p1));
    }
    d[n][0] = min(d[n][0], d[n][1]);
    lli ans = bp(2, d[n][0].fr) - 1LL + d[n][0].sc;
    ans %= mod;
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