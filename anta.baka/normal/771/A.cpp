#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

constexpr int N = 200001;

int n, m, c = 0;
vector<int> g[N];
bool u[N];

void dfs(int v, int s)
{
    c++;
    u[v] = true;
    if (g[v].size() != s)
    {
        cout << "NO";
        exit(0);
    }
    for(int t : g[v]) if (!u[t]) dfs(t, s);
}

int main()
{
    ios::sync_with_stdio(false);
    cin >> n >> m;
    for(int i = 0; i < m; ++i)
    {
        int a, b; cin >> a >> b; --a; --b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    for(int i = 0; i < n; ++i)
    {
        if (!u[i]){
        c = 0;
        dfs(i, g[i].size());
        if (c != g[i].size() + 1) return cout << "NO", 0;}
    }
    cout << "YES";
}