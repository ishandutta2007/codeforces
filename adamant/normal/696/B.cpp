#include <bits/stdc++.h>

using namespace std;

#define int int64_t
#define double long double
const int maxn = 1e5 + 42;
vector<int> g[maxn];
int sz[maxn];
double ans[maxn];
void dfs1(int v = 0)
{
    sz[v] = 1;
    for(auto u: g[v])
    {
        dfs1(u);
        sz[v] += sz[u];
    }
}

void dfs2(int v = 0, double t = 1)
{
    ans[v] = t;
    for(auto u: g[v])
        dfs2(u, 1 + t + (sz[v] - sz[u] - 1) / 2.);
}

signed main()
{
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for(int i = 1; i < n; i++)
    {
        int p;
        cin >> p;
        g[p - 1].push_back(i);
    }
    dfs1();
    dfs2();
    for(int i = 0; i < n; i++)
        cout << fixed << setprecision(8) << ans[i] << ' ';
	return 0;
}