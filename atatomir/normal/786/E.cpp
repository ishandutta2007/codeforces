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

#define maxN 20011
#define maxLog 16
#define maxNodes (maxN * maxLog)

struct edge {
    int from, to;
    int C, F;
    int rev;
};

int n, m, x, y, i;
vector< pair<int, int> > list[maxN];

int cnt, dim, S, D;
int lvl[maxN], dad[maxLog][maxN], id[maxLog][maxN], edge_id[maxN];
vector<edge> E;
vector<int> adj[maxNodes];

int flow;
bool us[maxNodes];
int prov[maxNodes];
queue<int> Q;

vector<int> citizen, guard;


void dfs(int node, int root) {
    for (auto to : list[node]) {
        if (to.first == root) continue;
        lvl[to.first] = lvl[node] + 1;
        dad[0][to.first] = node;
        edge_id[to.first] = to.second;
        dfs(to.first, node);
    }
}

void add_dir_edge(int A, int B, int cc = 1) {
    E.pb({A, B, cc, 0, dim + 1});
    adj[A].pb(dim);

    E.pb({B, A, 0, 0, dim});
    adj[B].pb(dim + 1);

    dim += 2;
}

void pre() {
    int i, j, daddy, son1, son2;

    lvl[1] = 1;
    dfs(1, 0);

    S = ++cnt;
    D = ++cnt;
    for (i = 1; i <= m; i++) {
        ++cnt;
        add_dir_edge(S, cnt);
    }

    for (i = 1; i <= n; i++) {
        id[0][i] = ++cnt;
        add_dir_edge(cnt, D);
    }
    for (i = 1; i < maxLog; i++) {
        for (j = 1; j <= n; j++) {
            dad[i][j] = dad[i - 1][ dad[i - 1][j] ];
            id[i][j] = ++cnt;
        }
    }

    for (i = 1; i < maxLog; i++) {
        for (j = 1; j <= n; j++) {
            if (dad[i][j] == 0) continue;
            daddy = id[i][j];
            son1 = id[i - 1][j];
            son2 = id[i - 1][ dad[i - 1][j] ];

            add_dir_edge(daddy, son1, maxNodes);
            add_dir_edge(daddy, son2, maxNodes);
        }
    }


}

void add_restriction(int who, int n1, int n2) {
    int i, dif;

    if (lvl[n1] > lvl[n2]) swap(n1, n2);
    dif = lvl[n2] - lvl[n1];
    for (i = 0; dif > 0; dif >>= 1, i++) {
        if (dif & 1) {
            add_dir_edge(who + 2, id[i][n2]);
            n2 = dad[i][n2];
        }
    }

    if (n1 == n2) return;
    for (i = maxLog - 1; i >= 0; i--) {
        if (dad[i][n1] != dad[i][n2]) {
            add_dir_edge(who + 2, id[i][n1]);
            add_dir_edge(who + 2, id[i][n2]);
            n1 = dad[i][n1];
            n2 = dad[i][n2];
        }
    }

    add_dir_edge(who + 2, id[0][n1]);
    add_dir_edge(who + 2, id[0][n2]);
}

bool max_flow() {
    int i;

    memset(us, 0, sizeof(us));
    while (!Q.empty()) Q.pop();

    us[S] = true;
    Q.push(S);

    while (!Q.empty()) {
        int node = Q.front(); Q.pop();
        if (node == D) continue;

        for (auto e : adj[node]) {
            if (E[e].C == E[e].F) continue;
            if (us[E[e].to]) continue;

            us[E[e].to] = true;
            prov[E[e].to] = e;
            Q.push(E[e].to);
        }
    }

    if (!us[D]) return false;

    for (auto e : adj[D]) {
        if (!us[E[e].to]) continue;
        prov[D] = E[e].rev;

        int act = 1;
        for (int node = D; node != S; node = E[prov[node]].from)
            act = min(act, E[prov[node]].C - E[prov[node]].F);

        if (act == 0) continue;
        flow++;

        for (int node = D; node != S; node = E[prov[node]].from) {
            E[prov[node]].F++;
            E[ E[prov[node]].rev ].F--;
        }
    }

    return true;
}

void dfs(int node) {
    us[node] = true;

    for (auto e : adj[node]) {
        if (E[e].C == E[e].F) continue;
        if (us[E[e].to]) continue;
        dfs(E[e].to);
    }
}

int main()
{
    //freopen("test.in","r",stdin);

    scanf("%d%d", &n, &m);
    for (i = 1; i < n; i++) {
        scanf("%d%d", &x, &y);
        list[x].pb(mp(y, i));
        list[y].pb(mp(x, i));
    }

    pre();

    for (i = 1; i <= m; i++) {
        scanf("%d%d", &x, &y);
        add_restriction(i, x, y);
    }

    while (max_flow());

    memset(us, 0, sizeof(us));
    dfs(S);

    for (i = 1; i <= m; i++)
        if (!us[i + 2])
            citizen.pb(i);

    for (i = 1; i <= n; i++)
        if (us[ id[0][i] ])
            guard.pb(edge_id[i]);

    sort(guard.begin(), guard.end());

    printf("%d\n", flow);

    printf("%d ", citizen.size());
    for (auto e : citizen)
        printf("%d ", e);
    printf("\n");

    printf("%d ", guard.size());
    for (auto e : guard)
        printf("%d ", e);
    printf("\n");

    return 0;
}