#include <bits/stdc++.h>

using namespace std;

const int MX = 5000, INF = 1e9;

int dist[MX];
vector<int> G[MX];
vector<pair<int, int>> F[MX];

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        u--; v--;
        G[u].push_back(v);
        G[v].push_back(u);
    }

    int w;
    scanf("%d", &w);
    for (int i = 0; i < w; i++) {
        int c, k, p;
        scanf("%d %d %d", &c, &k, &p);

        F[c - 1].emplace_back(k, p);
    }

    int T;
    scanf("%d", &T);
    while (T--) {
        int g, r, a;
        scanf("%d %d %d", &g, &r, &a);
        g--;

        for (int j = 0; j < n; j++) dist[j] = INF;

        dist[g] = 0;
        vector<int> q = {g};
        for (int j = 0; j < (int)q.size(); j++)
            for (int v : G[q[j]])
                if (dist[v] == INF) {
                    dist[v] = dist[q[j]] + 1;
                    q.push_back(v);
                }

        int ans;
        long long sum = (long long)(INF + 42) * r;
        priority_queue<pair<int, int>> S;
        S.emplace(INF + 42, r);
        for (int i = 0; i < (int)q.size() && sum > a; i++) {
            ans = dist[q[i]];

            for (const auto& x : F[q[i]]) {
                int cnt = 0;
                while (cnt < x.first && (int)S.size() > 0) {
                    const auto& f = S.top();
                    if (f.first < x.second) break;
                    if (cnt + f.second <= x.first) {
                        sum -= f.second * 1ll * f.first;
                        cnt += f.second;
                        S.pop();
                    }
                    else {
                        sum -= (x.first - cnt) * 1ll * f.first;
                        auto y = f;
                        y.second -= x.first - cnt;
                        S.pop();
                        S.push(y);
                        cnt = x.first;
                    }
                }

                if (cnt > 0) {
                    sum += cnt * 1ll * x.second;
                    S.emplace(x.second, cnt);
                }
            }
        }

        if (sum > a) printf("-1\n");
        else printf("%d\n", ans);
    }

    return 0;
}