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
const lli mod = 998244353;
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
int a[4][N], dp[N][10];
int d(int x, int i1)
{
    int ret = 0;
    for (int i = 0; i < 3; i++)
    {
        if (x & (1 << i)) ret += 1 - a[i][i1];
        else ret += a[i][i1];
    }
    return ret;
}
bool stg(int a, int b)
{
    int c[3], d[3];
    for (int i = 0; i < 3; i++)
    {
        if (a & (1 << i)) c[i] = 1;
        else c[i] = 0;
        if (b & (1 << i)) d[i] = 1;
        else d[i] = 0;
    }
    if ((c[0] + c[1] + d[0] + d[1]) % 2 == 0) return false;
    if ((c[1] + c[2] + d[1] + d[2]) % 2 == 0) return false;
    return true;
}
int main()
{
    fastio;
    cin >> n >> m;
    if (n >= 4 && m >= 4) return cout << -1 << endl, 0;
    if (n <= m)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                char A;
                cin >> A;
                a[i][j] = A - '0';
            }
        }
    }
    else
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                char A;
                cin >> A;
                a[j][i] = A - '0';
            }
        }
        swap(n, m);
    }
    if (n == 1) return cout << 0 << endl, 0;
    if (n == 2)
    {
        dp[0][0] = dp[0][1] = 1;
        dp[0][(a[0][0] + a[1][0]) % 2]--;
        for (int i = 1; i < m; i++)
        {
            int sm = (a[0][i] + a[1][i]) % 2;
            dp[i][sm] = dp[i - 1][1 - sm];
            dp[i][1 - sm] = 1 + dp[i - 1][sm];
        }
        cout << min(dp[m - 1][0], dp[m - 1][1]) << endl;
        return 0;
    }

    else
    {
        for (int i = 0; i < 8; i++)
        {
            dp[0][i] = d(i, 0);
        }
        for (int i = 1; i < m; i++)
        {
            for (int k = 0; k < 8; k++)
            {
                dp[i][k] = mod;
            }
            for (int j = 0; j < 8; j++)
            {
                for (int k = 0; k < 8; k++)
                {
                    if (stg(j, k))
                    {
                        dp[i][k] = min(dp[i][k], dp[i - 1][j] + d(k, i));
                    }
                }
            }
        }
        int pat = mod;
        for (int i = 0; i < 8; i++)
        {
            pat = min(pat, dp[m - 1][i]);
        }
        cout << pat << endl;
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