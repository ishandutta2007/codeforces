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

int qq;
lli n, m;
bool stg(lli i)
{
    if(i>n||i>m) return 0;
    if(n%i>2||m%i>2) return 0;
    if(i<=2) return 1;
    if(n%i==2 && m%i==0) return 1;
    if(m%i==2 && n%i==0) return 1;
    if(n%i==2 || m%i==2) return 0;
    if(n%i==1 && m%i==1) return 1;
    return 0;
}
int main()
{
    fastio;
    cin >> qq;
    while (qq--)
    {
        cin >> n >> m;
        vector<lli> fp;
        lli sm = 2LL*(n+m-2);
        for (lli i = 1; i*i <= sm; i++)
        {
            if(sm%i==0)
            {
                if(stg(i)) fp.ad(i);
                if(i!=sm/i && stg(sm/i)) fp.ad(sm/i);
            }
        }
        sort(all(fp));
        cout << fp.size() << " ";
        for(auto p : fp) cout << p << " ";
        cout << endl;
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