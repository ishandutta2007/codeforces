

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

const int N = 1e6 + 7;

int cnt[N];
int a[N];
ll s[4 * N];
int mx[4 * N];

void upd(int v, int l, int r, int i, int x)
{
    if (r - l == 1)
    {
        s[v] = x;
        mx[v] = x;
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
        s[v] = s[v * 2 + 1] + s[v * 2 + 2];
        mx[v] = max(mx[v * 2 + 1], mx[v * 2 + 2]);
    }
}

vector <int> kek;

void find(int v, int l, int r, int tl, int tr)
{
    if (tl >= r || tr <= l || mx[v] <= 2)
    {
        return;
    }
    if (tl + 1 == tr)
    {
        kek.push_back(tl);
    }
    else
    {
        int tm = (tl + tr) / 2;
        find(v * 2 + 1, l, r, tl, tm);
        find(v * 2 + 2, l, r, tm, tr);
    }
}

ll get(int v, int l, int r, int tl, int tr)
{
    if (tl >= r || tr <= l)
    {
        return 0;
    }
    if (tl >= l && tr <= r)
    {
        return s[v];
    }
    else
    {
        int tm = (tl + tr) / 2;
        return get(v * 2 + 1, l, r, tl, tm) + get(v * 2 + 2, l, r, tm, tr);
    }
}

int main()
{
#ifdef ONPC
    freopen("a.in", "r", stdin);
#endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    for (int i = 1; i < N; i++)
    {
        for (int j = i; j < N; j += i)
        {
            cnt[j]++;
        }
    }
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        upd(0, 0, n, i, a[i]);
    }
    for (int i = 0; i < m; i++)
    {
        int t;
        cin >> t;
        if (t == 1)
        {
            kek.clear();
            int l, r;
            cin >> l >> r;
            l--, r--;
            find(0, l, r + 1, 0, n);
            for (int v : kek)
            {
                a[v] = cnt[a[v]];
                upd(0, 0, n, v, a[v]);
            }
        }
        else
        {
            int l, r;
            cin >> l >> r;
            l--, r--;
            cout << get(0, l, r + 1, 0, n) << '\n';
        }
    }
}