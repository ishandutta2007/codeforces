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


int n;
int a[N], i1;
lli ss[15];
void ask(int i1)
{
    vector<int> fp;
    for (int i = 1; i <= n; i++)
    {
        if ((1 << i1) & a[i]) fp.ad(i);
    }
    if (!fp.empty())
    {
        cout << "? ";
        cout << fp.size() << " ";
        for (auto& p : fp) cout << p << " ";
        cout << endl;
        lli sm;
        cin >> sm;
        ss[i1] = sm;
    }
}
int main()
{
    fastio;
    for (int x = 0; x < (1 << 13); x++)
    {
        int mq = 0;
        for (int i = 0; i < 13; i++)
        {
            if ((1 << i) & x) mq++;
        }
        if (mq == 6)
        {
            a[++i1] = x;
        }
    }
    cin >> n;
    for (int i = 0; i < 13; i++)
        ask(i);
    cout << "! ";
    for (int i = 1; i <= n; i++)
    {
        lli pat = 0;
        for (int j = 0; j < 13; j++)
        {
            if ((1 << j) & a[i]) continue;
            pat |= ss[j];
        }
        cout << pat << " ";
    }
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