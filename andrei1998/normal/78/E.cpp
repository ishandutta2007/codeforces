#include <iostream>
#include <string>
#include <cstdio>
#include <queue>
#include <utility>
#include <algorithm>
#include <cstring>

using namespace std;

template <const int NMAX, const int MMAX>
class MaxFLow {
public:
    MaxFLow() { m = 0; }

    inline void setN(int _n) { n = _n; }
    inline void setS(int _s) { s = _s; }
    inline void setT(int _t) { t = _t; }

	inline int getN() { return n; }
    inline int getS() { return s; }
    inline int getT() { return t; }

    void clear() {
        m = 0;
        for (int i = 1; i <= n; ++ i)
            graph[i].clear();
    }

    void reset() {
        for (int i = 0; i < m; ++ i)
            edges[i].flow = 0;
    }

    void addEdge(int from, int to, int cap) {
        edges[m ++] = Edge(from, to, 0, cap);
        edges[m ++] = Edge(to, from, 0, 0);

        //cout << "add " << from << ' ' << to << ' ' << cap << endl;

        graph[from].push_back(m - 2);
        graph[to].push_back(m - 1);
    }

    inline int computeFlow() {
        return Dinic();
    }

private:
    struct Edge {
        int from, to;
        int flow, cap;

        Edge(int _from = 0, int _to = 0, int _flow = 0, int _cap = 0):
            from(_from), to(_to), flow(_flow), cap(_cap) {}
        inline int other(int node) {
            return from ^ to ^ node;
        }
    };

    int n, m, s, t;

    vector <int> graph[NMAX];
    Edge edges[2 * MMAX];

    int father[NMAX];
    bool vis[NMAX];
    queue <int> _queue;

    bool bfs() {
        memset(vis, 0, (n + 1) * sizeof(bool));

        vis[s] = true;
        _queue.push(s);

        int node;
        while (!_queue.empty()) {
            node = _queue.front();
            _queue.pop();

            for (auto it: graph[node])
                if (!vis[edges[it].other(node)] && edges[it].flow < edges[it].cap) {
                    father[edges[it].other(node)] = it;
                    vis[edges[it].other(node)] = true;
                    _queue.push(edges[it].other(node));
                }
        }

        return vis[t];
    }

    int Dinic() {
        int flow = 0;
        while (bfs()) {
            for (auto it: graph[t])
                if (vis[edges[it ^ 1].other(t)] && edges[it ^ 1].flow < edges[it ^ 1].cap) {
                    int node = edges[it ^ 1].other(t);
                    int minimum = edges[it ^ 1].cap - edges[it ^ 1].flow;

                    while (node != s) {
                        minimum = min(minimum, edges[father[node]].cap - edges[father[node]].flow);
                        node = edges[father[node]].other(node);
                    }

                    node = edges[it ^ 1].other(t);
                    edges[it ^ 1].flow += minimum;
                    edges[it].flow -= minimum;
                    flow += minimum;

                    while (node != s) {
                        edges[father[node]].flow += minimum;
                        edges[father[node] ^ 1].flow -= minimum;

                        node = edges[father[node]].other(node);
                    }
                }
        }

        return flow;
    }
};

const int NMAX = 10 + 5;

int N, T;
string _sci[NMAX];
string _caps[NMAX];

bool blocked[NMAX][NMAX];
int sci[NMAX][NMAX];
int caps[NMAX][NMAX];

int infectDist[NMAX][NMAX];
bool infectVis[NMAX][NMAX];

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

void bfsInfest(int startLin, int startCol) {
    for (int i = 1; i <= N; ++ i)
        for (int j = 1; j <= N; ++ j)
            infectDist[i][j] = T + 100;

    queue <pair <int, int> > q;
    infectDist[startLin][startCol] = 0;
    q.push({startLin, startCol});
    infectVis[startLin][startCol] = true;

    pair <int, int> node;
    while (!q.empty()) {
        node = q.front();
        q.pop();

        for (int i = 0; i < 4; ++ i) {
            pair <int, int> newNode;
            newNode = {node.first + dx[i], node.second + dy[i]};

            if (newNode.first >= 1 && newNode.second >= 1 && newNode.first <= N && newNode.second <= N && !blocked[newNode.first][newNode.second] && !infectVis[newNode.first][newNode.second]) {
                infectDist[newNode.first][newNode.second] = infectDist[node.first][node.second] + 1;
                infectVis[newNode.first][newNode.second] = true;
                q.push(newNode);
            }
        }
    }
}

