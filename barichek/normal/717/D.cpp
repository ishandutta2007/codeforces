///----------------------------Template-----------------------///

#include <bits/stdc++.h>

#define pb push_back
#define mp make_pair
#define fi first
#define prev asfansjfansjabfasjlbfa
#define se second
#define I "%d"
#define II "%d%d"
#define III "%d%d%d"
#define elif else if
#define out_files(name) freopen(name".in","r",stdin); freopen(name".out","w",stdout);
#define all(x) (x).begin(), (x).end()
#define len(x) int((x).size())
#define fast ios_base::sync_with_stdio(0)
#define y1 asnflainflawnfaw
#define y0 snalfklawnfasdaspqw
#define next asfnlafnaldnffa

using namespace std;

typedef vector <int> vi;
typedef long long ll;
typedef unsigned long long ull;
typedef pair <int, int> pii;
typedef vector <pii> vii;
typedef double ld;

#ifdef WIN32
    #define I64 "%I64d"
#else
    #define I64 "%lld"
#endif // WIN32

const int inf = 1000000000;
const ll INF = 1LL*inf*inf;
const double eps = 1e-9;
const int md = (int)1e9 + 7;
const double EPS = 1e-7;
const ll maxll = numeric_limits<ll>::max();
const ld PI = acos(-1.0);

template <typename name> inline name sqr(name x)
{
    return x * x;
}

inline ll multmod(ll a, ll b, ll md)
{
    if (!a) return 0;
    if (a % 2 == 1)
        return (multmod(a - 1, b, md) + b) % md;
    else
        return sqr<ll>(multmod(a / 2, b, md)) % md;
}

template <typename name> inline name bpow(name base, ll exp)
{
    name res = base;
    while (exp)
    {
        if (exp % 2 == 1)
        {
            res = res * base;
        }
        base = base * base;
        exp /= 2;
    }
    return res;
}

///-------------------------End of Template-------------------------///

int n, x, m;
ld p[2000];

struct matr
{
    ld a[1<<7][1<<7];
} mat, qq;

const matr& operator *(const matr& x, const matr& y)
{
    for (int i=0; i<(1<<7); i++)
        for (int j=0; j<(1<<7); j++)
            qq.a[i][j] = 0;
    for (int i=0; i<(1<<7); i++)
        for (int j=0; j<(1<<7); j++)
            for (int k=0; k<(1<<7); k++)
                qq.a[i][j] += x.a[i][k] * y.a[k][j];
    return qq;
}
/*
matr bpow(matr x, int exp)
{
    cout << (exp == 2) << "\n";
    if (exp == 2)
    {
        cout << -1;
        exit(0);
    }
    //exit(0);
    if (exp == 1)
        return x;
    if (exp % 2 == 1)
        return mult(bpow(x, exp-1), x);
    else
    {
        matr q = bpow(x, exp/2);
        return mult(q, q);
    }
}
*/
main()
{
    ios_base :: sync_with_stdio(0);
    cin >> n >> x;
    for (int i=0; i<=x; i++)
        cin >> p[i];
    for (int mask1 = 0; mask1 < (1 << 7); mask1++)
        for (int mask2 = 0; mask2 < (1 << 7); mask2++)
            mat.a[mask1][mask2] = p[mask1 ^ mask2];
    mat = bpow(mat, n-1);
    cout << fixed << setprecision(10) << 1 - mat.a[0][0];
    return 0;
}