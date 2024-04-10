
/*
   
   
   
   
   
   
   
   
   
   
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

int n, s;

const int N = 1e5 + 7;

int x[N], a[N], b[N];

ll need;

ll f(ll first)
{
    ll second = (need - first);
    first *= s;
    second *= s;
    vector <pair <int, int> > e;
    ll cur_sum = 0;
    ll sum_need = 0;
    for (int i = 0; i < n; i++)
    {
        sum_need += x[i];
        cur_sum += a[i] * (ll) x[i];
        e.push_back({b[i] - a[i], i});
    }
    ll left = sum_need - first, right = second;
    ll cur_have = 0;
    ll cur_grabbed = 0;
    ll ans = -1e18;
    sort(e.rbegin(), e.rend());
    for (auto c : e)
    {
        int i = c.second;
        ll can_max_push = min((ll) x[i], right - cur_have);
        if (cur_have + can_max_push >= left)
        {
            ans = max(ans, cur_sum + can_max_push * (b[i] - a[i]) + cur_grabbed);
        }
        ll can_min_push = max(0ll, min((ll) x[i], left - cur_have));
        if (cur_have + can_min_push >= left)
        {
            ans = max(ans, cur_sum + can_min_push * (b[i] - a[i]) + cur_grabbed);
        }
        cur_have += can_max_push;
        cur_grabbed += can_max_push * (b[i] - a[i]);
    }
    return ans;
}

int main()
{
#ifdef ONPC
    freopen("a.in", "r", stdin);
#endif
    scanf("%d%d", &n, &s);
    ll sum = 0;
    for (int i = 0; i < n; i++)
    {
        scanf("%d%d%d", &x[i], &a[i], &b[i]);
        sum += x[i];
    }
    need = (sum / s) + bool(sum % s);
    ll l = -1, r = need;
    while (l < r - 1)
    {
        ll m = (l + r) / 2;
        if (f(m) < f(m + 1))
        {
            l = m;
        }
        else
        {
            r = m;
        }
    }
    printf("%lld\n", f(l + 1));
}