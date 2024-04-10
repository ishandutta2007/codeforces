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



str s;
lli x, y;
lli pr[N], sf[N], mk[N], zr[N];
int main()
{
    fastio;
    cin >> s;
    cin >> x >> y;
    lli zr = 0, mk = 0;;
    for (int i = 1; i <= s.length(); i++)
    {
        pr[i] = pr[i - 1];
        if (s[i - 1] == '1') pr[i] += zr * x, mk++;
        else pr[i] += mk * y, zr++;
        ::mk[i] = mk, ::zr[i] = zr;
    }
    zr = mk = 0;
    lli mn = pr[s.length()];
    for (int i = s.length(); i > 0; i--)
    {
        sf[i] = sf[i + 1];
        if (s[i - 1] == '0') sf[i] += mk * x, zr++;
        else sf[i] += zr * y, mk++;
        mn = min(mn, pr[i - 1] + sf[i] + mk * ::zr[i - 1] * x + zr * ::mk[i - 1] * y);
    }
    zr = 0, mk = 0;
    for (int i = 1; i <= s.length(); i++)
    {
        pr[i] = pr[i - 1];
        if (s[i - 1] == '0') pr[i] += mk * y, zr++;
        else pr[i] += zr * x, mk++;
        ::mk[i] = mk, ::zr[i] = zr;
    }
    zr = mk = 0;
    mn = min(mn, pr[s.length()]);
    for (int i = s.length(); i > 0; i--)
    {
        sf[i] = sf[i + 1];
        if (s[i - 1] == '1') sf[i] += zr * y, mk++;
        else sf[i] += mk * x, zr++;
        mn = min(mn, pr[i - 1] + sf[i] + mk * ::zr[i - 1] * x + zr * ::mk[i - 1] * y);
    }
    cout << mn << endl;
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