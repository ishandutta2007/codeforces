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
template<class T>
void maxi(T& a, T b)
{
    a = max(a, b);
}
template <class T>
void mini(T& a, T b)
{
    a = min(a, b);
}


itn n, pat;
int g[N], col[N], cl[N];
void rec(int l, int r)
{
    if (l >= r) return;
    int a = l, b = r;
    int mk = 0, zr = 0;
    int i1 = l, i2 = r;
    while (i1 <= a || i2 >= b)
    {
        if (i1 <= a)
        {
            if (cl[i1])
            {
                i1++;
                continue;
            }
            if (col[i1]) mk++;
            else zr++;
            if (g[i1] > b || g[i1] < a)
            {
                cout << -1 << endl;
                exit(0);
            }
            cl[g[i1]] = 1;
            cl[i1] = 1;
            b = g[i1];
            i1++;
        }
        else
        {
            if (cl[i2])
            {
                i2--;
                continue;
            }
            if (col[i2]) mk++;
            else zr++;
            if(g[i2] > b || g[i2] < a)
            {
                cout << -1 << endl;
                exit(0);
            }
            cl[g[i2]] = 1;
            cl[i2] = 1;
            a = g[i2];
            i2--;
        }
    }
    pat += min(zr, mk);
    rec(i1, i2);
}
int main()
{
    fastio;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        itn a, b;
        cin >> a >> b;
        g[a] = b;
        g[b] = a;
        col[b] = 1;
    }
    rec(1, 2 * n);
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