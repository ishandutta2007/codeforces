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

int f(int n)
{
    int ans = 1;
    while (n)
    {
        if (n % 10 != 0)
        {
            ans *= (n % 10);
        }
        n /= 10;
    }
    return ans;
}

int g(int n)
{
    if (n < 10)
    {
        return n;
    }
    else
    {
        return g(f(n));
    }
}

const int N = 1e6 + 7;

int ans[N][11];

int main()
{
#ifdef ONPC
    freopen("a.in", "r", stdin);
#endif
    for (int k = 1; k <= 9; k++)
    {
        int s = 0;
        for (int i = 1; i < N; i++)
        {
            s += (g(i) == k);
            ans[i][k] = s;
        }
    }
    int q;
    scanf("%d", &q);
    while (q--)
    {
        int l, r, k;
        scanf("%d%d%d", &l, &r, &k);
        printf("%d\n", ans[r][k] - ans[l - 1][k]);
    }
}