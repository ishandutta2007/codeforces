//#define _CRT_SECURE_NO_WARNINGS
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

#define fr first
#define sc second
#define MP make_pair
#define ad push_back
#define PB push_back
#define fastio ios_base::sync_with_stdio(false); cin.tie(0);
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
char vow[] = { 'a', 'e', 'i', 'o', 'u' };
int dx[] = { 1, -1, 0, 0, -1, -1, 1, 1, 0 };
int dy[] = { 0, 0, 1, -1, -1, 1, -1, 1, 0 };


const int N = (1 << 20) + 30;
const lli mod = 1e9 + 7;
const ld pi = acos(-1);
const int T = 238;
const ld e = 1e-13;

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


lli k, a, b;
int c[3][3], d[3][3];
lli col[3][3];
int a1, b1;
vector<pir> sm;
lli sm1, sm2;
void dfs(int a, int b, int xr)
{
    if (col[a][b])
    {
        lli i1 = col[a][b] - 1LL;
        for (int i = 0; i < min(i1, k); i++)
        {
            if (sm[i].fr == sm[i].sc) continue;
            if (sm[i].fr == 0)
            {
                if (sm[i].sc == 1) sm2++;
                else sm1++;
            }
            else if (sm[i].fr == 1)
            {
                if (sm[i].sc == 0) sm1++;
                else sm2++;
            }
            else
            {
                if (sm[i].sc == 1) sm1++;
                else sm2++;
            }
        }
        k -= min(i1, k);
        lli sz = sm.size() - i1;
        for (itn i = i1; i < sm.size(); i++)
        {
            if (sm[i].fr == sm[i].sc) continue;
            if (sm[i].fr == 0)
            {
                if (sm[i].sc == 1) sm2 += k / sz;
                else sm1 += k / sz;
            }
            else if (sm[i].fr == 1)
            {
                if (sm[i].sc == 0) sm1 += k / sz;
                else sm2 += k / sz;
            }
            else
            {
                if (sm[i].sc == 1) sm1 += k / sz;
                else sm2 += k / sz;
            }
        }
        for (int i = i1; i < i1 + (k % sz); i++)
        {
            if (sm[i].fr == sm[i].sc) continue;
            if (sm[i].fr == 0)
            {
                if (sm[i].sc == 1) sm2++;
                else sm1++;
            }
            else if (sm[i].fr == 1)
            {
                if (sm[i].sc == 0) sm1++;
                else sm2++;
            }
            else
            {
                if (sm[i].sc == 1) sm1++;
                else sm2++;
            }
        }
        return;
    }
    col[a][b] = xr;
    sm.ad(MP(a, b));
    int a1 = a, b1 = b;
    a = c[a1][b1];
    b = d[a1][b1];
    dfs(a, b, xr + 1);
}
void dfs1(int a, int b, int xr)
{
    if (xr == 0)return;
    if (a != b)
    {
        if (a > b)
        {
            if (a == 2 && b == 0) sm2++;
            else sm1++;
        }
        else
        {
            if (a == 0 && b == 2) sm1++;
            else sm2++;
        }
    }
    int a1 = a, b1 = b;
    a = c[a1][b1];
    b = d[a1][b1];
    dfs1(a, b, xr - 1);
}
int main()
{
    fastio;
    cin >> k >> a >> b;
    a--, b--;
    
    
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cin >> c[i][j];
            c[i][j]--;
        }
    }
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cin >> d[i][j];
            d[i][j]--;
        }
    }
    if (k < 100)
    {
        dfs1(a, b, k);
        cout << sm1 << " " << sm2 << endl;
        return 0;
    }
    dfs(a, b, 1);
    cout << sm1 << " " << sm2 << endl;
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