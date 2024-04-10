//Arayi
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
#include <chrono>
#include <random>

#define fr first
#define sc second
#define MP make_pair
#define ad push_back
#define PB push_back
#define fastio ios_base::sync_with_stdio(false); cin.tie(0);
#define lli unsigned long long int
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
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
char vow[] = { 'a', 'e', 'i', 'o', 'u' };
int dx[] = { 1, -1, 0, 0, -1, -1, 1, 1, 0 };
int dy[] = { 0, 0, 1, -1, -1, 1, -1, 1, 0 };


const int N = 1e5 + 30;
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



int n;
int nx, nw = 1, i1 = 2;
int a1[2200][2200];
int ask(int i, int j)
{
    if (a1[i][j]) return a1[i][j];
    cout << "? " << i << " " << j << endl;
    int sm;
    cin >> sm;
    a1[i][j] = a1[j][i] = sm;
    return sm;
}
int stg(int a, int b)
{
    if (a == b) return a;
    int i1 = 0;
    do
    {
        i1 = 1 + rnd() % n;
    } while (i1 == a || i1 == b);
    int sm = ask(a, i1);
    bool bl1, bl2;
    bl1 = bl2 = false;
    for (int j = 0; j < 12; j++)
    {
        if ((1 << j) & nx)
        {
            if (!((1 << j) & sm)) bl1 = true;
        }
        else
        {
            if ((1 << j) & sm) bl2 = true;
        }
    }
    if (bl1 && bl2)
    {
        return a;
    }
    else if (bl1)
    {
        return b;
    }
    else if (bl2)
    {
        return stg(b, a);
    }
    else
    {
        return b;      
    }
}
vector <int> pat;
int b[2200];
int main()
{
    fastio;
    cin >> n;
    nx = ask(1, 2);
    for (int i = 3; i <= n; i++)
    {
        b[i - 3] = i;
    }
    random_shuffle(b, b + n - 2);
    for (int i = 0; i <= n - 3; i++)
    {
        itn sm = ask(nw, b[i]);
        bool bl1, bl2;
        bl1 = bl2 = false;
        for (int j = 0; j < 12; j++)
        {
            if ((1 << j) & nx)
            {
                if (!((1 << j) & sm)) bl1 = true;
            }
            else
            {
                if ((1 << j) & sm) bl2 = true;
            }
        }
        if (bl1 && bl2)
        {
            if (i < n - 3)
            {
                nx = ask(nw, b[i + 1]);
                i1 = b[i + 1];
                i++;
            }
            else
            {
                i1 = nw;
            }
        }
        else if (bl1)
        {
            nx = sm;
            i1 = b[i];
        }
        else if (bl2)
        {
            continue;
        }
        else
        {
            nw = i1;
            i1 = b[i];
            nx = ask(nw, i1);
        }
    }
   // cout << nw << " " << i1 << " " << nx << endl;
    nw = stg(nw, i1);
    for (int i = 1; i <= n; i++)
    {
        if (i == nw) pat.ad(0);
        else pat.ad(ask(i, nw));
    }
    cout << "! ";
    for (auto p : pat) cout << p << " ";
    cout << endl;
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