///      That's a Cigarette Day, my Sun

#include <bits/stdc++.h>

#pragma GCC optimize("O3")

#define pb push_back
#define mp make_pair
#define fi first
#define prev asfansjfansjabfasjlbfa
#define se second
#define I "%d"
#define II "%d%d"
#define III "%d%d%d"
#define elif else if
#define out_files freopen("input.txt", "r", stdin);freopen("output.txt", "w", stdout)
#define all(x) (x).begin(), (x).end()
#define fast ios_base::sync_with_stdio(0)
#define y1 asnflainflawnfaw
#define y0 snalfklawnfasdaspqw
#define BLEAT cout << "bleat!!!\n"
#define files(x) ((x != "") ? freopen(x".in", "r", stdin), freopen(x".out", "w", stdout) : 0)
#define files_dat_sol(x)  ((x != "") ? freopen(x".dat", "r", stdin), freopen(x".sol", "w", stdout) : 0)
#define next askfnlabfae

using namespace std;

typedef std::vector <int> vi;
typedef long long ll;
typedef unsigned long long ull;
typedef std::pair <int, int> pii;
typedef std::vector <pii> vii;
typedef long double ld;

#ifdef WIN32
    #define I64 "%I64d"
#else
    #define I64 "%lld"
#endif // WIN32

const int inf = 1000000000;
const ll INF = 1LL*inf*inf;
const long double eps = 1e-9;
const ll md = 1e9 + 7;
const long double EPS = 1e-5;
const ll maxll = std::numeric_limits<ll>::max();
const long double PI = acos(-1.0);

template <typename name> inline name sqr(name x)
{
    return x*x;
}

ld log(ld base, ld n)
{
    return log(n) / log(base);
}

inline ll multmod(ll a, ll b, ll md)
{
    if (!a) return 0;
    if (a % 2 == 1)
        return (multmod(a-1, b, md) + b) % md;
    else
        return sqr(multmod(a/2, b, md)) % md;
}

template <typename name> inline name bpow(const name& base, ll exp, const ll& md = maxll)
{
    if (exp == 1) return base;
    if (exp % 2 == 1)
        return (bpow<name>(base, exp-1, md) * base) % md;
    else
    {
        name k = bpow<name>(base, exp/2, md);
        return (k*k)%md;
    }
}

unsigned char ccc;

inline void read(int &n)
{
    n = 0;
    bool _minus = false;
    while (true) {
        ccc = getchar();
        if (ccc == ' ' || ccc == '\n')
            break;
        if (ccc == '-') {
            _minus = true;
            continue;
        }
        n = n * 10 + ccc - '0';
    }
    if (_minus)
        n *= -1;
}

inline void read(int &n, int& m)
{
    read(n);
    read(m);
}

inline void read(int &n, int &m, int &k)
{
    read(n);
    read(m);
    read(k);
}

inline void read(std::string &s)
{
    s = "";
    while (true)
    {
        ccc = getchar();
        if (ccc == ' ' || ccc == '\n')
            break;
        s += ccc;
    }
}

///-------------------------End of Template-------------------------///

const int MAXN = 3e5;

int cnt[10][MAXN], cur_cnt[10], full_cnt[10][MAXN];
ll dp_down[10][MAXN], cur[10], dp[10][MAXN];
int n, k;
vi way[MAXN];

void dfs1(int v, int pred)
{
    cnt[0][v] = 1;
    for (auto to : way[v])
    {

        if (to == pred) continue;
        dfs1(to, v);
        for (int i=1; i<k; i++)
        {
            dp_down[(i + 1) % k][v] += dp_down[i][to];
            cnt[(i + 1) % k][v] += cnt[i][to];
        }
        dp_down[1 % k][v] += dp_down[0][to] + cnt[0][to];
        cnt[1 % k][v] += cnt[0][to];
    }
}

void dfs2(int v, int pred)
{
    if (pred == -1)
    {
        for (int i=0; i<k; i++)
            dp[i][v] = dp_down[i][v],
            full_cnt[i][v] = cnt[i][v];
    } else
    {
        for (int i=0; i<k; i++)
            cur[i] = 0, cur_cnt[i] = 0;
        for (int i=1; i<k; i++)
            cur[(i+1)%k] += dp[(i+1)%k][pred] - dp_down[i][v],
            cur_cnt[(i+1)%k] += full_cnt[(i+1)%k][pred] - cnt[i][v];
        cur[1 % k] += dp[1 % k][pred] - dp_down[0][v] - cnt[0][v];
        cur_cnt[1 % k] += full_cnt[1 % k][pred] - cnt[0][v];

        for (int i=1; i<k; i++)
            dp[(i + 1) % k][v] += dp_down[(i + 1) % k][v] + cur[i],
            full_cnt[(i + 1) % k][v] += cur_cnt[i] + cnt[(i + 1) % k][v];
        dp[1 % k][v] += cur[0] + cur_cnt[0] + dp_down[1 % k][v];
        full_cnt[1 % k][v] += cur_cnt[0] + cnt[1 % k][v];
    }
    for (auto to : way[v])
        if (to != pred) dfs2(to, v);
}

main()
{
    #ifdef STASTOMASH
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
        freopen("debug.txt", "w", stderr);
    #else
        files("");
    #endif // STASTOMASH

    scanf(II, &n, &k);
    for (int i=1; i<n; i++)
    {
        int x, y;
        scanf(II, &x, &y);
        way[x].pb(y);
        way[y].pb(x);
    }
    dfs1(1, -1);
    dfs2(1, -1);
    ll ans = 0;
    for (int i=1; i<=n; i++)
        for (int j=0; j<k; j++)
            ans += dp[j][i];
    cout << ans / 2;
}