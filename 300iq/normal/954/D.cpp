#include <cmath>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <map>
#include <list>
#include <time.h>
#include <math.h>
#include <random>
#include <deque>
#include <queue>
#include <cassert>
#include <unordered_map>
#include <iomanip>
#include <bitset>

using namespace std;

typedef long long ll;

mt19937 rnd(228);

const int N = 1000 + 7;

int dist[N][N];
vector <int> g[N];

int main()
{
#ifdef ONPC
    freopen("a.in", "r", stdin);
#endif
    int n, m, s, t;
    cin >> n >> m >> s >> t;
    s--, t--;
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        a--, b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    for (int i = 0; i < n; i++)
    {
        queue <int> q;
        q.push(i);
        for (int j = 0; j < n; j++)
        {
            dist[i][j] = -1;
        }
        dist[i][i] = 0;
        while (!q.empty())
        {
            int v = q.front();
            q.pop();
            for (int to : g[v])
            {
                if (dist[i][to] == -1)
                {
                    dist[i][to] = dist[i][v] + 1;
                    q.push(to);
                }
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (dist[i][j] != 1 && min(dist[s][i] + 1 + dist[j][t], dist[s][j] + 1 + dist[i][t]) >= dist[s][t])
            {
                ans++;
            }
        }
    }
    cout << ans << '\n';
}