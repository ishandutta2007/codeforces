#include <cmath>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <map>
#include <list>
#include <time.h>
#include <math.h>
#include <random>
#include <deque>
#include <queue>
#include <cassert>
#include <unordered_map>
#include <unordered_set>
#include <iomanip>
#include <bitset>
#include <sstream>
#include <chrono>

using namespace std;

typedef long long ll;

#ifdef ONPC
    mt19937 rnd(228);
#else
    mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
#endif

const int M = 1e9 + 7;

inline int add(int a, int b)
{
    a += b;
    if (a >= M) a -= M;
    if (a < 0) a += M;
    return a;
}

inline int mul(int a, int b)
{
    return (a * (ll) b) % M;
}

inline int bin(int a, int n)
{
    int res = 1;
    while (n)
    {
        if (n % 2 == 0)
        {
            a = mul(a, a);
            n /= 2;
        }
        else
        {
            res = mul(res, a);
            n--;
        }
    }
    return res;
}

int inv(int x)
{
    return bin(x, M - 2);
}

const int N = 1e4 + 7;
const int P = 60;

int dp[N][P];
int rev[P];

int solve(ll p, int deg, int k)
{
    for (int i = 0; i <= k; i++) for (int j = 0; j <= deg; j++) dp[i][j] = 0;
    dp[0][deg] = 1;
    for (int i = 0; i < k; i++)
    {
        for (int j = 0; j <= deg; j++)
        {
            int kek = rev[j + 1];
            for (int it = j; it >= 0; it--)
            {
                dp[i + 1][it] = add(dp[i + 1][it], mul(dp[i][j], kek));
            }
        }
    }
    int ans = 0;
    ll pw = 1;
    for (int j = 0; j <= deg; j++)
    {
        int op = pw % M;
        ans = add(ans, mul(dp[k][j], op));
        pw *= p;
    }
    return ans;
}

int main()
{
#ifdef ONPC
    freopen("a.in", "r", stdin);
#endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    for (int i = 0; i < P; i++) rev[i] = inv(i);
    ll n;
    int k;
    cin >> n >> k;
    vector <pair <ll, int> > ret;
    for (ll i = 2; i * i <= n; i++)
    {
        int deg = 0;
        while (n % i == 0)
        {
            n /= i;
            deg++;
        }
        if (deg > 0)
        {
            ret.push_back({i, deg});
        }
    }
    if (n != 1)
        ret.push_back({n, 1});
    int x = 1;
    for (auto c : ret)
    {
        x = mul(x, solve(c.first, c.second, k));
    }
    cout << x << '\n';
}