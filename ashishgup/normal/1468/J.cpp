#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
#define sz(x) ((int)x.size())
#define endl "\n"
#define inf (1LL<<62)
#define ninf (-inf)

const int nax = 200005;
int dsu[nax], size[nax];

int findSet(int x)
{
    if(dsu[x] != x)
        dsu[x] = findSet(dsu[x]);
    return dsu[x];
}

void mergeSet(int u, int v)
{
    u = findSet(u);
    v = findSet(v);
    if(u == v)
        return;
    if(size[u] < size[v])
        swap(u, v);
    dsu[v] = u;
    size[u] += size[v];
}

void initialise(int n)
{
    for(int i = 0; i <= n; i++)
    {
        dsu[i] = i;
        size[i] = 1;
    }
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        int n, m, K;
        cin >> n >> m >> K;
        initialise(n);
        vector< pair<int, pair<int, int>> > edges[2];
        for(int i = 0; i < m; i++)
        {
            int x, y, s;
            cin >> x >> y >> s;
            if(s <= K)
                edges[0].pb({s, {x, y}});
            else
                edges[1].pb({s, {x, y}});
        }
        if(n == 1)
        {
            cout << "0\n";
            continue;
        }
        int ans;
        sort(edges[0].rbegin(), edges[0].rend());
        sort(edges[1].begin(), edges[1].end());
        int added = 0;
        for(auto &k: edges[0])
        {
            int u = k.second.first, v = k.second.second;
            if(findSet(u) != findSet(v))
                added++;
            mergeSet(u, v);
        }
        if(added == n-1)
        {
            ans = K - edges[0][0].first;
            if(sz(edges[1]))
                ans = min(ans, edges[1][0].first-K);
        }
        else
        {
            ans = 0;
            for(auto &k: edges[1])
            {
                int u = k.second.first, v = k.second.second;
                if(findSet(u) != findSet(v))
                    ans += k.first-K;
                mergeSet(u, v);
            }
        }
        cout << ans << "\n";
    }
}