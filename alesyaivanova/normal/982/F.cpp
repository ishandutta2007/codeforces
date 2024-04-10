#include <bits/stdc++.h>

using namespace std;

int n, m, n1;
vector<int> g[100000];
int used[100000];
int q[100000];
int j = 2;
int p[100000];
int beg = -1;
bool k = true;
int d[100000];
vector<int> sup;
int super_v;

bool find_circle(int v)
{
    used[v] = 1;
    for (int to : g[v])
    {
        if (!used[to])
        {
            if (find_circle(to))
            {
                used[v] = 2;
                if (v == beg)
                    k = false;
                if (k)
                {
                    q[j] = v;
                    p[v] = j;
                    j++;
                }
                return true;
            }
        }
        else if (used[to] == 1)
        {
            beg = to;
            q[0] = to;
            p[to] = 0;
            q[1] = v;
            p[v] = 1;
            used[v] = 2;
            return true;
        }
    }
    used[v] = 2;
    return false;
}

void dfs(int v)
{
    used[v] = 1;
    for (int to: g[v])
    {
        if ((p[to] != -1) && ((p[to] + 1) % j != p[v]) && (d[beg] == -1 || (p[to] - beg + j) % j < d[beg]))
            d[beg] = (p[to] - beg + j) % j;
        if ((p[to] == -1) && (!used[to]))
            dfs(to);
    }
    used[v] = 2;
}

bool dfs1(int v)
{
    used[v] = 1;
    for (int to : g[v])
    {
        if (to == super_v)
            continue;
        if (!used[to])
        {
            if (dfs1(to))
            {
                used[v] = 2;
                return true;
            }
        }
        else if (used[to] == 1)
        {
            used[v] = 2;
            return true;
        }
    }
    used[v] = 2;
    return false;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        g[a].push_back(b);
    }
    for (int i = 0; i < n; i++)
    {
        p[i] = -1;
        d[i] = -1;
    }
    for (int i = 0; i < n; i++)
    {
        if ((!used[i]) && find_circle(i))
            break;
    }
    for (int i = 0; i < n; i++)
        used[i] = 0;
    for (int i = j - 1; i >= 0; i--)
    {
        beg = i;
        dfs(q[i]);
    }
    vector<pair<int, int> > w;
    int num = 0;
    for (int i = 0; i < j; i++)
    {
        if (d[i] == -1)
            continue;
        num++;
        if (i + d[i] < j)
        {
            w.emplace_back(i, -1);
            w.emplace_back(i + d[i], 1);
        }
        else
        {
            w.emplace_back(0, -1);
            w.emplace_back((i + d[i]) % j, 1);
            w.emplace_back(i, -1);
            w.emplace_back(j - 1, 1);
        }
    }
    sort(w.begin(), w.end());
    if (w.empty())
        sup.push_back(q[0]);
    int bal = 0;
    for (int i = 0; i < (int) w.size(); i++)
    {
        bal -= w[i].second;
        if (bal == num)
        {
            int e = w[i].first;
            while (true)
            {
                sup.push_back(q[e]);
                if (e == w[i + 1].first)
                    break;
                e++;
            }
        }
    }
    if (sup.empty())
    {
        cout << -1;
        return 0;
    }
    for (int e = 0; e < (int) sup.size(); e++)
    {
        super_v = sup[e];
        for (int i = 0; i < n; i++)
            used[i] = 0;
        bool c = true;
        for (int v = 0; v < n; v++)
        {
            if (v == super_v)
                continue;
            if ((!used[v]) && dfs1(v))
                c = false;
        }
        if (c)
        {
            cout << super_v + 1;
            return 0;
        }
    }
    cout << -1;
}