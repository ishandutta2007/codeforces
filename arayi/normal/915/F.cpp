//Arayi
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <queue>
#include <stack>
#include <algorithm>
#include <math.h>
#include <vector>
#include <cstring>
#include <ctime>
#include <set>
#include <bitset>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <iomanip>
#include <ctime>
#include <climits>
#include <cassert>
#include <chrono>
#include <random>
#include <complex>

#define fr first
#define sc second
#define MP make_pair
#define ad push_back
#define PB push_back
#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
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
char vow[] = { 'a', 'e', 'i', 'o', 'u' };
int dx[] = { 0, -1, 0, 1, -1, -1, 1, 1, 0 };
int dy[] = { -1, 0, 1, 0, -1, 1, -1, 1, 0 };


const int N = 1e6 + 30;
const lli mod = 998244353;
const ld pi = acos(-1);
const int T = 550;

lli bp(lli a, lli b = mod - 2LL)
{
    lli ret = 1;
    while (b)
    {
        if (b & 1) ret *= a, ret %= mod;
        a *= a;
        a %= mod;
        b >>= 1;
    }
    return ret;
}
ostream& operator<<(ostream& c, pir a)
{
    c << a.fr << " " << a.sc;
    return c;
}
void maxi(lli& a, lli b)
{
    a = max(a, b);
}


int n;
vii g[N];
lli pat, a[N];
int p[N];
lli sz[N];
bool cl[N];
vector<pair<lli, int>> fp;
int gp(int x)
{
    if (p[x] == x) return x;
    return p[x] = gp(p[x]);
}
void slv()
{
    for (auto& p : fp)
    {
        int v = p.sc;
        lli sum = 0;
        for (auto p1 : g[v]) sum += sz[gp(p1)];
        sz[v] = sum + 1;
        cl[v] = 0;
        lli sm = 0;
        for (auto p1 : g[v])
        {
            if (cl[p1]) continue;
            sm += p.fr * (sum - sz[gp(p1)]) * sz[gp(p1)];
            ::p[gp(p1)] = v;
        }
        sm >>= 1;
        sm += sum * p.fr;
        pat += sm;
    }
}
int main()
{
    fastio;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i + 1];
    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        g[a].ad(b);
        g[b].ad(a);
    }
    for (int i = 1; i <= n; i++)
    {
        sz[i] = 0;
        p[i] = i;
        fp.ad(MP(a[i], i));
        cl[i] = 1;
    }
    sort(all(fp));
    slv();
    for (int i = 1; i <= n; i++)
    {
        sz[i] = 0;
        p[i] = i;
        fp[i - 1].fr *= -1;
        cl[i] = 1;
    }
    sort(all(fp));
    slv();
    cout << pat << endl;
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