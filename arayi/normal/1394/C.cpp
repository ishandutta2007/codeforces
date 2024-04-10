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
const lli mod = 998244353;
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


int n, mns = mod, mnt = mod, mxs, mxt;
str s[N];
vii fp[N];
int pat = mod, pta, ptb;
int mn[N];
int main()
{
    fastio;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> s[i];
        int a = 0, b = 0;
        for (auto p : s[i])
        {
            if (p == 'B') a++;
            else b++;
        }
        fp[a].ad(b);
        mns = min(mns, a);
        mxs = max(mxs, a);
        mnt = min(mnt, b);
        mxt = max(mxt, b);
    }
    mn[mxs + 1] = mod;
    for (int i = mxs; i >= mns; i--)
    {
        mn[i] = mn[i + 1];
        for (auto b : fp[i]) mn[i] = min(mn[i], b - i);
    }
    int mx = -mod;
    for (int i = mns; i <= mxs; i++)
    {
        int ans = max(i - mns, mxs - i);
        for (auto b : fp[i]) mx = max(mx, b - i);
        itn dz = min(mnt, mn[i + 1] + i);
        int aj = max(mxt, mx + i);
        //cout << dz << " " << aj << endl;
        int mid = max(max(0, 1 - i), (dz + aj) / 2);
        ans = max(ans, max(aj - mid, mid - dz));
        if (ans < pat)
        {
            pat = ans;
            pta = i;
            ptb = mid;
        }
    }
    cout << pat << endl;
    for (int i = 0; i < pta; i++) cout << 'B';
    for (int i = 0; i < ptb; i++) cout << 'N';
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