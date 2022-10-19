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



int n, m;
vii a[N];
int p[N], sz[N];
lli f[N], fm[N];
int gp(int x)
{
    if (p[x] == x) return x;
    return p[x] = gp(p[x]);
}
lli c(int n, int k)
{
    lli ret = f[n];
    ret *= fm[k];
    ret %= mod;
    ret *= fm[n - k];
    ret %= mod;
    return ret;
}
lli sm(int a)
{
    if (a < 2) return 1;
    lli sum = 0;
    for (int i = 0; i <= a; i += 2)
    {
        sum += c(a, i);
        sum %= mod;
    }
    return sum;
}
int main()
{
    fastio;
    cin >> n >> m;
    f[0] = 1;
    fm[0] = bp(f[0]);
    for (int i = 1; i <= m + 1; i++)
        f[i] = f[i - 1] * 1LL * (lli)i, f[i] %= mod, fm[i] = bp(f[i]);
    for (int i = 0; i <= m + 5; i++) p[i] = i;
    for (int i = 0; i < n; i++)
    {
        int k;
        cin >> k;
        int x, y;
        cin >> x;
        if (k == 1) y = 0;
        else cin >> y;
        if (gp(x) == gp(y)) continue;
        p[gp(x)] = gp(y);
        a[i].ad(y), a[i].ad(x);
    }
    vii pat;
    for (int i = 0; i < n; i++)
        if (a[i].size()) pat.ad(i + 1);
    for (int i = 1; i <= m; i++)
        sz[gp(i)]++;
    lli ans = bp(2, sz[gp(0)]);
    for (int i = 1; i <= m; i++)
    {
        if (gp(i) != i) continue;
        if (i == gp(0)) continue;
        ans *= sm(sz[i]), ans %= mod;
    }
    cout << ans << " ";
    cout << pat.size() << endl;
    for (auto p : pat) cout << p << " ";
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