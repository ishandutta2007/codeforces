#include <iostream>
#include <vector>
#include <cstring>
#include <queue>

using namespace std;

//15:25
const int NMAX = 205;
const int MMAX = 1005;

vector <int> graph[NMAX];

//Maxflow
int n, m, s, t;
int cap[NMAX][NMAX];
int flow[NMAX][NMAX];

queue <int> _queue;
bool vis[NMAX];
int father[NMAX];

bool bfs() {
    memset(father, 0, sizeof father);
    memset(vis, 0, sizeof vis);

    _queue.push(s);
    vis[s] = true;
    father[s] = -1;

    int node;
    while (!_queue.empty()) {
        node = _queue.front();
        _queue.pop();

        for (auto it: graph[node])
            if (cap[node][it] - flow[node][it] && !vis[it]) {
                father[it] = node;
                vis[it] = true;
                _queue.push(it);
            }
    }

    return vis[t];
}

int dinic() {
    memset(flow, 0, sizeof flow);

    int ans = 0;
    while (bfs())
        for (int i = 1; i <= n; ++ i)
            if (cap[i][t] - flow[i][t] && vis[i]) {
                int node = i;
                int f = cap[i][t] - flow[i][t];

                while (node != s) {
                    f = min(f, cap[father[node]][node] - flow[father[node]][node]);
                    node = father[node];
                }

                flow[i][t] += f;
                flow[t][i] -= f;
                node = i;

                ans += f;

                while (node != s) {
                    flow[father[node]][node] += f;
                    flow[node][father[node]] -= f;

                    node = father[node];
                }
            }

    return ans;
}

//Gomory-Hu tree
vector <int> tree[NMAX];
int all_cuts[NMAX][NMAX];
int _father[NMAX];

int det_tree() {
    for (int i = 1; i <= n; ++ i)
        for (int j = 1; j <= n; ++ j)
            all_cuts[i][j] = 1e9;

    for (int i = 2; i <= n; ++ i)
        _father[i] = 1;

    int sum = 0;
    for (int i = 2; i <= n; ++ i) {
        //Flow
        s = i;
        t = _father[i];
        all_cuts[i][_father[i]] = all_cuts[_father[i]][i] = dinic();
        sum += all_cuts[i][_father[i]];

        tree[t].push_back(s);
        tree[s].push_back(t);

        for (int j = i + 1; j <= n; ++ j)
            if (vis[j] && _father[j] == t)
                _father[j] = i;

        for (int j = 1; j < i; ++ j)
            all_cuts[i][j] = all_cuts[j][i] = min(all_cuts[_father[i]][j], all_cuts[i][_father[i]]);
    }

    return sum;
}

vector <int> sol;

void dfs(int node, int father, int &minimum, int &minimum_a, int &minimum_b) {
    for (auto it: tree[node])
        if (it != father && !vis[it]) {
            if (all_cuts[it][node] < minimum) {
                minimum = all_cuts[it][node];
                minimum_a = node;
                minimum_b = it;
            }

            dfs(it, node, minimum, minimum_a, minimum_b);
        }
}

void get_sol(int node) {
    int minimum = 1e9;
    int minimum_a, minimum_b;
    dfs(node, 0, minimum, minimum_a, minimum_b);

    if (minimum == 1e9) {
        sol.push_back(node);
        return ;
    }

    vis[minimum_a] = true;
    get_sol(minimum_b);
    vis[minimum_a] = false;

    vis[minimum_b] = true;
    get_sol(minimum_a);
    vis[minimum_b] = false;
}



int main()
{
    cin >> n >> m;

    int a, b, c;
    for (int i = 1; i <= m; ++ i) {
        cin >> a >> b >> c;

        graph[a].push_back(b);
        graph[b].push_back(a);

        cap[a][b] += c;
        cap[b][a] += c;
    }

    cout << det_tree() << '\n';

    memset(vis, 0, sizeof vis);
    get_sol(1);
    for (int i = 0; i < sol.size(); ++ i)
        cout << sol[i] << " \n"[i + 1 == sol.size()];
    return 0;
}