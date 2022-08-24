
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

const int N = 2e6 + 7;

int arr[N];
ll sum[N];

int get(int l, int r)
{
    if (l > r) return 0;
    if (!l) return arr[r];
    else return arr[r] - arr[l - 1];
}

ll get_sum(int l, int r)
{
    if (!l) return sum[r];
    else return sum[r] - sum[l - 1];
}

int main()
{
#ifdef ONPC
    freopen("a.in", "r", stdin);
#endif
    int n, x, y;
    scanf("%d%d%d", &n, &x, &y);
    int cur = x / y;
    for (int i = 0; i < n; i++)
    {
        int p;
        scanf("%d", &p);
        arr[p]++;
        sum[p] += p;
    }
    for (int i = 1; i < N; i++) arr[i] += arr[i - 1], sum[i] += sum[i - 1];
    ll ans = 1e18;
    for (int i = 2; i < N; i++)
    {
        ll ok = 0;
        for (int j = i; j < N; j += i)
        {
            int l = max(0, max(j - i + 1, j - cur));
            int r = j;
            //j - cur .. j -> ok
            //j .. j - cur -> not ok
            int real_l = max(0, j - i + 1);
            ok += get(real_l, l - 1) * (ll) x;
            ok += (j * (ll) get(l, r) - get_sum(l, r)) * (ll) y;
        }
        ans = min(ans, ok);
    }
    printf("%lld\n", ans);
}