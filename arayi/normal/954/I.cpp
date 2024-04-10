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


const int N = 8e5 + 30;
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




int rev[N];
cd roots[N];
void fft(vcd& a, int n)
{
    while (a.size() < n) a.push_back(0);
    for (int i = 0; i < n; ++i)
        if (i < rev[i])
            swap(a[i], a[rev[i]]);
    for (int len = 1, step = n / 2; len < n; len <<= 1, step >>= 1)
        for (int st = 0; st < n; st += len + len)
            for (int i = 0; i < len; ++i)
            {
                cd u = a[st + i], v = roots[i * step] * a[st + len + i];
                a[st + i] = u + v;
                a[st + len + i] = u - v;
            }
}
void inv(vcd& a)
{
    fft(a, a.size());
    reverse(a.begin() + 1, a.end());
    for (cd& x : a)
        x /= a.size();
}
int init(int a, int b)
{
    int n = 1, h = 0;
    while (n < a + b) n *= 2, ++h;
    rev[0] = 0;
    for (int i = 1, high = -1; i < n; ++i)
    {
        high += !(i & (i - 1));
        rev[i] = rev[i ^ (1 << high)] | (1 << (h - high - 1));
    }
    double sector = 2. * pi / n;
    for (int i = 0; i < n; ++i) {
        double alpha = i * sector;
        roots[i] = cd(cos(alpha), sin(alpha));
    }
    return n;
}
vcd conv(vcd a, vcd& b)
{
    for (int i = 0; i < a.size(); ++i)
        a[i] *= b[i];
    inv(a);
    return a;
}
str s, t;
bool a[N][6][6], col[6];
void dfs(int i1, int v)
{
    col[v] = true;
    for (int i = 0; i < 6; i++)
    {
        if (!col[i] && a[i1][v][i]) dfs(i1, i);
    }
}
vcd a1[6], b1[6];
int main()
{
    fastio;
    cin >> s >> t;
    vcd p(s.length()), g(t.length());
    int n = init(s.length(), t.length());
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < s.length(); j++)
        {
            if (s[j] == 'a' + i) a1[i].ad(1);
            else a1[i].ad(0);
        }
        fft(a1[i], n);
        for (int j = t.length() - 1; j >= 0; j--)
        {
            if (t[j] == 'a' + i) b1[i].ad(1);
            else b1[i].ad(0);
        }
        fft(b1[i], n);
    }
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            if (i == j) continue;
            p = conv(a1[i], b1[j]);
            for (int i1 = t.length() - 1; i1 < s.length(); i1++)
            {
                if (p[i1].real() > 0.5)
                {
                    a[i1][i][j] = true;
                    a[i1][j][i] = true;
                    //cout << i1 << " " << char('a' + i) << " " << char('a' + j) << endl;
                }
            }
            //cout << i << " " << j << endl;
        }
    }
    for (int i = t.length() - 1; i < s.length(); i++)
    {
        itn sm = 0;
        memset(col, 0, sizeof(col));
        for (int j = 0; j < 6; j++)
        {
            if (!col[j])
            {
                sm++;
                dfs(i, j);
            }
        }
        cout << 6 - sm << " ";
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