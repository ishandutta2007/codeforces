#include <bits/stdc++.h>

using namespace std;

#define int int64_t

signed main()
{
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m, L, s, t;
    cin >> n >> m >> L >> s >> t;
    int u[m], v[m], w[m];
    vector<int> g[n];
    for(int i = 0; i < m; i++)
    {
        cin >> u[i] >> v[i] >> w[i];
        g[u[i]].push_back(i);
        g[v[i]].push_back(i);
    }
    int dp[n][n];
    int pr[n][n];
    int in_que[n][n];
    memset(in_que, 0, n * n * sizeof(int));
    memset(dp, 0x3F, n * n * sizeof(int));
    dp[s][0] = 0;
    deque<pair<int, int>> que;
    que.push_back({s, 0});
    in_que[s][0] = 1;
    while(!que.empty())
    {
        int V = que.front().first;
        int lv = que.front().second;
        que.pop_front();
        in_que[V][lv] = 0;
        for(auto it: g[V])
        {
            int U = v[it] == V ? u[it] : v[it];
            int c = w[it];
            int lvu = lv + (c == 0);
            if(lvu >= n)
                continue;
            if(dp[V][lv] + max(c, 1LL) < dp[U][lvu])
            {
                dp[U][lvu] = dp[V][lv] + max(c, 1LL);
                pr[U][lvu] = it;
                if(!in_que[U][lvu])
                    que.push_back({U, lvu});
                in_que[U][lvu] = 1;
            }
        }
    }
    if(dp[t][0] < L)
    {
        cout << "NO\n";
        return 0;
    }
    for(int i = 0; i < n; i++)
    {
        if(dp[t][i] <= L)
        {
            cout << "YES\n";
            vector<int> path;
            int q = t;
            int lv = i;
            while(q != s)
            {
                int nu = u[pr[q][lv]] == q ? v[pr[q][lv]] : u[pr[q][lv]];
                if(w[pr[q][lv]] == 0)
                {
                    path.push_back(pr[q][lv]);
                    lv--;
                }
                q = nu;
            }
            for(int i = 0; i + 1 < path.size(); i++)
                w[path[i]] = 1;
            if(path.size())
                w[path.back()] = L - dp[t][i] + 1;
            assert(path.size() == i);
            const int inf = 1e17;
            for(int i = 0; i < m; i++)
                cout << u[i] << ' ' << v[i] << ' ' << (w[i] == 0 ? inf : w[i]) << "\n";
            return 0;
        }
    }
    cout << "NO\n";
	return 0;
}