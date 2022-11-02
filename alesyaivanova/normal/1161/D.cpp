#include <bits/stdc++.h>

using namespace std;

#define int long long
#define ff first
#define ss second
#define pb emplace_back
#define pii pair<long long, long long>

const int MAXN = 2009;
vector<pii> c[MAXN];
int mod = 998244353;
bool used[2][MAXN];
int a[MAXN];
int m;
int col[2][MAXN];

void dfs(int t, int i, int cnt, int len)
{
    used[t][i] = true;
    c[cnt].pb(i, t);
    if (a[i] != -1 && !used[1 - t][i])
        dfs(1 - t, i, cnt, len);
    if (t == 0 && !used[0][m - 1 - i])
        dfs(0, m - i - 1, cnt, len);
    if (t == 1 && i < len && !used[1][len - 1 - i])
        dfs(1, len - i - 1, cnt, len);
}

bool check(int i, int t, int cur_col, int len)
{
    used[t][i] = true;
    col[t][i] = cur_col;
    if (a[i] != -1)
    {
        if (used[1 - t][i] && (col[0][i] ^ col[1][i]) != a[i])
            return false;
        if (!used[1 - t][i] && !check(i, 1 - t, cur_col ^ a[i], len))
            return false;
    }
    if (t == 0)
    {
        if (used[0][m - 1 - i] && col[0][i] != col[0][m - 1 - i])
            return false;
        if (!used[0][m - 1 - i] && !check(m - 1 - i, 0, cur_col, len))
            return false;
    }
    if (t == 1 && i < len)
    {
        if (used[1][len - 1 - i] && col[1][i] != col[1][len - 1 - i])
            return false;
        if (!used[1][len - 1 - i] && !check(len - 1 - i, 1, cur_col, len))
            return false;
    }
    if (t == 1 && i >= len && col[1][i] == 1)
        return false;
    if (t == 1 && i == len - 1 && col[1][i] == 0)
        return false;
    //cout << "  " << i << " " << t << " " << col[t][i] << "\n";
    return true;
}

signed main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    string s;
    cin >> s;
    m = s.length();
    for (int i = 0; i < m; i++)
    {
        if (s[m - 1 - i] == '?')
            a[i] = -1;
        else
            a[i] = s[m - 1 - i] - '0';
    }
    int ans = 0;
    for (int len = 1; len < m; len++)
    {
        for (int i = 0; i < MAXN; i++)
        {
            c[i].resize(0);
            c[i].shrink_to_fit();
        }
        for (int i = 0; i < m; i++)
        {
            used[0][i] = false;
            used[1][i] = false;
        }
        int cnt = 0;
        for (int i = 0; i < m; i++)
        {
            if (!used[0][i])
            {
                dfs(0, i, cnt, len);
                cnt++;
            }
            if (!used[1][i])
            {
                dfs(1, i, cnt, len);
                cnt++;
            }
        }
        int cur = 1;
        for (int j = 0; j < cnt; j++)
        {
            /*for (auto e : c[j])
                cout << e.ff << " " << e.ss << "   ";
            cout << "\n";*/
            int y = 0;
            for (auto e : c[j])
                used[e.ss][e.ff] = false;
            if (check(c[j][0].ff, c[j][0].ss, 0, len))
                y++;

            for (auto e : c[j])
                used[e.ss][e.ff] = false;
            if (check(c[j][0].ff, c[j][0].ss, 1, len))
                y++;
            //cout << y << "\n";
            cur = (cur * y) % mod;
        }
        //cout << "\n";
        //cout << " " << len << " " << cur << "\n";
        ans = (ans + cur) % mod;
    }
    cout << ans;
}