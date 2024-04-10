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


const int N = 1e5 + 30;
const lli mod = 998244353;
const ld pi = acos(-1);
const int T = 550;

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
void maxi(lli& a, lli b)
{
    a = max(a, b);
}


int n, k, l;
int a[N];
lli d[N][111], dp[N];
lli p[N][111], pr[N];
int main()
{
    fastio;
    cin >> n >> k >> l;
    if (l == 1) return cout << 0 << endl, 0;
    d[0][0] = 1;
    p[0][0] = 1;
    dp[0] = 1;
    pr[0] = 1;
    int nax = 0, nx = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        if (a[i] != -1)
        {
            int j = a[i];
            if (a[i] == a[nax])
            {
                d[i][j] = pr[i - 1] - p[i - 1][j];
                int sm = max(i - l, nx - 1);
                if (sm >= 0) d[i][j] -= pr[sm] - p[sm][j];
            }
            else
            {
                d[i][j] = pr[i - 1] - p[i - 1][j];
                int sm = max(i - l, nax - 1);
                if (sm >= 0) d[i][j] -= pr[sm] - p[sm][j];
            }
            d[i][j] %= mod;
            if (d[i][j] < 0) d[i][j] += mod;
            dp[i] = d[i][j];
            if (a[i] != a[nax]) nx = nax, nax = i;
            else nax = i;   
        }
        else
        {
            for (int j = 1; j <= k; j++)
            {
                if (a[nax] == j)
                {
                    d[i][j] = pr[i - 1] - p[i - 1][j];
                    int sm = max(i - l, nx - 1);
                    if (sm >= 0) d[i][j] -= pr[sm] - p[sm][j];
                }
                else
                {
                    d[i][j] = pr[i - 1] - p[i - 1][j];
                    int sm = max(i - l, nax - 1);
                    if (sm >= 0) d[i][j] -= pr[sm] - p[sm][j];
                }
                d[i][j] %= mod;
                if (d[i][j] < 0) d[i][j] += mod;
                dp[i] += d[i][j];
                dp[i] %= mod;
            }
        }
        for (int j = 1; j <= k; j++)
            p[i][j] = (p[i - 1][j] + d[i][j]) % mod;
        pr[i] = (pr[i - 1] + dp[i]) % mod;
    }
    //for (int i = 1; i <= n; i++) cout << dp[i] << " ";
    cout << dp[n] << endl;
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