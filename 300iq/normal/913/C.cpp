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

int main()
{
#ifdef ONPC
    freopen("a.in", "r", stdin);
#endif
    int n, l;
    scanf("%d%d", &n, &l);
    vector <ll> c(41, LLONG_MAX);
    for (int i = 0; i < n; i++)
    {
        scanf("%lld", &c[i]);
    }
    for (int i = 1; i <= 30; i++)
    {
        c[i] = min(c[i], 2 * c[i - 1]);
    }
    ll ans = 0;
    ll res = LLONG_MAX;
    for (int i = 30; i >= 0; i--)
    {
        if ((l >> i) & 1)
        {
            ans += c[i];
        }
        else
        {
            res = min(res, ans + c[i]);
        }
    }
    printf("%lld\n", min(ans, res));
}