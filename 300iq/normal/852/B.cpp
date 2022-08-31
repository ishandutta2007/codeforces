
/*
    !  !!!
   
   
   
   
   
   
   
   
   
   
   
*/

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

using namespace std;

typedef long long ll;

mt19937 rnd(228);

int n, l, m;

const int M = 1e9 + 7;

inline int mul(int a, int b)
{
    return (a * (ll) b) % M;
}

inline int add(int a, int b)
{
    return (a + b >= M ? a + b - M : a + b);
}

vector <int> ans(const vector <int> &a, int n)
{
    if (n == 0)
    {
        vector <int> ans(m);
        ans[0] = 1;
        return ans;
    }
    if (n == 1)
    {
        return a;
    }
    else
    {
        if (n % 2 == 0)
        {
            auto kek = ans(a, n / 2);
            vector <int> cur(m);
            for (int i = 0; i < m; i++)
            {
                for (int j = 0; j < m; j++)
                {
                    cur[(i + j) % m] = add(cur[(i + j) % m], mul(kek[i], kek[j]));
                }
            }
            return cur;
        }
        else
        {
            auto kek = ans(a, n - 1);
            vector <int> cur(m);
            for (int i = 0; i < m; i++)
            {
                for (int j = 0; j < m; j++)
                {
                    cur[(i + j) % m] = add(cur[(i + j) % m], mul(kek[i], a[j]));
                }
            }
            return cur;
        }
    }
}

int main()
{
#ifdef ONPC
    freopen("a.in", "r", stdin);
#endif
    scanf("%d%d%d", &n, &l, &m);
    vector <int> dp(m);
    vector <int> in(n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &in[i]);
        dp[in[i] % m]++;
    }
    vector <int> go(n);
    vector <int> cnt(m);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &go[i]);
        cnt[go[i] % m]++;
    }
    vector <int> out(n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &out[i]);
    }
    auto cur = ans(cnt, l - 2);
    vector <int> other(m);
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < m; j++)
        {
            other[(i + j) % m] = add(other[(i + j) % m], mul(dp[i], cur[j]));
        }
    }
    int result = 0;
    for (int i = 0; i < m; i++)
    {
        for (int v = 0; v < n; v++)
        {
            if ((i + go[v] + out[v]) % m == 0)
            {
                result = add(result, other[i]);
            }
        }
    }
    printf("%d\n", result);
}