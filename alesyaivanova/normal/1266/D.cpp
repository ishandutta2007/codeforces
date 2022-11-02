#include <bits/stdc++.h>

using namespace std;

#define int long long
#define ff first
#define ss second
#define pii pair<int, int>
#define pb emplace_back
#define pf emplace_front
#define mp make_pair
#define ld long double
#define all(x) x.begin(), x.end()

const int maxn = 1e5 + 9;
map<int, int> g[maxn];
map<int, int> rg[maxn];
int n, m;
bool used[maxn];

void print()
{
    for (int v = 0; v < n; v++)
    {
        cout << v + 1 << ":\n";
        for (pii to : g[v])
            cout << to.ff + 1 << " "<< to.ss << "  ";
    }
}

signed main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif // LOCAL
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        a--; b--;
        g[a][b] += c;
        rg[b][a] += c;
    }
//    print();
    queue<int> q;
    for (int i = 0; i < n; i++)
    {
        if (!g[i].empty() && !rg[i].empty())
        {
            used[i] = 1;
            q.push(i);
        }
    }
    while (!q.empty())
    {
//        cout << "aaaa";
        int v = q.front();
        q.pop();
        used[v] = 0;
        auto j = g[v].begin();
        auto u = rg[v].begin();
        while (j != g[v].end() && u != rg[v].end())
        {
            if ((*j).ss == 0 || (*j).ff == v)
            {
                j = g[v].erase(j);
                continue;
            }
            if ((*u).ss == 0 || (*u).ff == v)
            {
                u = rg[v].erase(u);
                continue;
            }
            int mi = min((*j).ss, (*u).ss);
            (*j).ss -= mi;
            (*u).ss -= mi;
            int v1 = (*u).ff;
            int v2 = (*j).ff;
            rg[v2][v1] += mi;
            g[v1][v2] += mi;
            rg[v2][v] -= mi;
            g[v1][v] -= mi;
            if (!g[v1].empty() && !rg[v1].empty() && !used[v1])
            {
                used[v1] = 1;
                q.push(v1);
            }
            if (!g[v2].empty() && !rg[v2].empty() && !used[v2])
            {
                used[v2] = 1;
                q.push(v2);
            }
        }
//        cout << v << "!\n";
//        print();
    }
    int cnt = 0;
    for (int v = 0; v < n; v++)
    {
        for (auto j = g[v].begin(); j != g[v].end();)
        {
            if ((*j).ff == v || (*j).ss == 0)
                j = g[v].erase(j);
            else
                j++;
        }
        cnt += g[v].size();
    }
    cout << cnt << "\n";
    for (int i = 0; i < n; i++)
    {
        for (pii to : g[i])
            cout << i + 1 << " " << to.ff + 1 << " " << to.ss << "\n";
    }
}