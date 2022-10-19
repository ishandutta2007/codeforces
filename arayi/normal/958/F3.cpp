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


const int N = 1e6 + 30;
const lli mod = 1009;
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
vcd pat;
int col[N];
int rev[N];
cd roots[N];
void fft(vcd& a)
{
    int n = a.size();
    for (int i = 0; i < n; ++i)
        if (i < rev[i])
            swap(a[i], a[rev[i]]);
    for (int len = 1, step = n / 2; len < n; len <<= 1, step >>= 1)
        for (int st = 0; st < n; st += len + len)
            for (int i = 0, root = 0; i < len; ++i, root += step)
            {
                cd u = a[st + i], v = roots[root] * a[st + len + i];
                a[st + i] = u + v;
                a[st + i + len] = u - v;
            }
}
void inv(vcd& a)
{
    fft(a);
    reverse(a.begin() + 1, a.end());
    for (cd& x : a)
        x /= a.size();
}
void conv(vcd& a, vcd& b)
{
    int n = 1, h = 0;
    while (n < a.size() + b.size())
        n *= 2, ++h;
    while (a.size() < n) a.push_back(0);
    while (b.size() < n) b.push_back(0);
    rev[0] = 0;
    for (int i = 1, high = -1; i < n; ++i) {
        high += !(i & (i - 1));
        rev[i] = rev[i ^ (1 << high)] | (1 << (h - high - 1));
    }
    ld sector = 2. * pi / n;
    for (int i = 0; i < n; ++i) {
        roots[i] = cd(cos(sector * i), sin(sector * i));
    }
    fft(a); fft(b);
    for (int i = 0; i < n; ++i)
        a[i] *= b[i];
    inv(a);
}
vcd rec(int l, int r)
{
    vcd ret;
    if (l == r)
    {
        for (int i = 0; i <= col[l]; i++)
        {
            ret.ad(1);
        }
        return ret;
    }
    int mid = (l + r) / 2;
    ret = rec(l, mid);
    vcd ret1 = rec(mid + 1, r);
    conv(ret, ret1);
    vii a;
    for (auto p : ret)
    {
        a.ad((lli)(p.real() + 0.45) % mod);
    }
    while (!a.back()) a.pop_back();
    vcd ans(a.begin(), a.end());
    return ans;
}
int main()
{
    fastio;
    cin >> n >> m >> k;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        col[x]++;
    }
    pat = rec(1, m);
    cout << pat[k].real() << endl;
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