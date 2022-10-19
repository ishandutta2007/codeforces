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
const int mod = 1e9;
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



int t1;
int n, q;
str s, f;
vector<pir> fp;
int t[4 * N], ti;
pir flg[4 * N];
int sz[4 * N];
void push(int nd)
{
    flg[nd * 2] = max(flg[nd], flg[nd * 2]);
    flg[nd * 2 + 1] = max(flg[nd], flg[nd * 2]);
    if (flg[nd].sc == 1) t[nd] = sz[nd];
    else if (flg[nd].sc == -1) t[nd] = 0;
    flg[nd] = MP(0, 0);
}
void bld(int l = 0, int r = n - 1, int nd = 1)
{
    sz[nd] = r - l + 1;
    flg[nd] = MP(0, 0);
    if (l == r)
    {
        t[nd] = f[l] - '0';
        return;
    }
    int mid = (l + r) / 2;
    bld(l, mid, nd * 2);
    bld(mid + 1, r, nd * 2 + 1);
    t[nd] = t[nd * 2] + t[nd * 2 + 1];
}
void upd(int l, int r, int v, int nl = 0, int nr = n - 1, int nd = 1)
{
    push(nd);
    if (l > nr || r < nl)return;
    if (l == nl && r == nr)
    {
        flg[nd] = MP(ti++, v);
        push(nd);
        return;
    }
    int mid = (nl + nr) / 2;
    upd(l, min(mid, r), v, nl, mid, nd * 2);
    upd(max(mid + 1, l), r, v, mid + 1, nr, nd * 2 + 1);
    t[nd] = t[nd * 2] + t[nd * 2 + 1];
}
int qry(int l, int r, int nl = 0, int nr = n - 1, int nd = 1)
{
    push(nd);
    if (l > nr || r < nl) return 0;
    if (l == nl && r == nr) return t[nd];
    int mid = (nl + nr) / 2;
    return qry(l, min(mid, r), nl, mid, nd * 2) + qry(max(mid + 1, l), r, mid + 1, nr, nd * 2 + 1);
}
int main()
{
    fastio;
    cin >> t1;
    while (t1--)
    {
        cin >> n >> q;
        cin >> s >> f;
        fp.clear();
        ti = 1;
        for (int i = 0; i < q; i++)
        {
            int l, r;
            cin >> l >> r;
            fp.ad({ l,r });
        }
        bool bl = 0;
        bld();
        for (int i = fp.size() - 1; i >= 0; i--)
        {
            //for (int i = 0; i < n; i++) f[i] = qry(i, i) + '0';
            //cout << f << endl;
            int l = fp[i].fr, r = fp[i].sc;
            l--, r--;
            int sm = qry(l, r);
            int sm1 = r - l + 1 - sm;
            if (sm < sm1) upd(l, r, -1);
            else if (sm > sm1) upd(l, r, 1);
            else
            {
                bl = 1;
                break;
            }
        }
        for (int i = 0; i < n; i++) f[i] = qry(i, i) + '0';
        if (s != f) bl = 1;
        if (bl) cout << "NO\n";
        else cout << "YES\n";
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