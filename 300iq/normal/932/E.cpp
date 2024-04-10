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
#include <iomanip>
#include <bitset>

using namespace std;

typedef long long ll;

mt19937 rnd(228);

const int N = 5000 + 7;
const int M = 1e9 + 7;

inline int add(int a, int b)
{
    a += b;
    if (a >= M) a -= M;
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

int dp[N][N];
int fact[N];
int rfact[N];

int C(int n, int k)
{
    int ret = 1;
    for (int i = n; i >= n - k + 1; i--) ret = mul(ret, i);
    ret = mul(ret, rfact[k]);
    return ret;
}

int main()
{
#ifdef ONPC
    freopen("a.in", "r", stdin);
#endif
    fact[0] = 1;
    for (int i = 1; i < N; i++)
    {
        fact[i] = mul(fact[i - 1], i);
    }
    for (int i = 0; i < N; i++)
    {
        rfact[i] = bin(fact[i], M - 2);
    }
    dp[0][0] = 1;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (i + 1 < N)
                dp[i + 1][j] = add(dp[i + 1][j], mul(dp[i][j], j));
            if (i + 1 < N && j + 1 < N)
                dp[i + 1][j + 1] = add(dp[i + 1][j + 1], dp[i][j]);
        }
    }
    int n, k;
    cin >> n >> k;
    int fact = 1;
    int ans = 0;
    for (int cnt = 1; cnt <= k; cnt++)
    {
        if (cnt > n) break;
        fact = mul(fact, cnt);
        int ret = mul(mul(mul(dp[k][cnt], fact), C(n, cnt)), bin(2, n - cnt));
        ans = add(ans, ret);
    }
    cout << ans << '\n';
}