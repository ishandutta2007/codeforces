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


int qq;
int n;
int a[N], b[N];
vii g[N];
bool col[N];
int dfs(int v)
{
    col[v] = 1;
    for(auto p : g[v])
    {
        if(col[p]) continue;
        return 1 + dfs(p);
    }
    return 1;
}
int main()
{
    fastio;
    cin >> qq;
    while (qq--)
    {
        cin >> n;
        for (int i = 0; i < n; i++) cin >> a[i];
        for (int i = 0; i < n; i++) cin >> b[i];
        for (int i = 0; i < n; i++)
        {
            g[a[i]].ad(b[i]);
            g[b[i]].ad(a[i]);
        }
        vii fp;
        for (int i = 1; i <= n; i++)
            if(!col[i]) fp.ad(dfs(i));
        lli l = 1, r = n;
        lli ans = 0;
        for(auto p : fp)
        {
            if(p%2==1) p--;
            lli nx = l;
            lli sk = l;
            for (int i = 0; i < p; i+=2)
            {
                ans += abs(l-nx);
                ans += r-l;
                l++;
                nx = r;
                r--;
            }
            ans += abs(nx-sk);
        }
        cout << ans << endl;
        for (int i = 0; i <= n; i++)
        {
            g[i].clear();
            col[i]=0;
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