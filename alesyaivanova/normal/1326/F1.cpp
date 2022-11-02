#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ff first
#define ss second
#define pii pair<int, int>
#define pb emplace_back
#define pf emplace_front
#define mp make_pair
#define ld long double
#define all(x) x.begin(), x.end()
#define uniq(x) sort(all(x)), x.resize(unique(all(x)) - x.begin())

const int maxn = 14;
bool g[maxn][maxn];
int dp[2][3500][1 << 7][14];
int num[1 << 14];
vector<int> all_masks;
int n;
ll ans[1 << 14];

void gen0(int lst, int sz, vector<bool>& used, int len, int mask1, int mask)
{
    if (sz == len)
    {
        dp[0][num[mask]][mask1][lst]++;
        return;
    }
    for (int e = 0; e < n; e++)
    {
        if (!used[e])
        {
            int mask2 = 0;
            if (sz)
                mask2 = (mask1 | (g[lst][e] << (sz - 1)));
            used[e] = 1;
//            cur.pb(e);
            mask ^= (1 << e);
            gen0(e, sz + 1, used, len, mask2, mask);
            used[e] = 0;
//            cur.pop_back();
            mask ^= (1 << e);
        }
    }
}

void gen1(int st, int lst, int sz, vector<bool>& used, int len, int mask1, int mask)
{
    if (sz == len)
    {
        for (int e = 0; e < n; e++)
        {
            if (used[e])
                continue;
            dp[1][num[mask]][mask1 | g[e][st]][e]++;
        }
        return;
    }
    for (int e = 0; e < n; e++)
    {
        if (!used[e])
        {
            int mask2 = 0;
            if (sz)
                mask2 = (mask1 | (g[lst][e] << sz));
            used[e] = 1;
//            cur.pb(e);
            mask ^= (1 << e);
            gen1((sz ? st : e), e, sz + 1, used, len, mask2, mask);
            used[e] = 0;
//            cur.pop_back();
            mask ^= (1 << e);
        }
    }
}

void prec_num(vector<int>& cur, int len, int& pt)
{
    if ((int)cur.size() == len)
    {
        int mask = 0;
        for (int e : cur)
            mask |= (1 << e);
        num[mask] = pt;
        pt++;
        all_masks.pb(mask);
        return;
    }
    for (int e = (cur.empty() ? 0 : cur.back() + 1); e < n; e++)
    {
        cur.pb(e);
        prec_num(cur, len, pt);
        cur.pop_back();
    }
}

signed main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        for (int e = 0; e < n; e++)
            g[i][e] = (s[e] == '1');
    }
    int len = n / 2;
    vector<int> cur;
    vector<bool> used(n, 0);
    int pt = 0;
    prec_num(cur, len, pt);
    gen0(0, 0, used, len, 0, 0);
    gen1(0, 0, 0, used, n - len, 0, (1 << n) - 1);
    len--;
    for (int i = 0; i < pt; i++)
    {
        vector<int> kek;
        for (int e = 0; e < 14; e++)
        {
            if (all_masks[i] & (1 << e))
                kek.pb(e);
        }
        for (int mask = 0; mask < (1 << (n - 1)); mask++)
        {
            for (int e : kek)
                ans[mask] += dp[0][i][mask % (1 << len)][e] * 1ll * dp[1][i][mask / (1 << len)][e];
        }
    }
    for (int i = 0; i < (1 << (n - 1)); i++)
        cout << ans[i] << " ";
}