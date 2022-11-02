#include <bits/stdc++.h>

using namespace std;

//#define int long long
#define pb emplace_back
#define pii pair<int, int>
#define mp make_pair
#define ff first
#define ss second
#define ld long double
#define matr vector<vector<int> >
#define all(x) x.begin(), x.end()
#define uniq(x) sort(all(x)), x.resize(unique(all(x)) - x.begin())

const int maxn = 1e5 + 9;
int n, m;
vector<pii> g[maxn];
int used[maxn];
int col[maxn];
const int magic = 243;
int dp[maxn][400];
int mod = 1e9 + 7;
int x[maxn];
vector<int> ruba[maxn];
int pos[maxn];
int mask_on_pos[maxn];
int sz;
int opt_mask[maxn];
int go[400][400];

void find_col(int v, int C)
{
    used[v] = 1;
    col[v] = C;
    for (pii to : g[v])
    {
        if (to.ff && !used[to.ff])
            find_col(to.ff, C);
    }
}

void dfs(int v, int c, vector<int>& cur, int kek, int t, int pr)
{
    used[v] = 2 * t + 1;
    x[v] = kek;
    for (pii to : g[v])
    {
        if (to.ff == pr || (to.ff && col[to.ff] != c))
            continue;
        if (!to.ff && t)
            continue;
        if (used[to.ff] == 2 * t + 1)
            cur.pb(x[v] ^ to.ss ^ x[to.ff]);
        else if (used[to.ff] == 2 * t)
            dfs(to.ff, c, cur, kek ^ to.ss, t, v);
    }
    used[v] = 2 * t + 2;
}

void update_b(vector<int>& q)
{
    for (int j = 4; j >= 0; j--)
    {
        if (q[j] == -1)
            continue;
        for (int e = j - 1; e >= 0; e--)
        {
            if ((q[j] & (1 << e)) && q[e] != -1)
                q[j] ^= q[e];
        }
    }
}

void make_vector(int e, vector<int>& cur)
{
    for (int len = 1; len <= 5; len++)
    {
        int t = e % (1 << len);
        e /= (1 << len);
        if (t)
            cur.pb(t);
    }
    reverse(all(cur));
}

int make_mask(vector<int>& cur)
{
    int mask = 0;
    int j = 0;
    for (int len = 5; len >= 1; len--)
    {
        mask = (mask << len);
        if (j < (int)cur.size() && cur[j] >= (1 << (len - 1)))
        {
            mask += cur[j];
            j++;
        }
    }
    return mask;
}

int find_b(vector<int>& cur, bool w = 0)
{
    if ((int)cur.size() > 5)
        return -1;
    vector<int> q(5, -1);
    for (int e : cur)
    {
        for (int j = 4; j >= 0; j--)
        {
            if (e & (1 << j))
            {
                if (q[j] == -1)
                {
                    q[j] = e;
                    break;
                }
                else
                    e ^= q[j];
            }
            if (j == 0)
                return -1;
        }
    }
    if (w)
        update_b(q);
    cur.resize(0);
    for (int j = 4; j >= 0; j--)
    {
        if (q[j] != -1)
            cur.pb(q[j]);
    }
    return make_mask(cur);
}

void prec()
{
    for (int mask = 0; mask < (1 << 15); mask++)
    {
        vector<int> e;
        make_vector(mask, e);
        int y = find_b(e, 1);
        if (y == -1)
        {
            opt_mask[mask] = -1;
            continue;
        }
        opt_mask[mask] = y;
        if (mask == y)
        {
            pos[mask] = sz;
            mask_on_pos[sz] = mask;
            sz++;
        }
    }
    for (int i = 0; i < sz; i++)
    {
        int m1 = mask_on_pos[i];
        for (int e = 0; e < sz; e++)
        {
            int m2 = mask_on_pos[e];
            vector<int> w;
            make_vector(m1, w);
            make_vector(m2, w);
            int y = find_b(w);
            if (y == -1)
                go[i][e] = -1;
            else
                go[i][e] = pos[opt_mask[y]];
        }
    }
}

void update_dp(int m2, int j, int C)
{
    m2 = pos[opt_mask[m2]];
    for (int m1 = 0; m1 < sz; m1++)
    {
        int m3 = go[m1][m2];
        if (m3 == -1)
            continue;
        dp[j + 1][m3] = (dp[j + 1][m3] + C * 1ll * dp[j][m1]) % mod;
    }
}

signed main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif // LOCAL
    prec();
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int a, b, w;
        cin >> a >> b >> w;
        a--, b--;
        g[a].pb(b, w);
        g[b].pb(a, w);
    }
    int kek = 0;
    for (int i = 1; i < n; i++)
    {
        if (!used[i])
        {
            find_col(i, kek);
            kek++;
        }
    }
    for (int v = 1; v < n; v++)
    {
        for (pii to : g[v])
        {
            if (!to.ff)
            {
                ruba[col[v]].pb(v);
                x[v] = to.ss;
            }
        }
    }
    for (int i = 0; i < n; i++)
        used[i] = 0;
    kek = 0;
    vector<int> w;
    dp[0][0] = 1;
    for (int i = 1; i < n; i++)
    {
        if (!used[i])
        {
            for (int e = 0; e < sz; e++)
                dp[kek + 1][e] = dp[kek][e];
            vector<int> cur;
            used[0] = 1;
            int v = ruba[col[i]][0];
            dfs(v, col[i], cur, x[v], 0, 0);
            int y = find_b(cur);
            if (y != -1)
                update_dp(y, kek, 1);
            if (ruba[col[i]].size() >= 2)
            {
                cur.resize(0);
                used[0] = 3;
                dfs(v, col[i], cur, x[v], 1, 0);
                y = find_b(cur);
                if (y != -1)
                    update_dp(y, kek, 2);
            }
            kek++;
        }
    }
    int ans = 0;
    for (int i = 0; i < sz; i++)
        ans = (ans + dp[kek][i]) % mod;
    cout << ans;
}