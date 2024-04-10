#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5 + 42, mod = 1e9 + 7;
int val[4 * maxn][2];
int mul[4 * maxn][2][2];

inline void apply(int a[2][2], int b[2][2], int r[2][2])
{
    int c[2][2] = {0};
    for(int i = 0; i < 2; i++)
        for(int j = 0; j < 2; j++)
            for(int k = 0; k < 2; k++)
                c[i][j] += 1LL * a[i][k] * b[k][j] % mod;
    for(int i = 0; i < 2; i++)
        for(int j = 0; j < 2; j++)
            c[i][j] %= mod;
    memcpy(r, c, sizeof(c));
}

inline void apply(int a[2][2], int b[2], int r[2])
{
    int c[2] = {0};
    for(int i = 0; i < 2; i++)
        for(int k = 0; k < 2; k++)
            c[i] += 1LL * a[i][k] * b[k] % mod;
    for(int i = 0; i < 2; i++)
            c[i] %= mod;
    memcpy(r, c, sizeof(c));
}

void upd(int a, int b, int c[2][2], int v = 1, int l = 0, int r = maxn)
{
    if(a <= l && r <= b)
    {
        apply(c, mul[v], mul[v]);
        apply(c, val[v], val[v]);
        return;
    }
    if(r <= a || b <= l)
        return;
    int m = (l + r) / 2;
    upd(a, b, c, 2 * v, l, m);
    upd(a, b, c, 2 * v + 1, m, r);
    val[v][0] = val[2 * v][0] + val[2 * v + 1][0];
    val[v][1] = val[2 * v][1] + val[2 * v + 1][1];
    apply(mul[v], val[v], val[v]);
}

pair<int, int> get(int a, int b, int v = 1, int l = 0, int r = maxn)
{
    if(a <= l && r <= b)
        return {val[v][0], val[v][1]};
    if(r <= a || b <= l)
    return {0, 0};
    int m = (l + r) / 2;
    auto A = get(a, b, 2 * v, l, m);
    auto B = get(a, b, 2 * v + 1, m, r);
    int t[2] = {A.first + B.first, A.second + B.second};
    apply(mul[v], t, t);
    return {t[0], t[1]};
}

int E[2][2] = {{1, 0}, {0, 1}};

void bpow(int x[2][2], int n, int res[2][2])
{
    if(n == 0)
    {
        res[0][0] = res[1][1] = 1;
        res[0][1] = res[1][0] = 0;
        return;
    }
    bpow(x, n / 2, res);
    apply(res, res, res);
    if(n % 2 == 1)
        apply(res, x, res);
}

int F[2][2] = {{1, 1}, {1, 0}};

signed main()
{
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    for(int i = 0; i < 4 * maxn; i++)
    {
        memcpy(mul[i], E, sizeof(E));
        val[i][0] = 0;
        val[i][1] = 1;
    }
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        int t[2][2];
        bpow(F, a, t);
        upd(i, i + 1, t);
        auto gg = get(i, i + 1);
    }
    while(m--)
    {
        int t;
        cin >> t;
        if(t == 1)
        {
            int l, r, x;
            cin >> l >> r >> x;
            int t[2][2];
            bpow(F, x, t);
            upd(l - 1, r, t);
        }
        else
        {
            int l, r;
            cin >> l >> r;
            auto it = get(l - 1, r);
            cout << it.first << "\n";
        }
    }
    return 0;
}