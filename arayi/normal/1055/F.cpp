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
vector<pair<int, lli> > g[N];
unordered_map <lli, int> mp;
lli k, col[N], b[N];
pair<lli, int> cl[N];
bool a[N];
void dfs(int v, int par, lli x = 0)
{
    b[v] = x;
    for (auto p : g[v])
    {
        if (p.fr == par) continue;
        dfs(p.fr, v, x ^ p.sc);
    }
}
int main()
{
    fastio;
    cin >> n >> k;
    for (int i = 2; i <= n; i++)
    {
        int a;
        lli c;
        cin >> a >> c;
        g[a].ad({ i,c });
        g[i].ad({ a,c });
    }
    dfs(1, 1);
    lli ans = 0, sm = 0;
    sort(b + 1, b + n + 1);
    for (int i = 1; i <= n; i++) cl[i] = MP(0, i);
    a[n] = 1;
    for (int i = 62 - 1; i >= 0; i--)
    {
        sm += (1LL << i);
        for (int i = 1; i <= n; i++)
        {
            col[i] = (b[i] & sm);
            cl[i].fr = ((b[cl[i].sc] & sm) ^ ans);
        }
        //for (int i = 1; i <= n; i++) cout << cl[i].fr << " "; cout << endl;
        int i1 = 1, i2 = 1;
        lli sm1 = 1, sm2 = 1, s = 0;
        while (i1 <= n && i2 <= n)
        {
            while (i1 + 1 <= n && col[i1] == col[i1 + 1]) i1++, sm1++;
            while (i2 + 1 <= n && cl[i2].fr == cl[i2 + 1].fr) i2++, sm2++;
            if (col[i1] > cl[i2].fr) sm2 = 1, i2++;
            else if (col[i1] < cl[i2].fr) sm1 = 1, i1++;
            else s += sm1 * sm2, sm1 = sm2 = 1, i1++, i2++;
        }
        if (s < k)
        {
            k -= s;
            ans += (1LL << i);
            int i1 = -1, l = 1;
            for (int i = 1; i <= n; i++)
            {
                if (i < n && cl[i].fr != cl[i + 1].fr && !a[i]) i1 = i;
                if (a[i])
                {
                    if (i1 != -1)
                    {
                        reverse(cl + l, cl + i1 + 1);
                        reverse(cl + i1 + 1, cl + i + 1);
                        reverse(cl + l, cl + i + 1);
                    }
                    l = i + 1, i1 = -1;
                }
            }
        }
        for (int i = 1; i < n; i++)
            if (cl[i].fr != cl[i + 1].fr) a[i] = 1;
    }
    cout << ans << endl;
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