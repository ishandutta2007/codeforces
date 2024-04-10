#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#include <cstdlib>

using namespace std;

class InputReader {
    public:
        InputReader() {
            input_file = stdin;
            cursor = 0;
            fread(buffer, SIZE, 1, input_file);
        }
        InputReader(const char *file_name) {
            input_file = fopen(file_name, "r");
            cursor = 0;
            fread(buffer, SIZE, 1, input_file);
        }
        inline InputReader &operator >>(int &n) {
            while(buffer[cursor] < '0' || buffer[cursor] > '9') {
                advance();
            }
            n = 0;
            while('0' <= buffer[cursor] && buffer[cursor] <= '9') {
                n = n * 10 + buffer[cursor] - '0';
                advance();
            }
            return *this;
        }
    private:
        FILE *input_file;
        static const int SIZE = 1 << 17;
        int cursor;
        char buffer[SIZE];
        inline void advance() {
            ++ cursor;
            if(cursor == SIZE) {
                cursor = 0;
                fread(buffer, SIZE, 1, input_file);
            }
        }
};

const int NMAX = 1005;
const int MMAX = 30005;
const int INF = 2e9 + 15;

int n, m, s, t;
struct Edge {
    int a, b, w;
    bool tree = false;
    bool erased = false;
    Edge(int _a = 0, int _b = 0, int _w = 0):
        a(_a), b(_b), w(_w) {}

    inline int other(int node) {
        return (a ^ b ^ node);
    }
} edges[MMAX];

vector <int> graph[NMAX];

bool vis[NMAX];
void dfs_tree(int node) {
    vis[node] = true;
    for (auto it: graph[node])
        if (!vis[edges[it].other(node)]) {
            edges[it].tree = true;
            dfs_tree(edges[it].other(node));
        }
}

int det_cost(const vector <int> &v) {
    int ans = 0;
    for (auto it: v)
        ans += edges[it].w;
    return ans;
}

int father_edge[NMAX];
int h[NMAX];
int low[NMAX];

void dfs(int node) {
    vis[node] = true;
    low[node] = h[node];
    for (auto it: graph[node])
        if (!edges[it].erased) {
            if (!vis[edges[it].other(node)]) {
                father_edge[edges[it].other(node)] = it;
                h[edges[it].other(node)] = 1 + h[node];
                dfs(edges[it].other(node));

                if (low[edges[it].other(node)] < low[node])
                    low[node] = low[edges[it].other(node)];
            }
            else if (it != father_edge[node]) {
                if (h[edges[it].other(node)] < low[node])
                    low[node] = h[edges[it].other(node)];
            }
        }
}

bool fail;
vector <int> solve(int missing_edge_index) {
    vector <int> sol;
    sol.push_back(missing_edge_index);

    memset(vis, 0, (n + 1) * sizeof(bool));
    dfs(s);

    if (!vis[t])
        return sol;
    else {
        int node = t;
        int best_edge;
        int best_edge_cost = INF;

        while (node != s) {
            //Muchia e critica
            if (low[node] >= h[node]) {
                if (edges[father_edge[node]].w < best_edge_cost) {
                    best_edge = father_edge[node];
                    best_edge_cost = edges[father_edge[node]].w;
                }
            }
            node = edges[father_edge[node]].other(node);
        }

        if (best_edge_cost == INF)
            fail = true;
        else
            sol.push_back(best_edge);
    }

    return sol;
}

int main()
{
    //ios_base :: sync_with_stdio(false);
    InputReader cin;

    cin >> n >> m >> s >> t;
    for (int i = 1; i <= m; ++ i) {
        cin >> edges[i].a >> edges[i].b >> edges[i].w;
        graph[edges[i].a].push_back(i);
        graph[edges[i].b].push_back(i);
    }

    dfs_tree(s);

    if (!vis[t]) {
        cout << "0\n0\n\n";
        return 0;
    }

    //for (int i = 1; i <= m; ++ i)
    //    if (edges[i].tree)
    //        cout << edges[i].a << ' ' << edges[i].b << ' ' << edges[i].w << endl;

    vector <int> sol, aux;
    int sol_cost = 2e9 + 15, aux_cost;
    for (int i = 1; i <= m; ++ i)
        if (edges[i].tree) {
            fail = false;
            edges[i].erased = true;
            aux = solve(i);
            edges[i].erased = false;
            aux_cost = det_cost(aux);

            if (!fail && aux_cost < sol_cost) {
                sol = aux;
                sol_cost = aux_cost;
            }
        }

    if (sol_cost == INF)
        cout << "-1\n";
    else {
        cout << sol_cost << '\n';
        cout << sol.size() << '\n';
        for (int i = 0; i < sol.size(); ++ i)
            cout << sol[i] << " \n"[i + 1 == sol.size()];
    }
    return 0;
}