#include <bits/stdc++.h>

using namespace std;

#define int long long

const int MAX_N = (1 << 18);
int mod = 998244353;
int a[MAX_N];
bool used[MAX_N];
int n, k;
int d[2 * MAX_N];
int p = 1;
int q = 1;

void add_elem(int v)
{
    while (v > 0)
    {
        d[v]++;
        v /= 2;
    }
}

int get_sum(int v, int l, int r, int left, int right)
{
    if (l == left && r == right)
        return d[v];
    int m = (l + r) / 2;
    if (right <= m)
        return get_sum(v * 2, l, m, left, right);
    if (left >= m)
        return get_sum(v * 2 + 1, m, r, left, right);
    return get_sum(v * 2, l, m, left, m) + get_sum(v * 2 + 1, m, r, m, right);
}

int fast_pow(int b, int x)
{
    if (x == 0)
        return 1;
    if (x == 1)
        return b;
    int ans = fast_pow(b, x / 2);
    ans = (ans * ans) % mod;
    if (x % 2 == 0)
        return ans;
    return (ans * b) % mod;
}

signed main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        if (a[i] == -1)
            k++;
        else
            used[a[i]] = true;
    }
    if (k <= 1)
    {
        if (k == 1)
        {
            int u;
            for (int i = 1; i <= n; i++)
            {
                if (!used[i])
                    u = i;
            }
            for (int i = 0; i < n; i++)
            {
                if (a[i] == -1)
                    a[i] = u;
            }
        }
        p = 0;
        for (int i = 0; i < n; i++)
        {
            int cur = get_sum(1, 0, MAX_N, a[i] + 1, MAX_N);
            p = (p + cur) % mod;
            add_elem(MAX_N + a[i]);
        }
        cout << p;
        return 0;
    }
    for (int i = 1; i <= k; i++)
        p = (p * i) % mod;
    p = (p * k) % mod;
    p = (p * (k - 1)) % mod;
    if (p % 2 == 1)
        p += mod;
    p /= 2;
    p %= mod;
    if (p % 2 == 1)
        p += mod;
    p /= 2;
    p %= mod;
    int p1 = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] == -1)
            continue;
        int cur = get_sum(1, 0, MAX_N, a[i] + 1, MAX_N);
        p1 = (p1 + cur) % mod;
        add_elem(MAX_N + a[i]);
    }
    int f = 1;
    for (int i = 1; i <= k; i++)
        f = (f * i) % mod;
    p = (p + p1 * f) % mod;
    for (int i = MAX_N; i < 2 * MAX_N; i++)
        d[i] = 0;
    for (int i = 1; i <= n; i++)
        d[i + MAX_N] = (used[i] ^ 1);
    for (int i = MAX_N - 1; i >= 1; i--)
        d[i] = d[i * 2] + d[i * 2 + 1];
    int cur = 0;
    int y = 1;
    for (int i = 1; i <= k - 1; i++)
        y = (y * i) % mod;
    int x = k;
    for (int i = 0; i < n; i++)
    {
        if (a[i] == -1)
        {
            x--;
            continue;
        }
        int u1 = get_sum(1, 0, MAX_N, 0, a[i]);
        int u2 = get_sum(1, 0, MAX_N, a[i] + 1, MAX_N);
        int e = (x * y) % mod;
        p = (p + e * u1) % mod;
        e = ((k - x) * y) % mod;
        p = (p + e * u2) % mod;
    }
    int q = f;
    //cout << fast_pow(3, 3) << endl;
    int ans = (fast_pow(q, mod - 2) * p) % mod;
    cout << ans;
}