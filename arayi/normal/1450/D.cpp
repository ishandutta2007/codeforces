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


const int N = 4e5 + 30;
const lli mod = 998244353;
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



int t1, n;
itn a[N], pr[N];
vii fp[N];
pir t[4 * N];
void upd(int q, int l = 0, int r = n + 1, int nd = 1)
{
    if (q > r || q < l) return;
    if (l == r)
    {
        t[nd] = MP(l, l);
        return;
    }
    int mid = (l + r) / 2;
    upd(q, l, mid, nd * 2);
    upd(q, mid + 1, r, nd * 2 + 1);
    if (t[nd * 2 + 1].sc)t[nd].sc = t[nd * 2 + 1].sc;
    else t[nd].sc = t[nd * 2].sc;
    if (t[nd * 2].fr) t[nd].fr = t[nd * 2].fr;
    else t[nd].fr = t[nd * 2 + 1].fr;
}
int qryr(int l, int r, int nl = 0, int nr = n + 1, int nd = 1)
{
    if (l > nr || r < nl) return 0;
    if (l == nl && r == nr) return t[nd].fr;
    int mid = (nl + nr) / 2;
    if (qryr(l, min(mid, r), nl, mid, nd * 2)) return qryr(l, min(mid, r), nl, mid, nd * 2);
    else return qryr(max(mid + 1, l), r, mid + 1, nr, nd * 2 + 1);
}
int qryl(int l, int r, int nl = 0, int nr = n + 1, int nd = 1)
{
    if (l > nr || r < nl) return 0;
    if (l == nl && r == nr) return t[nd].sc;
    int mid = (nl + nr) / 2;
    if (qryl(max(mid + 1, l), r, mid + 1, nr, nd * 2 + 1)) return qryl(max(mid + 1, l), r, mid + 1, nr, nd * 2 + 1);
    else return qryl(l, min(mid, r), nl, mid, nd * 2);
}
int main()
{
    fastio; 
    cin >> t1;
    while (t1--)
    {
        cin >> n;
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
            fp[a[i]].ad(i);
        }
        upd(0), upd(n + 1);
        for (int i = 1; i <= n; i++)
        {
            itn mx = 0;
            for (auto p : fp[i])
            {
                int r = qryr(p, n + 1);
                int l = qryl(0, p);
                //cout << l << " " << r << endl;
                itn sm = r - l - 1;
                mx = max(mx, sm);
            }
            mx = min(mx, n - i + 1);
            pr[1]++, pr[mx + 1]--;
            for (auto p : fp[i]) upd(p);
        }
        int sm = 0;
        for (int i = 1; i <= n; i++)
        {
            sm += pr[i];
            if (sm == n - i + 1) cout << 1;
            else cout << 0;
        }
        cout << "\n";
        for (int i = 1; i <= n + 1; i++) fp[i].clear(), pr[i] = 0;
        for (int i = 0; i < 8 * n; i++) t[i] = { 0,0 };
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