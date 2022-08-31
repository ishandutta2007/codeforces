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
#include <unordered_set>
#include <iomanip>
#include <bitset>
#include <sstream>

using namespace std;

typedef long long ll;

mt19937 rnd(228);

const int N = 1e5 + 7;
const int K = 1e2 + 1;

int dist[N][K];
vector <int> g[N];

int main()
{
#ifdef ONPC
    freopen("a.in", "r", stdin);
#endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m, k, s;
    cin >> n >> m >> k >> s;
    vector <int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        a[i]--;
    }
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        a--, b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    for (int i = 0; i < k; i++)
    {
        queue <int> q;
        for (int j = 0; j < n; j++)
        {
            if (a[j] == i)
            {
                dist[j][i] = 0;
                q.push(j);
            }
            else
            {
                dist[j][i] = -1;
            }
        }
        while (!q.empty())
        {
            int v = q.front();
            q.pop();
            for (int to : g[v])
            {
                if (dist[to][i] == -1)
                {
                    dist[to][i] = dist[v][i] + 1;
                    q.push(to);
                }
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        vector <int> t;
        for (int j = 0; j < k; j++)
        {
            t.push_back(dist[i][j]);
        }
        sort(t.begin(), t.end());
        int ans = 0;
        for (int j = 0; j < s; j++) ans += t[j];
        cout << ans << ' ';
    }
    cout << '\n';
}