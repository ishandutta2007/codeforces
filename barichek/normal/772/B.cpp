///      That's a Cigarette Day, my Sun

#include <bits/stdc++.h>

#pragma pack(1)
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
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
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

template<typename T1, typename T2> inline T1 min(const T1 x, const T2 y)
{
    return (x > y ? y : x);
}

template<typename T1, typename T2> inline T1 max(const T1 x, const T2 y)
{
    return (x < y ? y : x);
}

template<typename T1, typename T2> ostream& operator<<(ostream& os, const pair<T1, T2>& rhs)
{
    os << rhs.fi << " " << rhs.se;
    return os;
}

template<typename T1> ostream& operator<<(ostream& os, const vector<T1>& rhs)
{
    for (int i=0; i<(int)rhs.size(); i++)
        cout << rhs[i] << (i == (int)rhs.size() - 1 ? "" : " ");
    return os;
}

///-------------------------End of Template-------------------------///

const int MAXN = 2e5;

int n;
ld x[MAXN], y[MAXN];

ld Square(ld a, ld b, ld c)
{
    ld p = (a + b + c) / ld(2);
    ld S = sqrt(p) * sqrt(p - a) * sqrt(p - b) * sqrt(p - c);
    return S;
}

main()
{
    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
        freopen("debug.txt", "w", stderr);
    #else
        files("");
    #endif // LOCAL

    scanf(I, &n);
    for (int i=0; i<n; i++)
    {
        cin >> x[i] >> y[i];
    }
    x[n] = x[0];
    y[n] = y[0];
    x[n + 1] = x[1];
    y[n + 1] = y[1];

    ld mn = INF;
    for (int i=0; i<n; i++)
        for (int j=i+1; j<n; j++)
            mn = min(mn, sqrt(sqr(x[i] - x[j]) + sqr(y[i] - y[j])));
    mn /= ld(2);

    for (int i=0; i<n; i++)
    {
        ld a = sqrt(sqr(x[i + 2] - x[i + 1]) + sqr(y[i + 2] - y[i + 1]));
        ld b = sqrt(sqr(x[i + 1] - x[i]) + sqr(y[i + 1] - y[i]));
        ld c = sqrt(sqr(x[i + 2] - x[i]) + sqr(y[i + 2] - y[i]));

        mn = min(mn, Square(a, b, c) / c);
    }
    cout << fixed << setprecision(10) << mn;
}