int capsNode[NMAX][NMAX];
int scientNode[NMAX][NMAX];
int nodes;

bool vis[NMAX][NMAX];
int dist[NMAX][NMAX];

void bfsScient(int startLin, int startCol) {
    for (int i = 1; i <= N; ++ i)
        for (int j = 1; j <= N; ++ j)
            vis[i][j] = false, dist[i][j] = T + 100;

    queue <pair <int, int> > q;
    q.push({startLin, startCol});
    vis[startLin][startCol] = true;
    dist[startLin][startCol] = 0;

    pair <int, int> node;
    while (!q.empty()) {
        node = q.front();
        q.pop();
        if (dist[node.first][node.second] >= infectDist[node.first][node.second])
            continue;


        for (int i = 0; i < 4; ++ i) {
            pair <int, int> newNode;
            newNode = {node.first + dx[i], node.second + dy[i]};

            if (newNode.first >= 1 && newNode.second >= 1 && newNode.first <= N && newNode.second <= N && !blocked[newNode.first][newNode.second] && !vis[newNode.first][newNode.second]) {
                vis[newNode.first][newNode.second] = true;
                dist[newNode.first][newNode.second] = dist[node.first][node.second] + 1;
                q.push(newNode);
            }
        }
    }
}

int main()
{
    //freopen("data.in", "r", stdin);

    cin >> N >> T;

    for (int i = 1; i <= N; ++ i) {
        cin >> _sci[i];
        _sci[i] = " " + _sci[i];
    }
    for (int i = 1; i <= N; ++ i) {
        cin >> _caps[i];
        _caps[i] = " " + _caps[i];
    }

    int startLin;
    int startCol;

    for (int i = 1; i <= N; ++ i)
        for (int j = 1; j <= N; ++ j)
            if (_sci[i][j] == 'Z')
                startLin = i, startCol = j;
            else if (_sci[i][j] == 'Y')
                blocked[i][j] = true;
            else {
                sci[i][j] = _sci[i][j] - '0';
                caps[i][j] = _caps[i][j] - '0';
            }

    bfsInfest(startLin, startCol);
    blocked[startLin][startCol] = true;

    /*for (int i = 1; i <= N; ++ i) {
        for (int j = 1; j <= N; ++ j)
            cout << infectDist[i][j] << ' ';
        cout << endl;
    }*/

    //Compute labels
    for (int i = 1; i <= N; ++ i)
        for (int j = 1; j <= N; ++ j)
            if (sci[i][j] > 0)
                scientNode[i][j] = ++ nodes;
    for (int i = 1; i <= N; ++ i)
        for (int j = 1; j <= N; ++ j)
            if (caps[i][j] > 0)
                capsNode[i][j] = ++ nodes;

    int source = ++ nodes;
    int dest = ++ nodes;

    MaxFLow <NMAX * NMAX, NMAX * NMAX * NMAX * NMAX> f;

    f.setN(nodes);
    f.setS(source);
    f.setT(dest);

    for (int i = 1; i <= N; ++ i)
        for (int j = 1; j <= N; ++ j)
            if (sci[i][j] > 0)
                f.addEdge(f.getS(), scientNode[i][j], sci[i][j]);
    for (int i = 1; i <= N; ++ i)
        for (int j = 1; j <= N; ++ j)
            if (caps[i][j] > 0)
                f.addEdge(capsNode[i][j], f.getT(), caps[i][j]);

    for (int i = 1; i <= N; ++ i)
        for (int j = 1; j <= N; ++ j)
            if (sci[i][j]) {

                //cout << "try " << i << ' ' << j << endl;

                bfsScient(i, j);

                /*for (int k = 1; k <= N; ++ k) {
                    for (int l = 1; l <= N; ++ l)
                        cout << dist[k][l] << ' ';
                    cout << endl;
                }
                cout << endl;
                cout << endl;
                cout << endl;*/

                for (int k = 1; k <= N; ++ k)
                    for (int l = 1; l <= N; ++ l)
                        if (caps[k][l] && dist[k][l] <= T && dist[k][l] <= infectDist[k][l]) {
                            f.addEdge(scientNode[i][j], capsNode[k][l], 10000000);
                            //cout << "de la " << i << ' ' << j << " la " << k << ' ' << l << endl;
                            //cout << "avem " << dist[k][l] << " si infectia " << ' ' << infectDist[k][l] << endl;
                            //cout << endl;
                        }
            }

    cout << f.computeFlow() << '\n';
    return 0;
}