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
char vow[] = { 'a', 'e', 'i', 'o', 'u' };
int dx[] = { 1, -1, 0, 0, -1, -1, 1, 1, 0 };
int dy[] = { 0, 0, 1, -1, -1, 1, -1, 1, 0 };


const int N = 1e5 + 30;
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


int n, k;
vector <int> g[N], fp;
pir dp[N];
int pat[N];
queue <pir> q;
void dfs(int v, int par)
{
    for (auto p : g[v])
    {
        if (p == par) continue;
        dfs(p, v);
    }
    fp.ad(v);
}
int stg(int a)
{
    k = a;
    memset(dp, 0, sizeof(dp));
    for (auto v : fp)
    {
        int mx, mx1;
        mx = mx1 = 0;
        for (auto p : g[v])
        {
            dp[v].fr += dp[p].fr;
            mx1 = max(mx1, dp[p].sc);
            if (mx1 > mx) swap(mx, mx1);
        }
        if (mx + mx1 + 1 >= k) dp[v].fr++;
        else dp[v].sc = mx + 1;
    }
    return dp[1].fr;
}
void sm(int l, int r)
{
    if (pat[l] == pat[r] || l > r)
    {
        for (int i = l + 1; i < r; i++)
            pat[i] = pat[l];
    }
    else
    {
        int mid = (l + r) / 2;
        int ss = stg(mid);
        pat[mid] = ss;
        sm(l, mid);
        ss = stg(mid + 1);
        pat[mid + 1] = ss;
        sm(mid + 1, r);
    }
}
int main()
{
    fastio;
    cin >> n;
    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        g[a].ad(b);
        g[b].ad(a);
    }
    dfs(1, 1);
    pat[1] = n;
    pat[n] = stg(n);
    sm(1, n);
    for (int i = 1; i <= n; i++)
    {
        cout << pat[i] << " ";
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