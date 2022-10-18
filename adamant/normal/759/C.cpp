#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5 + 42;

int val[4 * maxn], mx[4 * maxn], sm[4 * maxn];

void upd(int p, int t, int x, int v = 1, int l = 0, int r = maxn)
{
    if(r - l == 1)
    {
        val[v] = x;
        sm[v] = mx[v] = (t == 0 ? -1 : 1);
        return;
    }
    int m = (l + r) / 2;
    if(p < m)
        upd(p, t, x, 2 * v, l, m);
    else
        upd(p, t, x, 2 * v + 1, m, r);
    sm[v] = sm[2 * v] + sm[2 * v + 1];
    mx[v] = max(mx[2 * v + 1], mx[2 * v] + sm[2 * v + 1]);
}

int get(int v = 1, int l = 0, int r = maxn, int suf = 0)
{
    if(r - l == 1)
        return (l > 0 ? val[v] : -1);
    int m = (l + r) / 2;
    if(mx[2 * v + 1] + suf > 0)
        return get(2 * v + 1, m, r, suf);
    else
        return get(2 * v, l, m, suf + sm[2 * v + 1]);
}

signed main()
{
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        int p, t;
        cin >> p >> t;
        if(t == 0)
        {
            upd(p, t, 0);
        }
        else
        {
            int x;
            cin >> x;
            upd(p, t, x);
        }
        cout << get() << "\n";
    }
    return 0;
}