#include <bits/stdc++.h>

using namespace std;

#define int long long

const int MAX_N = (1 << 19);
int mask[2 * MAX_N];
int mask1[2 * MAX_N];
int d[2 * MAX_N];
int ps[2 * MAX_N];
int mod = 1000 * 1000 * 1000 + 7;
int n, q;
int pr[65];
int cnt;
bool prime[309];
int k[65];

int binpow(int a, int pw)
{
    if (pw == 1)
        return a;
    int b = binpow(a, pw / 2);
    b = (b * b) % mod;
    if (pw % 2 == 1)
        b = (b * a) % mod;
    return b;
}

int divide(int a, int b)
{
    int c = binpow(b, mod - 2) * a;
    return c % mod;
}

void push(int i, int len)
{
    d[i] = (d[i] * binpow(ps[i], len)) % mod;
    ps[i * 2] = (ps[i * 2] * ps[i]) % mod;
    ps[i * 2 + 1] = (ps[i * 2 + 1] * ps[i]) % mod;
    ps[i] = 1;
}

void add(int i, int l, int r, int left, int right, int x)
{
    if (l == left && r == right)
    {
        ps[i] = (ps[i] * x) % mod;
        return;
    }
    //push(i, r - l);
    int m = (l + r) / 2;
    if (right <= m)
        add(i * 2, l, m, left, right, x);
    else if (left >= m)
        add(i * 2 + 1, m, r, left, right, x);
    else
    {
        add(i * 2, l, m, left, m, x);
        add(i * 2 + 1, m, r, m, right, x);
    }
    d[i] = (d[i * 2] * binpow(ps[i * 2], m - l)) % mod;
    d[i] = (d[i] * d[i * 2 + 1]) % mod;
    d[i] = (d[i] * binpow(ps[i * 2 + 1], r - m)) % mod;
}

int get(int i, int l, int r, int left, int right)
{
    if (l == left && r == right)
        return (d[i] * binpow(ps[i], r - l)) % mod;
    push(i, r - l);
    int m = (l + r) / 2;
    if (right <= m)
        return get(i * 2, l, m, left, right);
    if (left >= m)
        return get(i * 2 + 1, m, r, left, right);
    return (get(i * 2, l, m, left, m) * get(i * 2 + 1, m, r, m, right)) % mod;
}

void update(int i, int l, int r, int left, int right, int y)
{
    if (l == left && r == right)
    {
        mask1[i] |= y;
        return;
    }
    int m = (l + r) / 2;
    if (right <= m)
        update(i * 2, l, m, left, right, y);
    else if (left >= m)
        update(i * 2 + 1, m, r, left, right, y);
    else
    {
        update(i * 2, l, m, left, m, y);
        update(i * 2 + 1, m, r, m, right, y);
    }
    mask[i] = (mask[i * 2] | mask[i * 2 + 1] | mask1[i * 2] | mask1[i * 2 + 1]);
}

void push1(int i)
{
    mask[i] |= mask1[i];
    mask1[i * 2] |= mask1[i];
    mask1[i * 2 + 1] |= mask1[i];
    mask1[i] = 0;
}

int check(int i, int l, int r, int left, int right)
{
    if (l == left && r == right)
        return (mask[i] | mask1[i]);
    push1(i);
    int m = (l + r) / 2;
    if (right <= m)
        return check(i * 2, l, m, left, right);
    if (left >= m)
        return check(i * 2 + 1, m, r, left, right);
    return (check(i * 2, l, m, left, m) | check(i * 2 + 1, m, r, m, right));
}

signed main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    for (int i = 2; i <= 300; i++)
        prime[i] = true;
    for (int i = 2; i <= 300; i++)
    {
        if (prime[i])
        {
            pr[cnt] = i;
            k[cnt] = divide(i - 1, i);
            cnt++;
            for (int e = i + i; e <= 300; e += i)
                prime[e] = false;
        }
    }
    cin >> n >> q;
    for (int i = 0; i < n; i++)
        cin >> d[MAX_N + i];
    for (int i = MAX_N + n; i < 2 * MAX_N; i++)
        d[i] = 1;
    for (int i = MAX_N - 1; i >= 1; i--)
        d[i] = (d[i * 2] * d[i * 2 + 1]) % mod;
    for (int i = 1; i < 2 * MAX_N; i++)
        ps[i] = 1;
    for (int i = MAX_N; i < MAX_N + n; i++)
    {
        for (int e = 0; e < cnt; e++)
        {
            if (d[i] % pr[e] == 0)
                mask[i] |= (1ll << e);
        }
    }
    for (int i = MAX_N - 1; i >= 1; i--)
        mask[i] = (mask[i * 2] | mask[i * 2 + 1]);
    for (int j = 0; j < q; j++)
    {
        string s;
        int l, r;
        cin >> s >> l >> r;
        l--;
        if (s[0] == 'M')
        {
            int x;
            cin >> x;
            add(1, 0, MAX_N, l, r, x);
            int y = 0;
            for (int e = 0; e < cnt; e++)
            {
                if (x % pr[e] == 0)
                    y |= (1ll << e);
            }
            update(1, 0, MAX_N, l, r, y);
        }
        else
        {
            int ans = get(1, 0, MAX_N, l, r);
            int y = check(1, 0, MAX_N, l, r);
            for (int e = 0; e < cnt; e++)
            {
                if (y & (1ll << e))
                    ans = (ans * k[e]) % mod;
            }
            cout << ans << "\n";
        }
    }
}