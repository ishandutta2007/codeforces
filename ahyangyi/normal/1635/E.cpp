#include <cstdio>
#include <vector>
#include <queue>

using namespace std;
const int N = 100000;
const int M = 200000;

int main()
{
    int n, m;

    scanf("%d%d", &n, &m);
    vector<vector<pair<int, int>>> edges(n);
    vector<vector<int>> edges2(n);
    for (int i = 0; i < m; ++i)
    {
        int t, a, b;
        scanf("%d%d%d", &t, &a, &b);
        --a;
        --b;
        edges[a].push_back(make_pair(b, t));
        edges[b].push_back(make_pair(a, t));
    }

    vector<char> color(n);
    vector<int> loc(n);
    vector<int> in_degree(n);
    int lp = 0;
    {
        vector<char> visited(n);
        for (int i = 0; i < n; ++i)
        {
            if (!visited[i])
            {
                vector<int> q;
                int qp = 0;

                q.push_back(i);
                visited[i] = 1;

                while (qp < q.size())
                {
                    int x = q[qp++];
                    char xcolor = color[x];

                    for (const auto& e: edges[x])
                    {
                        int dst = e.first;
                        int type = e.second;
                        if (!visited[dst])
                        {
                            visited[dst] = 1;
                            q.push_back(dst);
                            color[dst] = 1 - xcolor;
                        }
                        if (color[dst] != 1 - xcolor)
                        {
                            printf("NO\n");
                            return 0;
                        }
                        if (dst > x)
                        {
                            if ((type == 2) ^ (xcolor == 0))
                            {
                                edges2[x].push_back(dst);
                                ++in_degree[dst];
                            }
                            else
                            {
                                edges2[dst].push_back(x);
                                ++in_degree[x];
                            }
                        }
                    }
                }

                vector<int> q2;
                int qp2 = 0;
                for (int i = 0; i < q.size(); ++i)
                {
                    if (in_degree[q[i]] == 0)
                    {
                        q2.push_back(q[i]);
                    }
                }

                while (qp2 < q2.size())
                {
                    int x = q2[qp2++];
                    loc[x] = lp++;

                    for (int y : edges2[x])
                    {
                        if (--in_degree[y] == 0)
                        {
                            q2.push_back(y);
                        }
                    }
                }

                if (q2.size() != q.size())
                {
                    printf("NO\n");
                    return 0;
                }
            }
        }
    }

    printf("YES\n");
    for (int i = 0; i < n; ++i)
    {
        printf("%c %d\n", (color[i] == 0? 'L' : 'R'), loc[i]);
    }
    return 0;
}