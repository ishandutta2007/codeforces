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


const int N = 2e5 + 20;
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
str s;
lli pr[N][4];
lli pat;
int main()
{
    fastio;
    cin >> n;
    cin >> s;
    for (int i = 0; i < n; i++)
    {
        if (i) for (int j : { 0, 1, 2, 3 }) pr[i][j] = pr[i - 1][j];
        if (s[i] == '?') pr[i][3]++;
        else pr[i][s[i] - 'a']++;
    }
    for (int i = 1; i < n; i++)
    {
        if (s[i] == 'b')
        {
            pat += ((pr[i - 1][0] * (pr[n - 1][2] - pr[i][2])) % mod) * bp(3, pr[n - 1][3]);
            pat %= mod;
        }
    }
    if (pr[n - 1][3] >= 1)
    {
        for (int i = 1; i < n; i++)
        {
            if (s[i] == 'b')
            {
                pat += ((pr[i - 1][3] * (pr[n - 1][2] - pr[i][2])) % mod) * bp(3, pr[n - 1][3] - 1);
                pat %= mod;
                pat += ((pr[i - 1][0] * (pr[n - 1][3] - pr[i][3])) % mod) * bp(3, pr[n - 1][3] - 1);
                pat %= mod;
            }
            else if (s[i] == '?')
            {
                pat += ((pr[i - 1][0] * (pr[n - 1][2] - pr[i][2])) % mod) * bp(3, pr[n - 1][3] - 1);
                pat %= mod;
            }
        }
    }
    if (pr[n - 1][3] >= 2)
    {
        for (int i = 1; i < n; i++)
        {
            if (s[i] == 'b')
            {
                pat += ((pr[i - 1][3] * (pr[n - 1][3] - pr[i][3])) % mod) * bp(3, pr[n - 1][3] - 2);
                pat %= mod;
            }
            else if (s[i] == '?')
            {
                pat += ((pr[i - 1][0] * (pr[n - 1][3] - pr[i][3])) % mod) * bp(3, pr[n - 1][3] - 2);
                pat %= mod;
                pat += ((pr[i - 1][3] * (pr[n - 1][2] - pr[i][2])) % mod) * bp(3, pr[n - 1][3] - 2);
                pat %= mod;
            }
        }
    }
    if (pr[n - 1][3] >= 3)
    {
        for (int i = 1; i < n; i++)
        {
            if (s[i] == '?')
            {
                pat += ((pr[i - 1][3] * (pr[n - 1][3] - pr[i][3])) % mod) * bp(3, pr[n - 1][3] - 3);
                pat %= mod;
            }
        }
    }
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