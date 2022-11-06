#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>

using namespace std;

#define mp make_pair
#define pb push_back
#define ll long long

#define inf 1000000000
#define maxN 222

const int def = 100;
const int maxi = 10000000;

struct plant {
    int a, b, c, l, r;

    int f(int x) {
        return a * x * x + b * x + c;
    }
};

class Flow {
    public:
        int dim;
        int S, D;
        vector< vector<int> > C, F, list;
        vector<int> prov;
        queue<int> Q;
        int total;

        void init(int _dim, int _S, int _D) {
            dim = _dim; S = _S; D = _D;
            dim += 5;
            total = 0;

            list = vector< vector<int> >(dim, vector<int>(0, 0));
            C = F = vector< vector<int> >(dim, vector<int>(dim, 0));
            prov = vector<int>(dim, 0);
        }

        void add_edge(int x, int y, int cap) {
            list[x].pb(y);
            list[y].pb(x);
            C[x][y] = C[y][x] = cap;
            F[x][y] = F[y][x] = 0;
        }

        void add_dir_edge(int x, int y, int cap) {
            list[x].pb(y);
            list[y].pb(x);
            C[x][y] = cap;
            F[x][y] = F[y][x] = 0;
        }

        bool bellman() {
            int i;

            for (i = 0; i < dim; i++) prov[i] = 0;
            prov[S] = S;
            Q.push(S);

            while (!Q.empty()) {
                int node = Q.front(); Q.pop();

                if (node == D) continue;
                for (int to : list[node]) {
                    if (prov[to]) continue;
                    if (F[node][to] == C[node][to]) continue;

                    prov[to] = node;
                    Q.push(to);
                }
            }

            if (prov[D] == 0) return false;

            for (int to : list[D]) {
                if (prov[to] == 0) continue;

                int flow = inf;
                prov[D] = to;

                for (int node = D; node != S; node = prov[node])
                    flow = min(flow, C[prov[node]][node] - F[prov[node]][node]);

                for (int node = D; node != S; node = prov[node]) {
                    F[prov[node]][node] += flow;
                    F[node][prov[node]] -= flow;
                }

                total += flow;
            }

            return true;
        }

        void start_process() {
            while (bellman());
        }


};

int n, m, i, j, u, v, d, cnt, need, S, D;
plant P[maxN];
int id[maxN][maxN];
Flow F;


int main()
{
    //freopen("test.in","r",stdin);

    scanf("%d%d", &n, &m);
    for (i = 1; i <= n; i++) scanf("%d%d%d", &P[i].a, &P[i].b, &P[i].c);
    for (i = 1; i <= n; i++) scanf("%d%d", &P[i].l, &P[i].r), need += P[i].r - P[i].l + 2;

    need += 2;
    S = ++cnt; D = ++cnt;
    F.init(need, S, D);

    for (i = 1; i <= n; i++) {
        for (j = def + P[i].l; j <= def + P[i].r + 1; j++) id[i][j] = ++cnt;
        F.add_dir_edge(S, id[i][def + P[i].l], inf);
        F.add_dir_edge(id[i][def + P[i].r + 1], D, inf);
        for (j = def + P[i].l; j <= def + P[i].r; j++)
            F.add_dir_edge(id[i][j], id[i][j + 1], maxi - P[i].f(j - def));
    }

    for (i = 1; i <= m; i++) {
        scanf("%d%d%d", &u, &v, &d);

        for (j = P[u].l; j <= P[u].r; j++) {
            int to = j - d;
            to = max(to, P[v].l);
            to = min(to, P[v].r + 1);

            F.add_dir_edge(id[u][def + j], id[v][def + to], inf);
        }
    }

    F.start_process();
    cout << maxi * n - F.total;




    return 0;
}