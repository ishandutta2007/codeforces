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
    return (a * (a - 1LL)) / 2;
}
mt19937 rnd(363542);
char vow[] = { 'a', 'e', 'i', 'o', 'u' };
int dx[] = { 0, -1, 0, 1, -1, -1, 1, 1, 0 };
int dy[] = { -1, 0, 1, 0, -1, 1, -1, 1, 0 };


const int N = 2020 + 30;
const lli mod = 1e15 + 7;
const ld pi = acos(-1);
const int T = 1000;

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

int n;
lli k, sum;
lli dp[N][2];
lli l[N], r[N], a[N];
pair<lli, lli> d[N][N][2];
pair<lli, lli> sm(lli l1, lli k1, int i)
{
    if (l1 > r[i]) return MP(mod, mod);
    if (a[i] < k1) return MP(l1, k1 - a[i]);
    if (a[i] == k1) return MP(l1 + 1, k);
    lli mn = a[i] - k1;
    l1 += (mn - 1LL) / k + 1LL;
    if (l1 > r[i]) return MP(mod, mod);
    if (mn % k == 0) l1++;
    return MP(l1, k - mn % k);
}
int main()
{
    fastio;
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        cin >> l[i] >> r[i] >> a[i];
        sum += a[i];
    }
    for (int l = 1; l <= n; l++)
    {
        d[l][l][0] = sm(::l[l], k, l);
        d[l][l][1] = sm(::l[l] + 1, k, l);
        for (int r = l + 1; r <= n; r++)
        {
            auto p = d[l][r - 1][0];
            d[l][r][0] = sm(max(p.fr, ::l[r]), p.sc, r);
            p = d[l][r - 1][1];
            d[l][r][1] = sm(max(p.fr, ::l[r]), p.sc, r);
        }
    }
    //cout << d[1][1][1].fr << " " << d[1][1][1].sc << endl;
    for (int i = 1; i <= n; i++)
    {
        dp[i][0] = dp[i][1] = mod;
        for (int j = 0; j < i; j++)
        {
            auto p = d[j + 1][i][0];
            if (r[j] == l[j + 1]) p.sc += dp[j][0];
            else p.sc += min(dp[j][0], dp[j][1]);
            if (p.fr < r[i]) dp[i][0] = min(dp[i][0], p.sc);
            else dp[i][1] = min(dp[i][1], p.sc);
            p = d[j + 1][i][1];
            p.sc += dp[j][1];
            if (p.fr < r[i]) dp[i][0] = min(dp[i][0], p.sc);
            else dp[i][1] = min(dp[i][1], p.sc);
        }
        dp[i][1] = min(dp[i][0], dp[i][1]);
    }
    lli mn = mod;
    for (int i = 0; i < n; i++)
    {
        if (d[i + 1][n][0].fr < mod)
        {
            if (r[i] < l[i + 1]) mn = min(mn, min(dp[i][0], dp[i][1]));
            else mn = min(mn, dp[i][0]);
        }
        if (d[i + 1][n][1].fr < mod)
            mn = min(mn, min(dp[i][0], dp[i][1]));
    }
    sum += mn;
    if (sum >= mod) cout << -1 << endl;
    else cout << sum << endl;
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