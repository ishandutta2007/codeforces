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
#define out_files freopen("ladder.in", "r", stdin);freopen("ladder.out", "w", stdout)
#define all(x) (x).begin(), (x).end()
#define fast ios_base::sync_with_stdio(0)
#define y1 asnflainflawnfaw
#define y0 snalfklawnfasdaspqw

using namespace std;

typedef vector <int> vi;
typedef long long ll;
typedef unsigned long long ull;
typedef pair <int, int> pii;
typedef vector <pii> vii;
typedef long double ld;

#ifdef WIN32
    #define I64 "%I64d"
#else
    #define I64 "%lld"
#endif // WIN32

const int inf = 1000000000;
const ll INF = 1LL*inf*inf;
const double eps = 1e-9;
const int MAXN = 2500;
const int md = (int)1e9 + 7;
const double EPS = 1e-5;
const ll maxll = numeric_limits<ll>::max();

template <typename name> inline name sqr(name x)
{
    return x*x;
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

///-------------------------End of Template-------------------------///

ll n;

int main()
{
    cin >> n;
    cout << (n+1)/2;
    return 0;
}