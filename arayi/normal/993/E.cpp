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




int n, x;
int pr[N];
lli ans, sm;
vcd a, b;
vlli a1, b1;
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
    double sector = 2. * pi / n, alpha = 0;
    for (int i = 0; i < n; ++i) {
        roots[i] = cd(cos(alpha), sin(alpha));
        alpha += sector;
    }
    fft(a); fft(b);
    for (int i = 0; i < n; ++i)
        a[i] *= b[i];
    inv(a);
}
int main()
{
    fastio;
    cin >> n >> x;
    for (int i = 0; i < n; i++)
    {
        a1.ad(0);
        b1.ad(0);
        ans += sm;
        int a;
        cin >> a;
        if (i) pr[i] = pr[i - 1];
        if (a < x) pr[i]++, sm = 0;
        else sm++;
    }
    a1.ad(0);
    b1.ad(0);
    ans += sm;
    cout << ans << " ";
    a1[0]++;
    b1[n]++;
    for (int i = 0; i < n; i++)
    {
        //cout << pr[i] << " ";
        //cout << endl;
        a1[pr[i]]++;
        b1[n - pr[i]]++;
    }
    //cout << 3 << endl;
    vcd a(a1.begin(), a1.end());
    vcd b(b1.begin(), b1.end());
    //cout << 12 << endl;
    n++;
    conv(a, b);
    n--;
    for (int i = 1; i <= n; i++)
    {
        cout << (lli)(a[n - i].real() + 0.5) << " ";
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