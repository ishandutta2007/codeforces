#include <bits/stdc++.h>

using namespace std;

const int MAX_N = (1 << 18);
pair<int, int> d[16][2 * MAX_N];
int n, k;
int a[5];
const int inf = 1000 * 1000 * 1000;

void update(int e, int i, int x)
{
    d[e][i].first = x;
    d[e][i].second = x;
    i /= 2;
    while (i >= 1)
    {
        d[e][i].first = max(d[e][i * 2].first, d[e][i * 2 + 1].first);
        d[e][i].second = min(d[e][i * 2].second, d[e][i * 2 + 1].second);
        i /= 2;
    }
}

pair<int, int> get(int e, int i, int left, int right, int l, int r)
{
    if (left == l && right == r)
        return d[e][i];
    int m = (l + r) / 2;
    if (right <= m)
        return get(e, i * 2, left, right, l, m);
    if (left >= m)
        return get(e, i * 2 + 1, left, right, m, r);
    pair<int, int> u1 = get(e, i * 2, left, m, l, m);
    pair<int, int> u2 = get(e, i * 2 + 1, m, right, m, r);
    return make_pair(max(u1.first, u2.first), min(u1.second, u2.second));
}

signed main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        for (int e = 0; e < k; e++)
            cin >> a[e];
        for (int e = 0; e < (1 << (k - 1)); e++)
        {
            int u = e;
            int cur = 0;
            for (int j = 0; j < k - 1; j++)
            {
                if (u & 1)
                    cur += a[j];
                else
                    cur -= a[j];
                u /= 2;
            }
            cur += a[k - 1];
            //cur = abs(cur);
            d[e][MAX_N + i].first = cur;
            d[e][MAX_N + i].second = cur;
        }
    }
    for (int e = 0; e < (1 << (k - 1)); e++)
    {
        for (int i = n; i < MAX_N; i++)
        {
            d[e][i + MAX_N].first = -inf;
            d[e][i + MAX_N].second = inf;
        }
    }
    for (int e = 0; e < (1 << (k - 1)); e++)
    {
        for (int i = MAX_N - 1; i >= 1; i--)
        {
            d[e][i].first = max(d[e][i * 2].first, d[e][i * 2 + 1].first);
            d[e][i].second = min(d[e][i * 2].second, d[e][i * 2 + 1].second);
        }
    }
    int q;
    cin >> q;
    for (int j = 0; j < q; j++)
    {
        int t;
        cin >> t;
        if (t == 1)
        {
            int id;
            cin >> id;
            id--;
            for (int i = 0; i < k; i++)
                cin >> a[i];
            for (int e = 0; e < (1 << (k - 1)); e++)
            {
                int u = e;
                int cur = 0;
                for (int j = 0; j < k - 1; j++)
                {
                    if (u & 1)
                        cur += a[j];
                    else
                        cur -= a[j];
                    u /= 2;
                }
                cur += a[k - 1];
                //cur = abs(cur);
                update(e, MAX_N + id, cur);
            }
        }
        else
        {
            int l, r;
            cin >> l >> r;
            l--;
            int ans = 0;
            for (int e = 0; e < (1 << (k - 1)); e++)
            {
                pair<int, int> cur = get(e, 1, l, r, 0, MAX_N);
                ans = max(ans, cur.first - cur.second);
            }
            cout << ans << "\n";
        }
    }
}