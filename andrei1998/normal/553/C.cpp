#include <iostream>
#include <vector>
#include <bitset>

#define mod 1000000007
using namespace std;

struct edge {
    int a, b;
    bool type;
} edges[100005];

int n;
int father[100005];
int h[100005];

inline void init () {
    for (int i = 1; i <= n; i++) {
        father[i] = i;
        h[i] = 1;
    }
}

int f (int x) {
    if (father[x] != x)
        father[x] = f(father[x]);
    return father[x];
}

inline void unite (int x, int y) {
    x = f(x);
    y = f(y);

    if (x == y)
        return ;

    if (h[x] < h[y])
        father[x] = y;
    else {
        if (h[x] == h[y])
            h[x] ++;
        father[y] = x;
    }
}

vector <int> graph[100005];
bitset <100005> vis;

int in[100005];
bool ok;

void dfs (int node) {
    vis[node] = 1;

    for (vector <int> :: iterator it = graph[node].begin(); it != graph[node].end(); it++)
        if (!vis[*it]) {
            in[*it] = 1 + in[node];
            dfs(*it);
        }
        else if ((in[node] + in[*it]) % 2 == 0)
            ok = false;
}

int main()
{
    ok = true;
    ios_base :: sync_with_stdio(false);
    cin >> n;
    init();

    int m = 0;
    cin >> m;

    for (int i = 1; i <= m; i++)
        cin >> edges[i].a >> edges[i].b >> edges[i].type;

    for (int i = 1; i <= m; i++)
        if (edges[i].type == 1)
            unite(edges[i].a, edges[i].b);

    for (int i = 1; i <= m; i++)
        if (edges[i].type == 0) {
            graph[f(edges[i].a)].push_back(f(edges[i].b));
            graph[f(edges[i].b)].push_back(f(edges[i].a));
        }

    for (int i = 1; i <= n; i++)
        if (!vis[f(i)])
            dfs(f(i));

    if (!ok) {
        cout << "0\n";
        return 0;
    }

    for (int i = 1; i <= m; i++)
        if (edges[i].type == 0)
            unite(edges[i].a, edges[i].b);

    vis &= 0;
    int ans = 0;

    for (int i = 1; i <= n; i++)
        if (!vis[f(i)]) {
            ans ++;
            vis[f(i)] = 1;
        }

    int real_ans = 1;
    for (int i = 1; i < ans; i++)
        real_ans = (2ll * real_ans) % mod;

    cout << real_ans << '\n';
    return 0;
}