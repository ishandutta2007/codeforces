#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <queue>


using namespace std;

const int MAXN = 1000100;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
vector<int> edge[MAXN];

bool inBoard(int x, int y, int n, int m) {
    return (x >= 0 && y >= 0 && x < n && y < m);
}
int vis[MAXN];

void bfs(int s, int dist[MAXN]) {
    queue<int> q;
    q.push(s);
    vis[s] = 1;
    dist[s] = 0;
    while (!q.empty()) {
        int t = q.front();
        for (int i = 0; i < (int)edge[t].size(); i++)
            if (vis[edge[t][i]] == 0) {
                q.push(edge[t][i]);
                dist[edge[t][i]] = dist[t] + 1;
                vis[edge[t][i]] = 1;
            }
        q.pop();
    }
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int n, m;
    cin >> n >> m;
    string s[MAXN];
    for (int i = 0; i < n; i++)
        cin >> s[i];
    for (int x = 0; x < n; x++)
        for (int y = 0; y < m; y++) {
            for (int k = 0; k < 4; k++)
                if (inBoard(x + dx[k], y + dy[k], n, m) && s[x + dx[k]][y + dy[k]] != '#')
                    edge[x * m + y].push_back((x + dx[k]) * m + (y + dy[k]));
            if (s[x][y] == '1') {
                edge[x * m + y].push_back(n * m);
                edge[n * m].push_back(x * m + y);
            }
            if (s[x][y] == '2') {
                edge[x * m + y].push_back(n * m + 1);
                edge[n * m + 1].push_back(x * m + y);
            }
            if (s[x][y] == '3') {
                edge[x * m + y].push_back(n * m + 2);
                edge[n * m + 2].push_back(x * m + y);
            }
        }
    int dist1[MAXN], dist2[MAXN], dist3[MAXN];
    for (int i = 0; i < n * m + 3; i++)
        vis[i] = 0;
    for (int i = 0; i < n * m + 3; i++)
        dist1[i] = 100000000;
    bfs(n * m, dist1);
    for (int i = 0; i < n * m + 3; i++)
        vis[i] = 0;
    for (int i = 0; i < n * m + 3; i++)
        dist2[i] = 100000000;
    bfs(n * m + 1, dist2);
    for (int i = 0; i < n * m + 3; i++)
        vis[i] = 0;
    for (int i = 0; i < n * m + 3; i++)
        dist3[i] = 100000000;
    bfs(n * m + 2, dist3);
    int ans = 100000000;
    ans = min(ans, dist1[n * m + 1] + dist1[n * m + 2] - 6);
    ans = min(ans, dist2[n * m] + dist2[n * m + 2] - 6);
    ans = min(ans, dist3[n * m] + dist3[n * m + 1] - 6);
    for (int i = 0; i < n * m; i++)
        ans = min(ans, dist1[i] + dist2[i] + dist3[i] - 5);
    if (ans < 10000000)
        cout << ans << endl;
    else
        cout << -1;
    return 0;
}