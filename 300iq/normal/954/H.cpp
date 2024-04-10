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

const int N = 20000 + 7;
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

int dp[N];
int ndp[N];
int ans[N];
int a[N];

int main()
{
#ifdef ONPC
    freopen("a.in", "r", stdin);
#endif
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n - 1; i++)
    {
        scanf("%d", &a[i]);
    }
    vector <int> pref(n);
    pref[0] = 1;
    for (int i = 1; i < n; i++)
    {
        pref[i] = mul(pref[i - 1], a[i - 1]);
    }
    dp[0] = 1;
    for (int i = n - 2; i >= 0; i--)
    {
        int x = a[i];
        ll cur = x * (ll) (x - 1) / 2;
        ll ot_cur = x * (ll) x;
        for (int j = 0; j < 2 * n; j++)
        {
            ans[j + 2] = add(ans[j + 2], mul(pref[i], mul(dp[j], cur % M)));
            ndp[j] = 0;
        }
        for (int j = 0; j < 2 * n; j++)
        {
            ndp[j + 2] = add(ndp[j + 2], mul(dp[j], ot_cur % M));
        }
        int lol = 1;
        int eds = 1;
        for (int go = i; go <= n - 2; go++)
        {
            lol = mul(lol, a[go]);
            ndp[eds] = add(ndp[eds], mul(lol, 2));
            ans[eds] = add(ans[eds], mul(pref[i], lol));
            eds++;
        }
        for (int j = 1; j < 2 * n; j++)
        {
            dp[j] = ndp[j];
        }
    }
    for (int k = 1; k <= 2 * n - 2; k++)
    {
        printf("%d ", ans[k]);
    }
    puts("");
}