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

int qq=1;
int n;
int a[N], b[N], qn[N];
vii fp[N];
int main()
{
    fastio;
    cin >> qq;
    while (qq--)
    {
        cin >> n;
        for (int i = 0; i < n; i++) 
        {
            cin >> a[i];
            qn[i]=1;
        }
        for (int i = 0; i < n; i++) cin >> b[i];
        for (int i = n - 1; i >= 0; i--) fp[a[i]].ad(i);
        int i1 = 0, i = 0;
        while (i < n && i1 < n)
        {
            if(b[i] == a[i1])
            {
                qn[i1]--;
                i++;
                if(qn[i1]==0) 
                {
                    fp[a[i1]].pop_back();
                    i1++;
                }
                continue;
            }
            fp[a[i1]].pop_back();
            if(fp[a[i1]].empty()) 
            {
                i=0;
                break;
            }
            qn[fp[a[i1]].back()]+=qn[i1];
            i1++;
        }
        if(i<n) cout << "NO\n";
        else cout << "YES\n";
        for (int i = 0; i < n; i++) fp[a[i]].clear();
        
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