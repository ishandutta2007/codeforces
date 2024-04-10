#include <iostream>
#include <queue>
#include <vector>

using namespace std;

const int NMAX = 100000 + 5;

int n, m;
vector <int> graph[NMAX];
int h[NMAX];

//LCA
int euler[2 * NMAX];
int euler_sz;
int euler_first[NMAX];

void dfs_euler(int node, int father) {
    euler[++ euler_sz] = node;
    euler_first[node] = euler_sz;

    for (auto it: graph[node])
        if (it != father) {
            h[it] = 1 + h[node];
            dfs_euler(it, node);
            euler[++ euler_sz] = node;
        }
}

int dp[18][2 * NMAX];
int logar[2 * NMAX];

void precalc() {
    for (int i = 2; i <= euler_sz; ++ i)
        logar[i] = 1 + logar[i >> 1];

    for (int i = 1; i <= euler_sz; ++ i)
        dp[0][i] = euler[i];

    for (int i = 1; (1 << i) <= euler_sz; ++ i)
        for (int j = 1; j + (1 << i) - 1 <= euler_sz; ++ j)
            if (h[dp[i - 1][j]] < h[dp[i - 1][j + (1 << (i - 1))]])
                dp[i][j] = dp[i - 1][j];
            else
                dp[i][j] = dp[i - 1][j + (1 << (i - 1))];
}

int lca(int a, int b) {
    if (!a)
        return b;
    if (!b)
        return a;

    a = euler_first[a];
    b = euler_first[b];

    if (b < a)
        swap(a, b);
    int y = logar[b - a + 1];

    if (h[dp[y][a]] < h[dp[y][b - (1 << y) + 1]])
        return dp[y][a];
    return dp[y][b - (1 << y) + 1];
}

bool red[NMAX];

int dist[NMAX];
queue <int> q;

void bfs() {
    for (int i = 1; i <= n; ++ i)
        if (!red[i])
            dist[i] = 2 * NMAX;
        else {
            dist[i] = 0;
            q.push(i);
        }

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        for (auto it: graph[node])
            if (dist[node] + 1 < dist[it]) {
                dist[it] = dist[node] + 1;
                q.push(it);
            }
    }
}

const int RAD = 440;

vector <int> buffer;

void dischargeBuffer() {
    buffer.clear();
    bfs();
}

int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;

    for (int i = 1; i < n; ++ i) {
        int a, b;
        cin >> a >> b;

        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    dfs_euler(1, 0);
    precalc();

    buffer = {1};
    red[1] = true;

    for (int i = 1; i <= n; ++ i)
        dist[i] = 2 * NMAX;

    for (int i = 1; i <= m; ++ i) {
        int type, node;
        cin >> type >> node;

        if (type == 1) {
            red[node] = true;
            buffer.push_back(node);

            if (buffer.size() > RAD)
                dischargeBuffer();
        }
        else {
            int best = dist[node];

            for (auto it: buffer) {
                int dst = h[node] + h[it] - 2 * h[lca(node, it)];
                best = min(best, dst);
            }

            cout << best << '\n';
        }
    }

    return 0;
}