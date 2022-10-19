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
const lli mod = 1e9 + 7;
const ld pi = acos(-1);
const int T = 200;

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

int tt;
int n, m, k;
int i1, i2;
lli a[N], b[N];
int main()
{
    fastio;
    cin >> tt;
    while (tt--)
    {
        cin >> n >> k;
        lli sum = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            sum += a[i];
        }
        cin >> m;
        for (int i = 0; i < m; i++)
        {
            cin >> b[i];
            sum -= b[i];
        }
        i1 = 0;
        lli qn1 = 1;
        while (b[0] % k == 0)
            qn1 *= k, b[0] /= k;
        bool bl = 0;
        if (sum)
        {
            cout << "No\n";
            continue;
        }
        for (int i = 0; i < n; i++)
        {
            lli qn = 1;
            while (a[i] % k == 0)
                a[i] /= k, qn *= k;
            while (qn)
            {
                if (b[i1] != a[i])
                {
                    bl = 1;
                    break;
                }
                lli sm = min(qn, qn1);
                qn -= sm;
                qn1 -= sm;
                if (qn1 == 0)
                {
                    i1++;
                    if (i1 >= m)
                        break;
                    qn1 = 1;
                    while (b[i1] % k == 0)
                        b[i1] /= k, qn1 *= k;
                }
            }
            if (qn)
            {
                bl = 1;
                break;
            }
        }
        if (bl)
            cout << "No\n";
        else
            cout << "Yes\n";
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