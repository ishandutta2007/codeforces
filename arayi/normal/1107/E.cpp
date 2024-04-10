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


const int N = 3e6 + 30;
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


str s;
int n;
lli a[N];
lli dp[111][111][111][2];
vii fp;
int main()
{
    fastio;
    cin >> n >> s;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        for (int j = i - 1; j > 0; j--) a[i] = max(a[i], a[j] + a[i - j]);
    }
    for (int i = 0; i < n; i++)
    {
        int sm = 1;
        while (i < n - 1 && s[i] == s[i + 1]) sm++, i++;
        fp.ad(sm);
    }
    n = fp.size();
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            for (int k = 1; k <= 100; k++) dp[i][j][k][0] = dp[i][j][k][1] = -mod;
    //for (int i = 0; i < n; i++) cout << fp[i] << " "; cout << endl;
    for (int len = 1; len <= n; len++)
    {
        for (int l = 0; l < n - len + 1; l++)
        {
            int r = l + len - 1;
            if (l == r)
            {
                dp[l][r][fp[l]][0] = 0;
                dp[l][r][0][0] = dp[l][r][0][1] = a[fp[l]];
                continue;
            }
            for (int k = 100; k >= fp[l]; k--)
            {
                maxi(dp[l][r][k][0], dp[l + 1][r][k - fp[l]][1]);
                maxi(dp[l][r][0][0], dp[l][r][k][0] + a[k]);
                maxi(dp[l][r][0][1], dp[l][r][k][0] + a[k]);
            }
            for (int k = 100; k > 0; k--)
            {
                for (int j = l; j < r; j++)
                {
                    if ((j - l) % 2 == 0)maxi(dp[l][r][k][1], dp[l][j][0][0] + dp[j + 1][r][k][0]);
                    else maxi(dp[l][r][k][1], dp[l][j][0][0] + dp[j + 1][r][k][1]);
                }
                maxi(dp[l][r][0][0], dp[l][r][k][1] + a[k]);
                maxi(dp[l][r][0][1], dp[l][r][k][1] + a[k]);
            }
        }
    }
    cout << max(dp[0][n - 1][0][0], dp[0][n - 1][0][1]) << endl;
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