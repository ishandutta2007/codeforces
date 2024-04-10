#include <bits/stdc++.h>

using namespace std;

#define int long long

const int MAX_N = 2009;
vector<int> g[MAX_N];
vector<int> rg[MAX_N];
string s[MAX_N];
int n, m;
bool used[MAX_N];
int ts[MAX_N];
int cnt;
int c[MAX_N];
vector<int> g1[MAX_N];
int h[MAX_N];

void dfs(int v)
{
    used[v] = true;
    for (int to : g[v])
    {
        if (!used[to])
            dfs(to);
    }
    ts[cnt] = v;
    cnt++;
}

void find_comp(int v)
{
    used[v] = true;
    c[v] = cnt;
    for (int to : rg[v])
    {
        if (!used[to])
            find_comp(to);
    }
}

void find_ans(int v)
{
    h[v] = 1;
    used[v] = true;
    for (int to : g1[v])
    {
        if (!used[to])
            find_ans(to);
        h[v] = max(h[v], h[to] + 1);
    }
}

signed main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> s[i];
        for (int e = 0; e < m; e++)
        {
            if (s[i][e] == '<')
            {
                g[i].push_back(e + n);
                rg[e + n].push_back(i);
            }
            else if (s[i][e] == '>')
            {
                g[e + n].push_back(i);
                rg[i].push_back(e + n);
            }
            else
            {
                g[i].push_back(e + n);
                g[e + n].push_back(i);
                rg[i].push_back(e + n);
                rg[e + n].push_back(i);
            }
        }
    }
    for (int i = 0; i < n + m; i++)
    {
        if (!used[i])
            dfs(i);
    }
    cnt = 0;
    for (int i = 0; i < n + m; i++)
        used[i] = false;
    for (int i = m + n - 1; i >= 0; i--)
    {
        int v = ts[i];
        if (!used[v])
        {
            find_comp(v);
            cnt++;
        }
    }
    for (int i = 0; i < n + m; i++)
    {
        for (int to : rg[i])
        {
            if (c[i] != c[to] && c[i] > c[to])
                g1[c[i]].push_back(c[to]);
        }
        used[i] = false;
    }
    for (int i = 0; i < cnt; i++)
    {
        if (!used[i])
            find_ans(i);
    }
    for (int i = 0; i < n + m; i++)
        c[i] = h[c[i]];
    for (int i = 0; i < n; i++)
    {
        for (int e = 0; e < m; e++)
        {
            if ((s[i][e] == '=' && c[i] == c[e + n]) || (s[i][e] == '>' && c[i] > c[e + n]) || (s[i][e] == '<' && c[i] < c[e + n]))
                continue;
            else
            {
                cout << "No";
                return 0;
            }
        }
    }
    cout << "Yes\n";
    for (int i = 0; i < n; i++)
        cout << c[i] << " ";
    cout << "\n";
    for (int i = 0; i < m; i++)
        cout << c[i + n] << " ";
}