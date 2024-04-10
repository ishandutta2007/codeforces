#include <bits/stdc++.h>

using namespace std;

#define int long long
#define ff first
#define ss second
#define pb emplace_back
#define pf emplace_front
#define pii pair<int, int>
#define mp make_pair

const int MAXN = 500009;
int ne[MAXN];
int n;
int num[MAXN];
int cnt;
int p[MAXN];
int lid[MAXN];
int sz[MAXN];
bool used[MAXN];
vector<int> g[MAXN];
bool ans;
int ma[20][MAXN];

int find_p(int e)
{
    if (p[e] == e)
        return e;
    p[e] = find_p(p[e]);
    return p[e];
}

void merg(int e1, int e2)
{
    e1 = find_p(e1);
    e2 = find_p(e2);
    if (e1 == e2)
        return;
    if (sz[e1] < sz[e2])
    {
        int c = e1;
        e1 = e2;
        e2 = c;
    }
    p[e2] = e1;
    lid[e1] = max(lid[e1], lid[e2]);
    sz[e1] += sz[e2];
}

void dfs(int e)
{
    used[e] = true;
    if (e > 0 && used[e - 1])
        merg(e, e - 1);
    if (e < n - 1 && used[e + 1])
        merg(e, e + 1);
    for (int to : g[e])
    {
        if (!used[to])
            dfs(to);
    }
    if (ne[e] == -1)
    {
        num[e] = cnt;
        cnt++;
        return;
    }
    int i = e + 1;
    while (i < ne[e])
    {
        if (!used[i])
            dfs(i);
        else
            i = lid[find_p(i)];
        i++;
    }
    num[e] = cnt;
    cnt++;
}

bool check()
{
    for (int i = 0; i < n; i++)
        ma[0][i] = num[i];
    for (int lg = 1; lg < 20; lg++)
    {
        for (int i = 0; i < n; i++)
        {
            ma[lg][i] = ma[lg - 1][i];
            if (i + (1 << (lg - 1)) < n)
                ma[lg][i] = max(ma[lg][i], ma[lg - 1][i + (1 << (lg - 1))]);
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (ne[i] == -1)
            continue;
        if (ne[i] != n && num[ne[i]] < num[i])
            return false;
        if (ne[i] == i + 1)
            continue;
        int len = ne[i] - i - 1;
        int lg = 0;
        while ((1 << (lg + 1)) <= len)
            lg++;
        int cur_ma = max(ma[lg][i], ma[lg][ne[i] - (1 << lg)]);
        if (cur_ma > num[i])
            return false;
    }
    return true;
}

signed main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    for (int j = 0; j < t; j++)
    {
        cin >> n;
        for (int i = 0; i <= n; i++)
        {
            used[i] = false;
            sz[i] = 1;
            p[i] = i;
            lid[i] = i;
        }
        ne[n] = -1;
        for (int i = 0; i < n; i++)
        {
            cin >> ne[i];
            if (ne[i] == -1)
                continue;
            ne[i]--;
            g[ne[i]].pb(i);
        }
        n++;
        cnt = 0;
        int e = 0;
        ans = true;
        while (e < n)
        {
            if (!used[e])
                dfs(e);
            else
                e = lid[find_p(e)];
            e++;
        }
        n--;
        int u = num[n];
        for (int i = 0; i < n; i++)
        {
            if (num[i] >= u)
                num[i]--;
        }
        if (!check())
            cout << "-1\n";
        else
        {
            for (int i = 0; i < n; i++)
                cout << num[i] + 1 << " ";
            cout << "\n";
        }
        for (int i = 0; i <= n; i++)
        {
            g[i].resize(0);
            g[i].shrink_to_fit();
        }
    }
}