#include <iostream>
#include <algorithm>
#include <cstdio>
#include <string>
#include <vector>

using namespace std;

const int NMAX = 10 + 1;
const int MMAX = 100000 + 5;

int N, M;
int mat[NMAX][MMAX];

struct Node {
    int st, dr;
    int internal;
    int comps[NMAX][2];
} tree[8 * MMAX];

vector <int> graph[3 * NMAX];

void addEdge(int a, int b) {
    graph[a].push_back(b);
    graph[b].push_back(a);
}

int comps[3 * NMAX];
int currentComp;
void dfs(int node)  {
    comps[node] = currentComp;
    for (auto it: graph[node])
        if (!comps[it])
            dfs(it);
}

void unite(Node &res, const Node a, const Node &b) {
    if (a.st == -1) {
        res = b;
        return ;
    }

    for (int i = 1; i <= 3 * N; ++ i)
        graph[i].clear(), comps[i] = 0;

    //Node a
    int last[2 * NMAX] = {0};
    for (int i = 1; i <= N; ++ i) {
        if (last[a.comps[i][0]])
            addEdge(i, last[a.comps[i][0]]);
        last[a.comps[i][0]] = i;
    }
    for (int i = 1; i <= N; ++ i) {
        if (last[a.comps[i][1]])
            addEdge(N + i, last[a.comps[i][1]]);
        last[a.comps[i][1]] = N + i;
    }
    //Node b
    for (int i = 1; i <= 2 * N; ++ i)
        last[i] = 0;
    for (int i = 1; i <= N; ++ i) {
        if (last[b.comps[i][0]])
            addEdge(N + i, last[b.comps[i][0]]);
        last[b.comps[i][0]] = N + i;
    }
    for (int i = 1; i <= N; ++ i) {
        if (last[b.comps[i][1]])
            addEdge(2 * N + i, last[b.comps[i][1]]);
        last[b.comps[i][1]] = 2 * N + i;
    }

    //Final dfs left
    currentComp = 0;
    for (int i = 1; i <= N; ++ i) {
        if (!comps[i]) {
            ++ currentComp;
            dfs(i);
        }
        res.comps[i][0] = comps[i];
    }

    //Final dfs right
    for (int i = 2 * N + 1; i <= 3 * N; ++ i) {
        if (!comps[i]) {
            ++ currentComp;
            dfs(i);
        }
        res.comps[i - 2 * N][1] = comps[i];
    }

    //Final dfs middle
    res.internal = a.internal + b.internal;
    for (int i = N + 1; i <= 2 * N; ++ i)
        if (!comps[i]) {
            ++ currentComp;
            dfs(i);
            ++ res.internal;
        }
    res.st = a.st;
    res.dr = b.dr;
}

const int dx[2] = {0, 1};
const int dy[2] = {1, 0};

int where[MMAX];
void build(int node, int st, int dr) {
    tree[node].st = st, tree[node].dr = dr;

    if (dr - st <= 1) {
        for (int i = 1; i <= 2 * N; ++ i)
            graph[i].clear(), comps[i] = 0;

        int nd = 1;
        for (int j = st; j <= dr; ++ j)
            for (int i = 1; i <= N; ++ i, ++ nd)
                for (int k = 0; k < 2; ++ k) {
                    int lin = i + dx[k];
                    int col = j + dy[k];

                    if (lin >= 1 && lin <= N && col >= st && col <= dr && mat[i][j] == mat[lin][col])
                        addEdge(nd, (col - st) * N + lin);
                }

        currentComp = 0;
        for (int i = 1; i <= N; ++ i) {
            if (!comps[i]) {
                ++ currentComp;
                dfs(i);
            }
            tree[node].comps[i][0] = comps[i];
            if (st == dr)
                tree[node].comps[i][1] = comps[i];
        }

        if (st < dr) {
            for (int i = N + 1; i <= 2 * N; ++ i) {
                if (!comps[i]) {
                    ++ currentComp;
                    dfs(i);
                }
                tree[node].comps[i - N][1] = comps[i];
            }
        }

        if (st < dr) {
            build(node << 1, st, st);
            build((node << 1) + 1, dr, dr);
        }

        if (st == dr)
            where[st] = node;
        return ;
    }

    int mid = (st + dr) >> 1;

    build(node << 1, st, mid);
    build((node << 1) + 1, mid, dr);

    unite(tree[node], tree[node << 1], tree[(node << 1) + 1]);
}

Node ans;
void query(int node, int st, int dr) {
    if (tree[node].st == st && tree[node].dr == dr) {
        unite(ans, ans, tree[node]);
        return ;
    }

    int mid = (tree[node].st + tree[node].dr) >> 1;

    if (dr <= mid)
        query(node << 1, st, dr);
    else if (st >= mid)
        query((node << 1) + 1, st, dr);
    else {
        query(node << 1, st, mid);
        query((node << 1) + 1, mid, dr);
    }
}

int main()
{
    //freopen("data.in", "r", stdin);
    ios_base :: sync_with_stdio(false);
    cin.tie(0);

    int Q;
    cin >> N >> M >> Q;
    for (int i = 1; i <= N; ++ i)
        for (int j = 1; j <= M; ++ j)
            cin >> mat[i][j];
    build(1, 1, M);

    while (Q --) {
        int st, dr;
        cin >> st >> dr;

        if (st < dr) {
            ans.st = -1;
            query(1, st, dr);
        }
        else
            ans = tree[where[st]];
        int res = ans.internal;

        vector <int> v;
        for (int i = 1; i <= N; ++ i) {
            v.push_back(ans.comps[i][0]);
            v.push_back(ans.comps[i][1]);
        }

        sort(v.begin(), v.end());
        v.resize(unique(v.begin(), v.end()) - v.begin());

        cout << res + v.size() << '\n';
    }

    return 0;
}