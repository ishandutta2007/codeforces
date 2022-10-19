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

int t, n;
int a[N], dp[N];
int main()
{
    fastio;
    cin >> t;
    while (t--)
    {
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        if (a[0])
            dp[0] = 1;
        else
            dp[0] = 0;
        int sm = a[0];
        for (int i = 1; i < n; i++)
        {
            dp[i] = dp[i - 1] + (a[i] != 0);
            int sm1 = sm;
            for (int j = 0; j < i; j++)
            {
                int ss = 0;
                if (j)
                    ss = dp[j - 1];
                ss += i - j;
                ss += ((sm1 ^ a[i]) != 0);
                mini(dp[i], ss);
                sm1 ^= a[j];
            }
            sm ^= a[i];
        }
        cout << dp[n - 1] << endl;
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