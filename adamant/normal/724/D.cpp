#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5 + 42;

int mn[4 * maxn];
const int inf = 1e9;

void upd(int p, int c, int v = 1, int l = 0, int r = maxn)
{
    if(r - l == 1)
    {
        mn[v] = c;
        return;
    }
    int m = (l + r) / 2;
    if(p < m)
        upd(p, c, 2 * v, l, m);
    else
        upd(p, c, 2 * v + 1, m, r);
    mn[v] = min(mn[2 * v], mn[2 * v + 1]);
}

int get(int a, int b, int v = 1, int l = 0, int r = maxn)
{
    if(a <= l && r <= b)
        return mn[v];
    if(r <= a || b <= l)
        return inf;
    int m = (l + r) / 2;
    return min(get(a, b, 2 * v, l, m), get(a, b, 2 * v + 1, m, r));
}

int main()
{
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    fill(mn, mn + 4 * maxn, inf);
    int m;
    cin >> m;
    string s;
    cin >> s;
    int n = s.size();
    int sigma = 26;
    int cnt[sigma];
    for(int c = 'a'; c <= 'z'; c++)
    {
        int dp[n + 1][2];
        dp[0][0] = dp[0][1] = 0;
        upd(0, 0);
        for(int i = 1; i <= n; i++)
        {
            dp[i][0] = get(max(0, i - m + 1), i);
            if(s[i - 1] == c)
                dp[i][1] = get(max(0, i - m), i) + 1;
            else if(s[i - 1] < c)
                dp[i][1] = get(max(0, i - m), i);
            else
                dp[i][1] = inf;
            upd(i, dp[i][1]);
        }
        if(min(dp[n][0], dp[n][1]) == inf)
        {
            cout << string(count(begin(s), end(s), c), c);
        }
        else
        {
            cout << string(min(dp[n][0], dp[n][1]), c);
            return 0;
        }
    }
    return 0;
}