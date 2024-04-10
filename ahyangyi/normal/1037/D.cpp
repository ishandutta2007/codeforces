#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
    int n;
    struct edge
    {
        int from, to;
        int real_direction;
    };

    cin >> n;
    vector<edge> e(n);
    vector<vector<int>> outbounds(n), inbounds(n);
    for (int i = 0; i < n - 1; ++i)
    {
        cin >> e[i].from >> e[i].to;
        --e[i].from; --e[i].to;

        outbounds[e[i].from].push_back(i);
        inbounds[e[i].to].push_back(i);
    }

    vector<int> generation(n);
    vector<int> children(n);
    vector<int> parent(n);
    {
        vector<bool> visited(n, false);
        queue<int> q;

        visited[0] = true;
        q.push(0);

        while (!q.empty())
        {
            int cur = q.front();
            q.pop();
            for (int i : outbounds[cur])
            {
                if (!visited[e[i].to])
                {
                    visited[e[i].to] = true;
                    e[i].real_direction = 0;
                    generation[e[i].to] = generation[cur] + 1;
                    ++children[cur];
                    parent[e[i].to] = cur;
                    q.push(e[i].to);
                }
            }
            for (int i : inbounds[cur])
            {
                if (!visited[e[i].from])
                {
                    visited[e[i].from] = true;
                    e[i].real_direction = 1;
                    generation[e[i].from] = generation[cur] + 1;
                    ++children[cur];
                    parent[e[i].from] = cur;
                    q.push(e[i].from);
                }
            }
        }
    }

    vector<int> s(n);
    int p;
    for (int i = 0; i < n; ++i)
    {
        cin >> s[i];
        --s[i];
        if (i == 0)
        {
            p = 0;
        }
        else
        if (generation[s[i]] < generation[s[i - 1]])
        {
            cout << "No" << endl;
            return 0;
        }
        else
        {
            if (parent[s[i]] != s[p])
            {
                cout << "No" << endl;
                return 0;
            }
            --children[s[p]];
            while (p <= i && children[s[p]] == 0)
            {
                ++p;
            }
        }
    }

    cout << "Yes" << endl;
    return 0;
}