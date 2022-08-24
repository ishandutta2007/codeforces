
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

const int N = 1e6 + 7;

ll t[4 * N];
ll d[4 * N];
int last[N];

void push(int v, int l, int r)
{
    ll m = (l + r) / 2;
    t[v * 2 + 1] += (m - l) * d[v];
    t[v * 2 + 2] += (r - m) * d[v];
    d[v * 2 + 1] += d[v];
    d[v * 2 + 2] += d[v];
    d[v] = 0;
}

void upd(int v, int l, int r, int tl, int tr, ll x)
{
    if (tl >= r || tr <= l)
    {
        return;
    }
    if (tl >= l && tr <= r)
    {
        t[v] += x * (tr - tl);
        d[v] += x;
    }
    else
    {
        int tm = (tl + tr) / 2;
        push(v, tl, tr);
        upd(v * 2 + 1, l, r, tl, tm, x);
        upd(v * 2 + 2, l, r, tm, tr, x);
        t[v] = t[v * 2 + 1] + t[v * 2 + 2];
    }
}

int main()
{
#ifdef ONPC
    freopen("a.in", "r", stdin);
#endif
    int n;
    scanf("%d", &n);
    for (int i = 0; i < N; i++) last[i] = -1;
    ll sum = 0;
    ll t = 0;
    for (int i = 0; i < n; i++)
    {
        int x;
        scanf("%d", &x);
        if (last[x] != -1)
        {
            t -= last[x] + 1;
        }
        last[x] = i;
        t += last[x] + 1;
        sum += t;
    }
    sum -= n;
    sum *= 2;
    sum += n;
    ll res = n * (ll) n;
    cout << fixed << setprecision(20) << sum / (double) res << '\n';
}