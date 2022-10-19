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
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
char vow[] = { 'a', 'e', 'i', 'o', 'u' };
int dx[] = { 1, -1, 0, 0, -1, -1, 1, 1, 0 };
int dy[] = { 0, 0, 1, -1, -1, 1, -1, 1, 0 };


const int N = 2e5 + 30;
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


int t;
int n, m;
char a[55][55];
bool col[55][55];
void dfs(int i, int j)
{
    col[i][j] = true;
    for (int k = 0; k < 4; k++)
    {
        int i1 = i + dx[k];
        int j1 = j + dy[k];
        if (i1 < 1 || j1 < 1 || i1 > n || j1 > m || col[i1][j1] || a[i1][j1] == '#') continue;
        dfs(i1, j1);
    }
}
int main()
{
    fastio;
    cin >> t;
    while (t--)
    {
        cin >> n >> m;
        bool bl = false;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                cin >> a[i][j];
                col[i][j] = false;
                if (a[i][j] == 'G') bl = true;
            }
        }
        if (!bl)
        {
            cout << "Yes\n";
            continue;
        }
        bl = false;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                if (a[i][j] == 'B')
                {
                    for (int k = 0; k < 4; k++)
                    {
                        if (i + dx[k] > n || j + dy[k] > m || j + dy[k] < 1 || i + dx[k] < 1) continue;
                        if (a[i + dx[k]][j + dy[k]] == 'G')
                        {
                            bl = true;
                            break;
                        }
                        if (a[i + dx[k]][j + dy[k]] == 'B') continue;
                        a[i + dx[k]][j + dy[k]] = '#';
                    }
                }
            }
        }
        if (bl || a[n][m] == '#')
        {
            cout << "No\n";
            continue;
        }
        dfs(n, m);
        bl = false;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                if (a[i][j] == 'G' && !col[i][j]) bl = true;
            }
        }
        if (bl) cout << "No\n";
        else cout << "Yes\n";
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