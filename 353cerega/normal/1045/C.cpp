#include <bits/stdc++.h>

using namespace std;


namespace fi
{
const
int bsize = 20000000;

char buff[bsize];
int sz;

void start()
{
    sz = fread(buff, 1, bsize, stdin);
    buff[sz++] = '\n';
}

int i = 0;
typedef double ld;
inline
double get_d()
{
    while (!isdigit(buff[i])) ++i;
    i += 4;
    return buff[i - 4] - '0' + ld(buff[i - 2] - '0') / 10 + ld(buff[i - 1] - '0') / 100;
}

inline
int get_i()
{

    while (!isdigit(buff[i])) ++i;
    int ans(0);
    while (isdigit(buff[i])) ans = ans * 10 + buff[i++] - '0';
    return ans;
}

}

#define MX 100100

vector<int> g[MX];
int p[19][MX];
int h[MX];

void bfs()
{
    queue<int> q;
    p[0][1] = 1;
    h[1] = 0;
    q.push(1);
    while (!q.empty())
    {
        int v(q.front());
        q.pop();
        for (int i(1); i < 19; ++i)
            p[i][v] = p[i - 1][p[i - 1][v]];
        for (int u : g[v])
            if (!p[0][u])
            {
                p[0][u] = v;
                h[u] = h[v] + 1;
                q.push(u);
            }
    }
}

inline
pair<int, int> pre_lca(int u, int v)
{
    if (h[u] < h[v]) swap(u, v);
    int sh(18);
    while (h[u] != h[v])
    {
        while (sh && h[p[sh][u]] < h[v])
            --sh;
        u = p[sh][u];
    }
    return {u, v};
}

inline
int cnt(const vector<int>& v, int x)
{
    auto it = lower_bound(v.begin(), v.end(), x);
    if (it == v.end() || *it != x) return 0;
    return 1;
}

int get_dist(int u, int v)
{
    auto lca = pre_lca(u, v);
    if (lca.first == lca.second)
        return abs(h[u] - h[v]);
    int a = lca.first;
    int b = lca.second;
    int sh = 18;
    while (p[0][a] != p[0][b])
    {
        while (sh && p[sh][a] == p[sh][b])
            --sh;
        a = p[sh][a];
        b = p[sh][b];
    }
    return h[u] + h[v] - h[a] - h[b] + 2 - cnt(g[a], b);
}

int main()
{
    //freopen("input.txt", "r", stdin);
    fi::start();
    int n = fi::get_i();
    int m = fi::get_i();
    int q = fi::get_i();
    for (int u, v, i(0); i < m; ++i)
    {
        u = fi::get_i();
        v = fi::get_i();
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for (int i(1); i <= n; ++i)
        sort(g[i].begin(), g[i].end());
    bfs();
    while (q--)
    {
        int u = fi::get_i();
        int v = fi::get_i();
        printf("%i\n", get_dist(u, v));
    }
}