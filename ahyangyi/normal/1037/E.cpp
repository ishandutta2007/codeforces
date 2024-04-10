#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);

    int n, m, k;

    cin >> n >> m >> k;
    struct edge
    {
        int f, t;
        bool v;
    };
    vector<edge> e(m);
    vector<vector<int>> b(n);
    vector<int> deg(n);

    for (int i = 0; i < m; ++i)
    {
        cin >> e[i].f >> e[i].t;
        e[i].v = true;
        --e[i].f; --e[i].t;
        ++deg[e[i].f];
        ++deg[e[i].t];
        b[e[i].f].push_back(i);
        b[e[i].t].push_back(i);
    }

    vector<bool> bad(n, false);
    int total_valid = n;
    vector<int> ans(m);

    for (int i = m; i >= 0; --i)
    {
        if (i < m)
        {
            ans[i] = total_valid;
        }

        queue<int> q;
        if (i == m)
        {
            for (int j = 0; j < n; ++j)
            {
                if (deg[j] < k)
                {
                    bad[j] = true;
                    q.push(j);
                }
            }
        }
        else if (e[i].v)
        {
            e[i].v = false;
            --deg[e[i].f];
            if (!bad[e[i].f] && deg[e[i].f] < k)
            {
                bad[e[i].f] = true;
                q.push(e[i].f);
            }
            --deg[e[i].t];
            if (!bad[e[i].t] && deg[e[i].t] < k)
            {
                bad[e[i].t] = true;
                q.push(e[i].t);
            }
        }
        while (!q.empty())
        {
            int c = q.front();
            q.pop();
            --total_valid;

            for (int j : b[c])
            {
                if (e[j].v)
                {
                    e[j].v = false;
                    --deg[e[j].f];
                    if (!bad[e[j].f] && deg[e[j].f] < k)
                    {
                        bad[e[j].f] = true;
                        q.push(e[j].f);
                    }
                    --deg[e[j].t];
                    if (!bad[e[j].t] && deg[e[j].t] < k)
                    {
                        bad[e[j].t] = true;
                        q.push(e[j].t);
                    }
                }
            }
        }
    }

    for (int i = 0; i < m; ++i)
        cout << ans[i] << endl;

    return 0;
}