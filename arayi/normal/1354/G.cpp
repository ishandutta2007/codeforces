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
#include <complex>

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
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
char vow[] = { 'a', 'e', 'i', 'o', 'u' };
int dx[] = { 1, -1, 0, 0, -1, -1, 1, 1, 0 };
int dy[] = { 0, 0, 1, -1, -1, 1, -1, 1, 0 };


const int N = 5e5 + 30;
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
struct pt
{
    lli x, y;
    int ind;
    int bl;
    bool operator==(const pt& a)
    {
        return ind == a.ind;
    }
    bool operator<(const pt& b)
    {
        if (x == b.x) return y < b.y;
        return x < b.x;
    }
};





int t, n, k;
int ask(int l1, int r1, int l2, int r2)
{
    cout << "? " << r1 - l1 + 1 << " " << r2 - l2 + 1 << endl;
    for (int i = l1; i <= r1; i++)
    {
        cout << i << " ";
    }
    cout << endl;
    for (int i = l2; i <= r2; i++)
    {
        cout << i << " ";
    }
    cout << endl;
    string s;
    cin >> s;
    if (s[0] == 'W') exit(0);
    else if (s[0] == 'E') return 0;
    else if (s[0] == 'F') return 1;
    else return -1;
}
int main()
{
    fastio;
    cin >> t;
    for(int x = 0; x < t; x++)
    {
        cin >> n >> k;
        bool bl = false;
        for (int j = 0; j < 30; j++)
        {
            int i1 = abs((int)rnd()) % (n - 1) + 2;
            if (ask(1, 1, i1, i1) == -1)
            {
                cout << "! 1" << endl;
                bl = true;
                break;
            }
        }
        if (bl) continue;;
        int l = -1, r = -1;
        for (int i = 1; i <= n; i *= 2)
        {
            if (2 * i > n) l = i + 1, r = n;
            else if (ask(1, i, i + 1, 2 * i))
            {
                l = i + 1;
                r = 2 * i;
                break;
            }
        }
        if (l == -1) continue;
        int ans = r;
        while (l <= r)
        {
            itn mid = (l + r) / 2;
            if (ask(1, mid - l + 1, l, mid))
            {
                ans = mid;
                r = mid - 1;
            }
            else
            {
                l = mid + 1;
            }
        }
        cout << "! " << ans << endl;
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