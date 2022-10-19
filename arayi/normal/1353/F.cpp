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
#define fr first
#define sc second
#define MP make_pair
#define ad push_back
#define PB push_back
#define fastio ios_base::sync_with_stdio(false); cin.tie(0);
#define lli long long int
#define y1 arayikhalatyan
#define j1 jiglypuff
#define ld long double
#define itn int
#define pir pair<int, int> 
#define all(x) (x).begin(), (x).end()
#define str string
using namespace std;

lli gcd(lli a, lli b) { return (b == 0LL ? a : gcd(b, a % b)); }
ld dist(ld x1, ld y1, ld x2, ld y2)
{
    return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}
lli S(lli a)
{
    return (a * (a + 1LL)) / 2;
}
char vow[] = { 'a', 'e', 'i', 'o', 'u' };
int dx[] = { 1, -1, 0, 0, -1, -1, 1, 1 };
int dy[] = { 0, 0, 1, -1, -1, 1, -1, 1 };


const int N = 110;
const lli mod = 998244353;
const ld pi = acos(-1);
const int T = 238;
const ld e = 1e-6;

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


int t;
int n, m;
lli dp[N][N], a[N][N], sm;
void clc()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (i == 0 && j == 0) continue;
            lli d = a[i][j] - sm;
            if (d < (lli)(i + j))
            {
                dp[i][j] = -1;
                continue;
            }
            d -= (lli)(i + j);
            if (i == 0 && dp[i][j - 1] == -1) dp[i][j] = -1;
            else if (i == 0)dp[i][j] = d + dp[i][j - 1];
            else if (j == 0 && dp[i - 1][j] == -1) dp[i][j] = -1;
            else if (j == 0) dp[i][j] = d + dp[i - 1][j];
            else
            {
                if (max(dp[i - 1][j], dp[i][j - 1]) == -1) dp[i][j] = -1;
                else if (min(dp[i - 1][j], dp[i][j - 1]) == -1) dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]) + d;
                else dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + d;
            }
        }
    }
}
int main()
{
    fastio;
    cin >> t;
    while (t--)
    {
        cin >> n >> m;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> a[i][j];
            }
        }
        lli pat = LLONG_MAX;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                sm = a[i][j] - (lli)(i + j);
                if (sm > a[0][0]) continue;
                dp[0][0] = a[0][0] - sm;
                clc();
                if (dp[n - 1][m - 1] != -1)
                    pat = min(pat, dp[n - 1][m - 1]);
            }
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