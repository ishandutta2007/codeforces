#include <bits/stdc++.h>

using namespace std;

#define int int64_t

int n, k, a, b, q;

const int maxn = 3e5;
int sum[4 * maxn][2];

void add(int p, int x, int v = 1, int l = 0, int r = maxn)
{
    if(r - l == 1)
    {
        sum[v][0] = min(b, sum[v][0] + x);
        sum[v][1] = min(a, sum[v][1] + x);
        return;
    }
    int m = (l + r) / 2;
    if(p < m)
        add(p, x, 2 * v, l, m);
    else
        add(p, x, 2 * v + 1, m, r);
    sum[v][0] = sum[2 * v][0] + sum[2 * v + 1][0];
    sum[v][1] = sum[2 * v][1] + sum[2 * v + 1][1];
}

int get(int a, int b, int mod, int v = 1, int l = 0, int r = maxn)
{
    if(a <= l && r <= b)
        return sum[v][mod];
    if(r <= a || b <= l)
        return 0;
    int m = (l + r) / 2;
    return get(a, b, mod, 2 * v, l, m) + get(a, b, mod, 2 * v + 1, m, r);
}

signed main()
{
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k >> a >> b >> q;
    while(q--)
    {
        int t;
        cin >> t;
        if(t == 1)
        {
            int d, a;
            cin >> d >> a;
            add(d, a);
        }
        else
        {
            int p;
            cin >> p;
            cout << get(0, p, 0) + get(p + k, maxn, 1) << "\n";
        }
    }
}