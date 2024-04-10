#include <bits/stdc++.h>

using namespace std;

#define int long long

const int MAXN = (1 << 17);

pair<bool, int> d[2 * MAXN];
int sum[2 * MAXN];
int ma[2 * MAXN];
int k[MAXN];
int pref_k[MAXN];
int n;
int inf = 1ll * 1000 * 1000 * 1000  * 1000 * 1000 * 1000;

void push(int i, int len)
{
    if (!d[i].first)
        return;
    d[i * 2].first = true;
    d[i * 2].second = d[i].second;
    ma[i * 2] = d[i].second;
    sum[i * 2] = d[i].second * len;
    d[i * 2 + 1].first = true;
    d[i * 2 + 1].second = d[i].second;
    ma[i * 2 + 1] = d[i].second;
    sum[i * 2 + 1] = d[i].second * len;
    d[i].first = false;
}

int find_elem(int i, int l, int r, int x)
{
    if (l == r - 1)
        return sum[i];
    push(i, (r - l) / 2);
    int m = (r + l) / 2;
    if (x < m)
        return find_elem(i * 2, l, m, x);
    return find_elem(i * 2 + 1, m, r, x);
}

int find_first_greater(int i, int l, int r, int left, int right, int x)
{
    if (ma[i] < x)
        return -1;
    if (l == r - 1)
        return l;
    push(i, (r - l) / 2);
    int m = (l + r) / 2;
    if (right <= m)
        return find_first_greater(i * 2, l, m, left, right, x);
    if (left >= m)
        return find_first_greater(i * 2 + 1, m, r, left, right, x);
    int cur = find_first_greater(i * 2, l, m, left, m, x);
    if (cur != -1)
        return cur;
    return find_first_greater(i * 2 + 1, m, r, m, right, x);
}

void update(int i, int l, int r, int left, int right, int x)
{
    if (l == left && r == right)
    {
        d[i].first = true;
        d[i].second = x;
        ma[i] = x;
        sum[i] = x * (r - l);
        return;
    }
    push(i, (r - l) / 2);
    int m = (l + r) / 2;
    if (right <= m)
        update(i * 2, l, m, left, right, x);
    else if (left >= m)
        update(i * 2 + 1, m, r, left, right, x);
    else
    {
        update(i * 2, l, m, left, m, x);
        update(i * 2 + 1, m, r, m, right, x);
    }
    ma[i] = max(ma[i * 2], ma[i * 2 + 1]);
    sum[i] = sum[i * 2] + sum[i * 2 + 1];
}

int get_sum(int i, int l, int r, int left, int right)
{
    if (l == left && r == right)
        return sum[i];
    push(i, (r - l) / 2);
    int m = (l + r) / 2;
    if (right <= m)
        return get_sum(i * 2, l, m, left, right);
    if (left >= m)
        return get_sum(i * 2 + 1, m, r, left, right);
    return get_sum(i * 2, l, m, left, m) + get_sum(i * 2 + 1, m, r, m, right);
}

signed main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> ma[MAXN + i];
    for (int i = 1; i < n; i++)
    {
        cin >> k[i];
        k[i] += k[i - 1];
        pref_k[i] = pref_k[i - 1] + k[i];
        ma[MAXN + i] -= k[i];
        sum[MAXN + i] = ma[MAXN + i];
    }
    sum[MAXN] = ma[MAXN];
    for (int i = MAXN + n; i < 2 * MAXN; i++)
        ma[i] = -inf;
    for (int i = MAXN - 1; i >= 1; i--)
    {
        ma[i] = max(ma[i * 2], ma[i * 2 + 1]);
        sum[i] = sum[i * 2] + sum[i * 2 + 1];
    }
    int q;
    cin >> q;
    for (int j = 0; j < q; j++)
    {
        char s;
        cin >> s;
        if (s == '+')
        {
            int i, x;
            cin >> i >> x;
            i--;
            int cur = find_elem(1, 0, MAXN, i) + x;
            int pos = find_first_greater(1, 0, MAXN, i + 1, n, cur);
            if (pos == -1)
                pos = n;
            update(1, 0, MAXN, i, pos, cur);
        }
        else
        {
            int l, r;
            cin >> l >> r;
            l--;
            cout << get_sum(1, 0, MAXN, l, r) + pref_k[r - 1] - (l > 0 ? pref_k[l - 1] : 0) << "\n";
        }
    }
}