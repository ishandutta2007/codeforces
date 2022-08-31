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

const int N = 5e5 + 7;

int t[4 * N];
int a[N];

int gcd(int a, int b)
{
    if (!min(a, b)) return max(a, b);
    return __gcd(a, b);
}

void build(int v, int l, int r)
{
    if (r - l == 1)
    {
        t[v] = a[l];
    }
    else
    {
        int m = (l + r) / 2;
        build(v * 2 + 1, l, m);
        build(v * 2 + 2, m, r);
        t[v] = gcd(t[v * 2 + 1], t[v * 2 + 2]);
    }
}

void upd(int v, int l, int r, int i, int x)
{
    if (r - l == 1)
    {
        t[v] = a[i] = x;
    }
    else
    {
        int m = (l + r) / 2;
        if (i < m)
        {
            upd(v * 2 + 1, l, m, i, x);
        }
        else
        {
            upd(v * 2 + 2, m, r, i, x);
        }
        t[v] = gcd(t[v * 2 + 1], t[v * 2 + 2]);
    }
}

int find(int v, int l, int r, int tl, int tr, int x)
{
    if (tl >= r || tr <= l || t[v] % x == 0)
    {
        return -1;
    }
    if (tr - tl == 1)
    {
        return tl;
    }
    else
    {
        int tm = (tl + tr) / 2;
        int a = find(v * 2 + 1, l, r, tl, tm, x);
        if (a != -1) return a;
        return find(v * 2 + 2, l, r, tm, tr, x);
    }
}

int get(int v, int l, int r, int tl, int tr)
{
    if (tl >= r || tr <= l)
    {
        return 0;
    }
    if (tl >= l && tr <= r)
    {
        return t[v];
    }
    else
    {
        int tm = (tl + tr) / 2;
        return gcd(get(v * 2 + 1, l, r, tl, tm), get(v * 2 + 2, l, r, tm, tr));
    }
}

int main()
{
#ifdef ONPC
    freopen("a.in", "r", stdin);
#endif
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    build(0, 0, n);
    int q;
    scanf("%d", &q);
    while (q--)
    {
        int t;
        scanf("%d", &t);
        if (t == 1)
        {
            int l, r, x;
            scanf("%d%d%d", &l, &r, &x);
            l--, r--;
            int g = get(0, l, r + 1, 0, n);
            if (g % x == 0)
            {
                puts("YES");
            }
            else
            {
                int p = find(0, l, r + 1, 0, n, x);
                if (p == r)
                {
                    puts("YES");
                }
                else
                {
                    int g = get(0, p + 1, r + 1, 0, n);
                    if (g % x == 0)
                    {
                        puts("YES");
                    }
                    else
                    {
                        puts("NO");
                    }
                }
            }
        }
        else
        {
            int i, x;
            scanf("%d%d", &i, &x);
            i--;
            upd(0, 0, n, i, x);
        }
    }
}