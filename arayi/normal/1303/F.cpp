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





int n, m, q;
pir p[333][333];
int pat[N];
vector<pir> fp[N];
int col[333][333];
bool cl[333][333];
pir gp(int x, int y)
{
    if (x == p[x][y].fr && y == p[x][y].sc) return MP(x, y);
    return p[x][y] = gp(p[x][y].fr, p[x][y].sc);
}
int main()
{
    fastio;
    cin >> n >> m >> q;
    while (q--)
    {
        int x, y, c;
        cin >> x >> y >> c;
        fp[c].ad(MP(x, y));
    }

    set<pir> st;
    int i1 = 1, sm = 0, ss = 0;
    for (int x = 1; x < N; x++)
    {
        if (fp[x].empty()) continue;
        ss = 0;
        for (int i = 0; i < fp[x].size(); i++)
        {
            auto v = fp[x][i];
            if (cl[v.fr][v.sc]) continue;
            p[v.fr][v.sc] = v;
            cl[v.fr][v.sc] = true;
            st.clear();
            for (int j = 0; j < 4; j++)
            {
                if (v.fr + dx[j] < 1 || v.fr + dx[j] > n || v.sc + dy[j] < 1 || v.sc + dy[j] > m) continue;
                if (!cl[v.fr + dx[j]][v.sc + dy[j]]) continue;
                auto u = gp(v.fr + dx[j], v.sc + dy[j]);
                if (u == v) continue;
                st.insert(u);
                p[u.fr][u.sc] = v;
            }
            ss -= (int)st.size() - 1;
            pat[i1 + i] = ss;
        }
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                p[i][j] = MP(i, j);
                if (cl[i][j]) continue;
                for (int k = 0; k < 2; k++)
                {
                    if (i + dx[k] > n || i + dx[k] < 1 || j + dy[k] > m || j + dy[k] < 1) continue;
                    if (cl[i + dx[k]][j + dy[k]] || col[i][j] != col[i + dx[k]][j + dy[k]]) continue;
                    auto u = gp(i + dx[k], j + dy[k]);
                    p[u.fr][u.sc] = gp(i, j);
                }
            }
        }
        sm = 0;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
                if (!cl[i][j] && p[i][j] == MP(i, j)) sm++;
        for (int i = fp[x].size() - 1; i >= 0; i--)
        {
            auto v = fp[x][i];
            if (pat[i1 + i] == 0) continue;
            pat[i1 + i] += sm;
            cl[v.fr][v.sc] = 0;
            p[v.fr][v.sc] = v;
            st.clear();
            for (int j = 0; j < 4; j++)
            {
                if (v.fr + dx[j] < 1 || v.fr + dx[j] > n || v.sc + dy[j] < 1 || v.sc + dy[j] > m) continue;
                if (cl[v.fr + dx[j]][v.sc + dy[j]] || col[v.fr + dx[j]][v.sc + dy[j]] != col[v.fr][v.sc]) continue;
                auto u = gp(v.fr + dx[j], v.sc + dy[j]);
                if (u == v) continue;
                st.insert(u);
                p[u.fr][u.sc] = v;
            }
            sm -= (int)st.size() - 1;
        }
        for (auto p : fp[x])
        {
            if (pat[i1] == 0) pat[i1] = pat[i1 - 1];
            cout << pat[i1] << "\n";
            i1++;
            col[p.fr][p.sc] = x;
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