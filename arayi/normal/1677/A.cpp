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

const int N = 1e5 + 20;
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


int t, n;
int a[N];
int t1[4*N], t2[4*N];
lli ans;
lli sum(int r) {
    int ret = 0;
    for (; r >= 0; r = (r & (r + 1)) - 1)
        ret += t1[r];
    return ret;
}

lli qry(int l, int r) {
    return sum(r) - sum(l - 1);
}

void upd(int idx, int delta) {
    for (; idx <= n; idx = idx | (idx + 1))
        t1[idx] += delta;
}
lli sum1(int r) {
    int ret = 0;
    for (; r >= 0; r = (r & (r + 1)) - 1)
        ret += t2[r];
    return ret;
}

lli qry1(int l, int r) {
    return sum1(r) - sum1(l - 1);
}

void upd1(int idx, int delta) {
    for (; idx <= n; idx = idx | (idx + 1))
        t2[idx] += delta;
}
int main()
{
    fastio;
    cin >> t;
    while (t--)
    {
        cin >> n;
        for (int i = 0; i < n; i++)
            cin >> a[i];
        ans = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j <= 4*n; j++) t1[j]=t2[j]=0;
            for (int j = i+2; j < n; j++)
                upd1(a[j], 1);
            lli sum = 0, sm = 0;
            for (int j = i+2; j < n; j++)
            {
                sm -= qry(a[j], n); 
                upd1(a[j], -1);   
                sm += qry1(1, a[j-1]);
                upd(a[j-1], 1);
                if(a[i] < a[j]) sum += sm;
            }
            ans += sum;
        }
        cout << ans << endl;
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