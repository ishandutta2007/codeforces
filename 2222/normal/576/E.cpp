#include <bits/stdc++.h>

using namespace std;

int n, m, K, Q;

struct history_node {
    int* ptr;
    int value;
    void rollback() { *ptr = value; }
};

vector<history_node> history;

void put(int &x, int value) {
    if (x != value) {
        history.push_back({&x, x});
        x = value;
    }
}

void rollback(int time) {
    for (; history.size() > time; ) {
        history.back().rollback();
        history.pop_back();
    }
}

struct graph {
    vector<int> p;

    graph() : p(n, -1) {}

    int cc(int &x) {
        int color = 0;
        for (; p[x] >= 0; x = p[x] / 2)
            color ^= p[x];
        return color & 1;
    }

    bool add_edge(int x, int y) {
        int c = cc(x) ^ cc(y);
        if (x == y) return c;
        if (p[x] < p[y]) swap(x, y);
        put(p[y], p[x] + p[y]);
        put(p[x], y * 2 + 1 - c);
        return true;
    }
};

vector<graph> G;
int edges[500000][3];
int queries[500000][2];
int mark[500000], now;

void down(int l0, int h0, int l1, int h1) {
    ++now;
    for (int i = l0; i < h0; ++i)
        mark[queries[i][0]] = now;
    for (int i = l1; i < h1; ++i) {
        int j = queries[i][0];
        if (mark[j] != now) {
            mark[j] = now;
            auto edge = edges[j];
            if (edge[2] >= 0)
                G[edge[2]].add_edge(edge[0], edge[1]);
        }
    }
};

void solve(int lo, int hi) {
    if (lo + 1 == hi) {
        auto query = queries[lo];
        auto edge = edges[query[0]];
        if (G[query[1]].add_edge(edge[0], edge[1])) {
            edge[2] = query[1];
            puts("YES");
        } else {
            puts("NO");
        }
        return;
    }
    int time = history.size(), mid = (lo + hi) / 2;
    down(lo, mid, mid, hi);
    solve(lo, mid);
    rollback(time);
    down(mid, hi, lo, mid);
    solve(mid, hi);
    rollback(time);
}

int main() {
    scanf("%d%d%d%d", &n, &m, &K, &Q);
    G.resize(K);
    for (int i = 0; i < m; ++i) {
        scanf("%d%d", edges[i], edges[i] + 1);
        --edges[i][0];
        --edges[i][1];
        --edges[i][2];
    }
    for (int i = 0; i < Q; ++i) {
        scanf("%d%d", queries[i], queries[i] + 1);
        --queries[i][0];
        --queries[i][1];
    }
    solve(0, Q);
    return 0;
}