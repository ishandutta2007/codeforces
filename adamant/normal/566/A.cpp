#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e6 + 7;

map<char, int> to[maxn];
set<int> nam[maxn][2];
int sz = 1;

void add_str(string s, int num, int type)
{
    int v = 0;
    for(auto c: s)
    {
        if(!to[v][c])
            to[v][c] = sz++;
        v = to[v][c];
    }
    nam[v][type].insert(num);
}

int par[maxn];
int ans = 0;

void dfs(int v = 0, int lev = 0)
{
    for(auto it: to[v])
    {
        int u = it.second;
        dfs(u, lev + 1);
        if(nam[v][0].size() < nam[u][0].size())
            swap(nam[v][0], nam[u][0]);
        for(auto it: nam[u][0])
            nam[v][0].insert(it);
        if(nam[v][1].size() < nam[u][1].size())
            swap(nam[v][1], nam[u][1]);
        for(auto it: nam[u][1])
            nam[v][1].insert(it);
    }
    while(nam[v][0].size() && nam[v][1].size())
    {
        ans += lev;
        par[*nam[v][0].begin()] = *nam[v][1].begin();
        nam[v][0].erase(nam[v][0].begin());
        nam[v][1].erase(nam[v][1].begin());
    }
}

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        add_str(s, i, 0);
    }
    for(int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        add_str(s, i, 1);
    }
    dfs();
    cout << ans << "\n";
    for(int i = 0; i < n; i++)
        cout << i + 1 << ' ' << par[i] + 1 << "\n";
    return 0;
}