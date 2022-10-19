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


const int N = 5e5 + 30;
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


int n, k, m;
int a[N];
int col[N], b[N], l[N], r[N];
lli pat = 1, dp[N], pr[N];
int main()
{
    fastio;
    cin >> n >> k >> m;
    for (int i = 0; i < m; i++)
        cin >> l[i] >> r[i] >> a[i];
    for (int x = 0; x < k; x++)
    {
        memset(col, 0, sizeof(col));
        memset(dp, 0, sizeof(dp));
        memset(pr, 0, sizeof(pr));
        memset(b, 0, sizeof(b));
        for (int i = 0; i < m; i++)
        {
            if ((1 << x) & a[i]) col[l[i]]++, col[r[i] + 1]--;
            else b[r[i] + 1] = max(b[r[i] + 1], l[i]);
        }
        for (int i = 1; i <= n + 1; i++)
            b[i] = max(b[i], b[i - 1]);
        for (int i = 1; i <= n + 1; i++)
            col[i] += col[i - 1];
        pr[0] = dp[0] = 1;
        for (int i = 1; i <= n + 1; i++)
        {
            if (col[i]) dp[i] = 0;
            else
            {
                dp[i] = pr[i - 1];
                if (b[i]) dp[i] -= pr[b[i] - 1];
                if (dp[i] < 0) dp[i] += mod;
            }
            pr[i] += pr[i - 1] + dp[i];
            pr[i] %= mod;
        }
       // cout << dp[n + 1] << endl;
        pat *= dp[n + 1];
        pat %= mod;
    }
    cout << pat << endl;
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