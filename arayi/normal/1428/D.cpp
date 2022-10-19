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
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
char vow[] = { 'a', 'e', 'i', 'o', 'u' };
int dx[] = { 0, -1, 0, 1, -1, -1, 1, 1, 0 };
int dy[] = { -1, 0, 1, 0, -1, 1, -1, 1, 0 };


const int N = 1e6 + 30;
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


int n;
int a[N];
queue<pir> q, q1;
vector <pir> pat;
int main()
{
    fastio;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = n - 1; i >= 0; i--)
    {
        if (a[i] == 0) continue;
        if (a[i] == 1) q.push(MP(i + 1, i + 1)), pat.ad(MP(i + 1, i + 1));
        if (a[i] == 2)
        {
            if (q.empty()) return cout << -1 << endl, 0;
            auto p = q.front();
            q.pop();
            pat.ad(MP(i + 1, p.sc));
            q1.push(MP(i + 1, p.sc));
        }
        if (a[i] == 3)
        {
            if (q1.empty() && q.empty()) return cout << -1 << endl, 0;
            pir p;
            if (q1.empty()) p = q.front(), q.pop();
            else p = q1.front(), q1.pop();
            pat.ad(MP(i + 1, i + 1)), pat.ad(MP(p.fr, i + 1));
            q1.push(MP(i + 1, i + 1));
        }
    }
    cout << pat.size() << endl;
    for (auto p : pat) cout << p.sc << " " << p.fr << endl;
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