#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 100009;
vector<int> g[MAX_N];
int n, k;
int ma_h = 0;
int ma = 0;
int d[MAX_N];
int d1[MAX_N];
bool r = true;

void dfs(int v, int pr, int h)
{
    if (r)
        d[v] = h;
    else
        d1[v] = h;
    if (h > ma_h)
    {
        ma_h = h;
        ma = v;
    }
    for (int to : g[v])
    {
        if (to != pr)
            dfs(to, v, h + 1);
    }
}

bool check(int v, int pr, int h)
{
    if (h == k && g[v].size() > 1)
        return false;
    if (h < k && g[v].size() == 1)
        return false;
    if (h == k)
        return true;
    if (g[v].size() < 4)
        return false;
    for (int to : g[v])
    {
        if (to != pr)
        {
            if (!check(to, v, h + 1))
                return false;
        }
    }
    return true;
}

signed main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> k;
    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    dfs(0, -1, 0);
    ma_h = 0;
    dfs(ma, -1, 0);
    r = false;
    dfs(ma, -1, 0);
    int s = -1;
    if (ma_h % 2 == 1 || ma_h / 2 != k)
    {
        cout << "No";
        return 0;
    }
    for (int i = 0; i < n; i++)
    {
        if (d[i] == ma_h / 2 && d1[i] == ma_h / 2)
            s = i;
    }
    if (s == -1)
    {
        cout << "No";
        return 0;
    }
    if (g[s].size() <= 2)
    {
        cout << "No";
        return 0;
    }
    bool q = true;
    for (int to : g[s])
        q &= check(to, s, 1);
    if (q)
        cout << "Yes";
    else
        cout << "No";
}