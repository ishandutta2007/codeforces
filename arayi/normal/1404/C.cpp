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






int n, q;
int a[N];
int ind[N], pat[N];
int t[4 * N];
vii fp[N];
vector <pir > sm[N];
void upd(int q, int nl = 1, int nr = n, int nd = 1)
{
    if (q > nr || q < nl) return;
    if (nl == nr)
    {
        t[nd]++;
        return;
    }
    int mid = (nl + nr) / 2;
    upd(q, nl, mid, nd * 2);
    upd(q, mid + 1, nr, nd * 2 + 1);
    t[nd] = t[nd * 2] + t[nd * 2 + 1];
}
int qry(int l, int r, int nl = 1, int nr = n, int nd = 1)
{
    if (l > nr || r < nl) return 0;
    if (l == nl && r == nr) return t[nd];
    int mid = (nl + nr) / 2;
    return qry(l, min(mid, r), nl, mid, nd * 2) + qry(max(l, mid + 1), r, mid + 1, nr, nd * 2 + 1);
}
int main()
{
    fastio;
    cin >> n >> q;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        if (i < a[i])
        {
            ind[i] = n + 1;
            continue;
        }
        int l = 1, r = i, ans = n + 1;
        while (l <= r)
        {
            int mid = (l + r) / 2;
            if (qry(mid, i) >= i - a[i]) ans = mid, l = mid + 1;
            else r = mid - 1;
        }
        ind[i] = ans;
        if (ans != n + 1) upd(ans);
        fp[ind[i]].ad(i);
    }
    memset(t, 0, sizeof(t));
    for (int i = 0; i < q; i++)
    {
        int x, y;
        cin >> x >> y;
        sm[x].ad(MP(y, i));
    }
    for (int i = n - 1; i >= 0; i--)
    {
        for (auto p : fp[i + 1]) upd(p);
        for (auto p : sm[i])
        {
            int ss = qry(i + 1, n);
            if (p.fr) ss -= qry(n - p.fr + 1, n);
            pat[p.sc] = ss;
        }
    }
    for (int i = 0; i < q; i++)
    {
        cout << pat[i] << " ";
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