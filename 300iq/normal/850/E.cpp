
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

const int M = 1e9 + 7;

inline int add(int a, int b)
{
    return (a + b >= M ? a + b - M : a + b < 0 ? a + b + M : a + b);
}

inline int mul(int a, int b)
{
    return (a * (ll) b) % M;
}

const int N = (1 << 20);

ll res[N];
ll b[N];

void rec(int l, int r)
{
    if (r - l == 1)
    {
        b[l] = res[l];
    }
    else
    {
        int m = (l + r) / 2;
        rec(l, m);
        rec(m, r);
        for (int i = l; i < m; i++)
        {
            ll x = b[i], y = b[m + (i - l)];
            b[i] = x + y;
            b[m + (i - l)] = x - y;
        }
    }
}

int main()
{
#ifdef ONPC
    freopen("a.in", "r", stdin);
#endif
    int n;
    scanf("%d", &n);
    int bit = n;
    n = (1 << n);
    for (int i = 0; i < n; i++)
    {
        char c;
        scanf(" %c", &c);
        res[i] = c - '0';
    }
    rec(0, n);
    for (int i = 0; i < n; i++)
    {
        res[i] = b[i] * b[i];
    }
    rec(0, n);
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        int cnt = 0;
        for (int j = 0; j < bit; j++)
        {
            if (!((i >> j) & 1))
            {
                cnt++;
            }
        }
        b[i] /= n;
        ll cur = (1ll << cnt) % M;
        ans = add(ans, mul(cur, b[i] % M));
    }
    printf("%d\n", mul(ans, 3));
}