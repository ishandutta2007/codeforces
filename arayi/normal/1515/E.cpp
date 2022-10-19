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
lli mod = 1e17;
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


int n;
int dp[2][410][410][2], sf[2][410][410][2];
int main()
{
    fastio;
    cin >> n >> mod;
    dp[1][1][1][0] = dp[1][1][1][1] = 1;
    sf[1][1][1][1] = sf[1][1][1][0] = sf[1][1][0][1] = sf[1][1][0][0] = 1;
    swap(sf[0], sf[1]);
    swap(dp[0], dp[1]);
    for (int i = 2; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            for (int k = 1; k <= j; k++)
            {
                dp[1][j][k][0] = sf[0][j - 1][k][1];
                dp[1][j][k][1] = sf[0][j - 1][k][1];
                dp[1][j][k][0] += sf[0][j - 1][0][0] - sf[0][j - 1][k][0];
                dp[1][j][k][0] %= mod; if (dp[1][j][k][0] < 0) dp[1][j][k][0] += mod;
                //cout << i << " " << j << " " << k << "    " << dp[i][j][k][0] << " " << dp[i][j][k][1] << endl;
            }
            //cout << endl;
            dp[1][j][j + 1][1] += sf[0][j][0][0];
            dp[1][j][j + 1][1] %= mod;
        }
        //cout << endl;
        for (int j = 1; j <= i; j++)
            for (int k = j + 1; k >= 0; k--)
                for (auto p : { 0, 1 })
                    sf[1][j][k][p] = (sf[1][j][k + 1][p] + dp[1][j][k][p]) % mod;
        swap(sf[0], sf[1]);
        swap(dp[0], dp[1]);
        for (int j = 1; j <= i; j++)
            for (int k = 0; k <= j + 1; k++)
                for (auto p : { 0, 1 })
                    dp[1][j][k][p] = sf[1][j][k][p] = 0;
    }
    lli pat = 0;
    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= n; j++)
            pat += dp[0][i][j][0], pat %= mod;
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