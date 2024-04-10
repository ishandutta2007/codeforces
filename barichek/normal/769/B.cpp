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
#define files(x) freopen(x".in", "r", stdin); freopen(x".out", "w", stdout);
#define files_dat_sol(x) freopen(x".dat", "r", stdin); freopen(x".sol", "w", stdout);
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
const double eps = 1e-9;
const ll md = 1e9 + 7;
const double EPS = 1e-5;
const ll maxll = std::numeric_limits<ll>::max();

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

template <typename name> inline name bpow(name base, ll exp, ll md = maxll)
{
    if (exp == 0) return 1;
    if (exp % 2 == 1)
        return (base * bpow(base, exp-1, md)) % md;
    else
    {
        name k = bpow(base, exp/2, md);
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
/*
struct Point
{
    ld x, y;
    int id;

    Point(ld _x_coord, ld _y_coord, int _id = -1)
    {
        x = _x_coord;
        y = _y_coord;
        id = _id;
    }

    Point() {}
};

const bool operator<(const Point& lhs, const Point& rhs)
{
    return (lhs.x < rhs.x);
}

struct Segment
{
    int upper_num, lower_num;
    ld x1, y1;
    ld x2, y2;
    Segment(Point _starting_point, Point _ending_point)
    {
        x1 = _starting_point.x;
        y1 = _starting_point.y;
        x2 = _ending_point.x;
        y2 = _ending_point.y;
    }
};

const bool operator<(const Segment& lhs, const Segment& rhs)
{
    if (lhs.x == rhs.x)
    {

    }
    else
    {

    }
}

int n, m, k;

main()
{
    files_dat_sol("archaeology");
    scanf(III, &n, &m, &k);
    for (int i=1; i<=n; i++)
    {
        int x, y;
        scanf(II, &x, &y);
        X[i] = cos(1) * x + sin(1) * y;
        Y[i] = -sin(1) * x + cos(1) * y;
        a.pb(Point(X[i], Y[i], i));
    }
    for (int i=0; i<m; i++)
    {
        int x, y;
        scanf(II, &x, &y);
        way[x].pb(y);
        way[y].pb(x);
    }
    for (int i=0; i<k; i++)
    {
        int x, y;
        scanf(II, &x, &y);
        ld X = cos(1) * x + sin(1) * y, Y = -sin(1) * x + cos(1) * y;
        a.pb(Point(X, Y));
    }
}
*/

int n, use[MAXN];
pii a[MAXN];
vii ans;

main()
{
    scanf(I, &n);
    for (int i=0; i<n; i++)
        scanf(I, &a[i].fi), a[i].se = i + 1;
    sort(a + 1, a + n);
    reverse(a + 1, a + n);
    int pos = 1;
    use[0] = 1;
    for (int i=0; i<n; i++)
    {
        if (!use[i]) return cout << -1, 0;
        for (int j=0; j<a[i].fi && pos < n; j++, pos++)
            ans.pb(mp(a[i].se, a[pos].se)), use[pos] = 1;
    }
    cout << ans.size() << "\n";
    for (auto q : ans)
        cout << q.fi << " " << q.se << "\n";
}