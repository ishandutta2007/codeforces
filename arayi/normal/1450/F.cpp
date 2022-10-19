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
itn a[N], qan;
int col[N];
int main()
{
    fastio; 
    cin >> t1;
    while (t1--)
    {
        cin >> n;
        vector<pir> fp;
        qan = 1;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            if (i)
            {
                if (a[i] != a[i - 1]) fp.ad(MP(a[i], a[i - 1]));
                else qan++, col[a[i - 1]]++, col[a[i]]++;
            }
        }
        col[a[0]]++, col[a[n - 1]]++;
        int mx = 0, sm = 1;
        for (int i = 1; i <= n; i++)
            if (col[i] > mx) mx = col[i], sm = i;
        int i1 = 0;
        while (mx - 1 > qan && i1 < fp.size())
        {
            if (fp[i1].fr != sm && fp[i1].sc != sm) qan++;
            i1++;
        }
        if (mx - 1 > qan) cout << -1 << "\n";
        else cout << qan - 1 << "\n";
        for (int i = 0; i <= n; i++) col[i] = 0;
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