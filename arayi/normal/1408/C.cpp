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


const int N = 1e5 + 20;
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



int t, n, k;
ld a[N], dp[N], dp1[N];
int main()
{
    fastio;
    setprecision(9);
    cout.setf(ios::showpoint);
    cout.setf(ios::fixed);
    cin >> t;
    while (t--)
    {
        cin >> n >> k;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            if (i == 0) dp[i] = a[i];
            else dp[i] = dp[i - 1] + (a[i] - a[i - 1]) / (1.0 + (ld)(i));
        }
        dp[n] = dp[n - 1] + (k - a[n - 1]) / (1.0 + (ld)(n));
        dp1[n] = 0;
        a[n] = k;
        dp1[n - 1] = k - a[n - 1];
        for (int i = n - 2; i >= 0; i--)
        {
            dp1[i] = dp1[i + 1] + (a[i + 1] - a[i]) / (ld)(n - i);
        }
        for (int i = 0; i <= n; i++)
        {
            if (dp[i] == dp1[i])
            {
                cout << dp[i];
                break;
            }
            if (dp[i] > dp1[i])
            {
                ld l = 0;
                if (i) l = a[i - 1];
                ld r = a[i];
                ld t1 = 0;
                if (i)t1 = dp[i - 1];
                ld t2 = dp1[i];
                l += max((ld)0, t2 - t1) * (ld)(1.0 + i);
                r -= max((ld)0, t1 - t2) * (ld)(n - i + 1.0);
                cout << max(t1, t2) + (r - l) / (ld)(n + 2.0);
                break;
            }
        }
        cout << endl;
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