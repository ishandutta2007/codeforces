#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define ld long double
#define pii pair<int,int>
#define pll pair<ll,ll>
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define all(vr) vr.begin(), vr.end()
#define vi vector<int>
#define vll vector<ll>
const int N = 2e4 + 10, lgn = 14, K = 30;

struct RMQ
{
    int spr[20][N], lg[N], val[N];

    int Min(int x, int y) { return val[x] < val[y] ? y : x;}

    void build(int a[], int n)
    {
        for (int i = 1; i <= n; ++i)
        {
            spr[0][i] = i;
            val[i] = a[i] + i;
            int x = i;
            while (x > 1) lg[i]++, x >>= 1;
        }
        for (int i = 1; i <= lg[n]; ++i)
            for (int j = 1; j <= n - (1 << i) + 1; ++j)
                spr[i][j] = Min(spr[i - 1][j], spr[i - 1][j + (1 << (i - 1))]);
    }

    int rmq(int l, int r)
    {
        int k = lg[r - l + 1];
        return Min(spr[k][l], spr[k][r - (1 << k) + 1]);
    }
} tab;

int a[N], n, q;
vi jump[N][15];

vi nxt(vi &vt, int sta, int l, int k)
{
    vi res(k + 1, 0);
    for (int i = 0; i <= k; ++i)
    {
        int pos = tab.rmq(sta, vt[i]);
        for (int j = 0; j <= k - i; ++j)
            res[i + j] = max(res[i + j], jump[pos][l][j]);
    }
    return res;
}

int main()
{
    //freopen("ss.inp", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> q;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    tab.build(a, n);
    for (int i = 1; i <= n; ++i)
    {
        jump[i][0].resize(K + 1);
        for (int j = 0; j <= K; ++j) jump[i][0][j] = min(n, a[i] + i + j);
    }
    for (int l = 1; l <= lgn; ++l)
        for (int i = 1; i <= n; ++i) jump[i][l] = nxt(jump[i][l - 1], i, l - 1, K);
    for (int i = 1, l, r, k; i <= q; ++i)
    {
        cin >> l >> r >> k;
        if (l == r)
        {
            cout << "0\n";
            continue;
        }
        vi vt(k + 1, l);
        int res = 0;
        for (int j = lgn; j >= 0; --j)
        {
            vi tmp = nxt(vt, l, j, k);
            if (tmp.back() < r) vt = tmp, res |= (1 << j);
        }
        cout << res + 1 << "\n";
    }
    return 0;
}