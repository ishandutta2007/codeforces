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


const int N = 2e6 + 30;
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



int n, k, m, c;
str a, b;
vector <int> dp[N];
int x[N], y[N], f[N], f1[N];
int main()
{
    fastio;
    cin >> n >> m >> k >> a >> b;
    for (int i = 0; i < k; i++) dp[n].ad(i), c += (a[i] == '1') + (b[i] == '1');
    for (int x = 0; x < (1 << k); x++) f[x] = n;
    for (int i = 0; i < n; i++)
    {
        cin >> x[i] >> y[i];
        x[i]--, y[i]--;
    }
    str s = b;
    for (int j = 0; j < dp[n].size(); j++)
        s[j] = b[dp[n][j]];
    //cout << s << endl;
    int ss = 0;
    for (int j = 0; j < s.length(); j++)
        ss += (1 << j) * (s[j] - '0');
    f1[ss] = max(f1[ss], n);
    for (int i = n - 1; i >= 0; i--)
    {
        vector <int> sm = dp[n];
        dp[i] = sm;
        swap(sm[x[i]], sm[y[i]]);
        for (int j = 0; j < dp[i + 1].size(); j++)
            dp[i][j] = sm[dp[i + 1][j]];
        s = a;
        for (int j = 0; j < dp[i].size(); j++)
            s[j] = a[dp[i][j]];
        ss = 0;
        for (int j = 0; j < s.length(); j++)
            ss += (1 << j) * (s[j] - '0');
        f[ss] = min(f[ss], i);
        //cout << s << " ";
        s = b;
        for (int j = 0; j < dp[i].size(); j++)
            s[j] = b[dp[i][j]];
        //cout << s << endl;
        ss = 0;
        for (int j = 0; j < s.length(); j++)
            ss += (1 << j) * (s[j] - '0');
        f1[ss] = max(f1[ss], i);
    }
    int pat = 0, l = 0, r = 0;
    for (int x = (1 << k) - 1; x >= 0; x--)
    {
        int mq = 0;
        for (int j = 0; j < k; j++)
        {
            if ((1 << j) & x)
            {
                mq++;
                f[x - (1 << j)] = min(f[x - (1 << j)], f[x]);
                f1[x - (1 << j)] = max(f1[x - (1 << j)], f1[x]);
            }
        }
        if (f1[x] - f[x] >= m && pat <= k - c + 2 * mq)
        {
            pat = max(pat, k - c + 2 * mq);
            l = f[x] + 1;
            r = f1[x];
        }
    }
    cout << pat << endl << l << " " << r << endl;
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