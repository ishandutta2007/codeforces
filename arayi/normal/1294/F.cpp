#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
 
const int N = (int) 2e5 + 7;
int n;
vector<int> g[N];
int d[N];
int r1;
int r2;
 
void dfs(int a)
{
    for (auto &b : g[a])
    {
        if (d[b] == -1)
        {
            d[b] = 1 + d[a];
            dfs(b);
        }
    }
}
 
void fd(int root)
{
    for (int i = 1; i <= n; i++)
    {
        d[i] = -1;
    }
    d[root] = 0;
    dfs(root);
}
 
int mnode()
{
    int md = 0;
    for (int i = 1; i <= n; i++)
    {
        md = max(md, d[i]);
    }
    for (int i = 1; i <= n; i++)
    {
        if (i == r1 || i == r2) continue;
        if (d[i] == md)
        {
            return i;
        }
    }
    return 1;
}
 
vector<int> path, sol;
int wb;
void dfs2(int a)
{
    d[a] = 0;
    path.push_back(a);
    if (a == wb)
    {
        sol = path;
    }
    for (auto &b : g[a])
    {
        if (d[b] == -1)
        {
            dfs2(b);
        }
    }
    path.pop_back();
}
 
vector<int> gpath(int a, int b)
{
    for (int i = 1; i <= n; i++)
    {
        d[i] = -1;
    }
    wb = b;
    path.clear();
    dfs2(a);
    return sol;
}
 
 
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
 
    cin >> n;
    for (int i = 1; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    fd(1);
    int a = mnode();
    fd(a);
    int b = mnode();
    vector<int> x = gpath(a, b);
    queue<int> q;
    for (int i = 1; i <= n; i++)
    {
        d[i] = -1;
    }
    for (auto &c : x)
    {
        d[c] = 0;
        q.push(c);
    }
    while (!q.empty())
    {
        int x = q.front();
        q.pop();
        for (auto &y : g[x])
        {
            if (d[y] == -1)
            {
                d[y] = 1 + d[x];
                q.push(y);
            }
        }
    }
    r1 = a;
    r2 = b;
    int c = mnode();
    cout << (int) x.size() + d[c] - 1 << "\n";
    cout << a << " " << b << " " << c << "\n";
}