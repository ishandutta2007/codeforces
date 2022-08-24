#include <bits/stdc++.h>

using namespace std;

const int N = 2e3 + 1;

vector <int> g[N];
vector <int> gr[N];

void add_edge(int a, int b)
{
    g[a].push_back(b);
    gr[b].push_back(a);
}

string first(string s)
{
    return s.substr(0, 3);
}

string second(string a, string b)
{
    return a.substr(0, 2) + b[0];
}

vector <int> t;
bool u[N];
int comp[N];
int sz;

void dfs(int v)
{
    u[v] = 1;
    for (auto to : g[v])
    {
        if (!u[to])
        {
            dfs(to);
        }
    }
    t.push_back(v);
}

void zhfs(int v)
{
    u[v] = 1;
    comp[v] = sz;
    for (auto to : gr[v])
    {
        if (!u[to])
        {
            zhfs(to);
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    int n;
    cin >> n;
    vector <pair <string, string> > e;
    for (int i = 0; i < n; i++)
    {
        string a, b;
        cin >> a >> b;
        e.push_back({first(a), second(a, b)});
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == j)
            {
                continue;
            }
            if (e[i].first == e[j].first)
            {
                add_edge(2 * i, 2 * j + 1);
                add_edge(2 * i + 1, 2 * j + 1);
            }
            if (e[i].second == e[j].second)
            {
                add_edge(2 * i + 1, 2 * j);
            }
            if (e[i].second == e[j].first)
            {
                add_edge(2 * i + 1, 2 * j + 1);
            }
            if (e[i].first == e[j].second)
            {
                add_edge(2 * i, 2 * j);
            }
        }
    }
    int last = 2 * n;
    for (int i = 0; i < last; i++)
    {
        if (!u[i])
        {
            dfs(i);
        }
    }
    reverse(t.begin(), t.end());
    memset(u, 0, sizeof u);
    for (auto i : t)
    {
        if (!u[i])
        {
            sz++;
            zhfs(i);
        }
    }
    for (int i = 0; i < last; i++)
    {
        if (comp[i] == comp[i ^ 1])
        {
            cout << "NO\n";
            return 0;
        }
    }
    cout << "YES\n";
    for (int i = 0; i < n; i++)
    {
        if (comp[2 * i] > comp[2 * i + 1])
        {
            cout << e[i].first << '\n';
        }
        else
        {
            cout << e[i].second << '\n';
        }
    }
}