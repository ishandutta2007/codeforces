// Arayi
#include <bits/stdc++.h>
#define fr first
#define sc second
#define MP make_pair
#define ad push_back
#define PB push_back
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);                       \
    cout.tie(0);
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
char vow[] = {'a', 'e', 'i', 'o', 'u'};
int dx[] = {0, -1, 0, 1, -1, -1, 1, 1, 0};
int dy[] = {-1, 0, 1, 0, -1, 1, -1, 1, 0};
char dc[] = {'R', 'D', 'L', 'U'};

const int N = 1e6 + 20;
const lli mod = 998244353;
const ld pi = acos(-1);
const ld e = 1e-13;
const int T = 128;

lli bp(lli a, lli b = mod - 2LL)
{
    lli ret = 1;
    while (b)
    {
        if (b & 1)
            ret *= a, ret %= mod;
        a *= a;
        a %= mod;
        b >>= 1;
    }
    return ret;
}
ostream &operator<<(ostream &c, pir a)
{
    c << a.fr << " " << a.sc;
    return c;
}
template <class T>
void maxi(T &a, T b)
{
    a = max(a, b);
}
template <class T>
void mini(T &a, T b)
{
    a = min(a, b);
}

int t, n, m;
lli a[N], dp[N];
vii g[N], g1[N];
bool col[N];
void dfs(int v)
{
    dp[v] = a[v];
    col[v] = 1;
    for (auto p : g1[v])
    {
        if (!col[p])
            dfs(p);
        dp[v] += dp[p];
        dp[v] %= mod;
    }
}
int main()
{
    fastio;
    cin >> t;
    while (t--)
    {
        cin >> n >> m;
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        for (int i = 0; i < m; i++)
        {
            int x, y;
            cin >> x >> y;
            g[x].ad(y);
            g1[y].ad(x);
        }
        lli ans = 0;
        for (int i = 0; i < 2 * n; i++)
        {
            vii fp;
            for (int j = 1; j <= n; j++)
            {
                if (a[j])
                    fp.ad(j);
            }
            if (fp.empty())
                break;
            ans++;
            for (auto p1 : fp)
            {
                a[p1]--;
                for (auto p : g[p1])
                    a[p]++;
            }
        }
        for (int i = 1; i <= n; i++)
        {
            if (g[i].empty())
            {
                dfs(i);
                ans += dp[i];
                break;
            }
        }
        cout << (ans % mod) << "\n";
        for (int i = 0; i <= n; i++)
        {
            col[i] = 0;
            a[i] = dp[i] = 0;
            g[i].clear();
            g1[i].clear();
        }
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