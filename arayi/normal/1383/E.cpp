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


const int N = 2e6 + 30;
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





str s;
lli dp[N], ap, dp1[N];
vector <pair<lli, lli> > fp;
int n;
int main()
{
    fastio;
    cin >> s;
    while (s[ap] == '0' && ap < s.length()) ap++;
    if (ap == s.length()) return cout << ap << endl, 0;
    for (int i = ap; i < s.length(); i++)
    {
        int sm = 1;
        while (i < s.length() - 1 && s[i] == s[i + 1]) i++, sm++;
        int ss = 1;
        i++;
        while (i < s.length() - 1 && s[i] == s[i + 1]) i++, ss++;
        fp.ad(MP(sm, ss));
    }
    if (s.back() == '1') fp.back().sc = 0;
    n = fp.size();
    dp[n] = 1;
    dp[n - 1] = (fp.back().fr * (fp.back().sc + 1LL)) % mod;
    stack <int> ss;
    for (int i = n - 2; i >= 0; i--)
    {
        while (!ss.empty() && fp[i].sc >= fp[ss.top()].sc) ss.pop();
        if (!ss.empty())
        {
            int i1 = ss.top();
            dp1[i] = dp1[i1] + (fp[i1].sc - fp[i].sc) * dp[i1 + 1], dp1[i] %= mod;
        }
        dp[i] = dp[i + 1] + (fp[i].fr * ((fp[i].sc * dp[i + 1]) % mod)) % mod + (dp1[i] * fp[i].fr) % mod + (fp[i].fr * (fp.back().sc + 1LL)) % mod, dp[i] %= mod;
        ss.push(i);
    }
    cout << (dp[0] * (ap + 1LL)) % mod << endl;
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