#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <tuple>

using namespace std;

struct Tree
{
    int N, log, cur_time;
    vector<vector<int>> G, anc;
    vector<pair<int, int>> edges;
    vector<vector<pair<int, int>>> all;
    vector<int> dep, be, en;
    vector<bool> dead;

    vector<int> cur_min;

    void build_tree(int root, int lo, int hi)
    {
        if (lo == hi) {
            cur_min[root] = all[lo].back().first;
            return;
        }

        int mid = (lo + hi) >> 1;
        build_tree(root << 1, lo, mid);
        build_tree(root << 1 | 1, mid + 1, hi);
        cur_min[root] = min(cur_min[root << 1], cur_min[root << 1 | 1]);
    }

    void get_all(int l, int r, int x, vector<int> &vec, int root, int lo, int hi)
    {
        if (hi < l || r < lo || cur_min[root] >= x) return;
        if (lo == hi) {
            while (all[lo].back().first < x) {
                int id = all[lo].back().second;
                all[lo].pop_back();
                if (!dead[id]) {
                    dead[id] = 1;
                    vec.push_back(id);
                }
            }
            cur_min[root] = all[lo].back().first;
            return;
        }

        int mid = (lo + hi) >> 1;
        get_all(l, r, x, vec, root << 1, lo, mid);
        get_all(l, r, x, vec, root << 1 | 1, mid + 1, hi);
        cur_min[root] = min(cur_min[root << 1], cur_min[root << 1 | 1]);
    }

    void dfs_init(int u)
    {
        be[u] = ++cur_time;
        for (int v : G[u]) if (v != anc[0][u]) {
            anc[0][v] = u;
            for (int i = 1; i < log; ++i) anc[i][v] = anc[i - 1][anc[i - 1][v]];
            dep[v] = dep[u] + 1;

            dfs_init(v);
        }
        en[u] = cur_time;
    }

    int get_lca(int u, int v)
    {
        if (dep[u] < dep[v]) swap(u, v);
        for (int j = log - 1; j >= 0; --j) if (dep[u] - (1 << j) >= dep[v]) u = anc[j][u];
        if (u == v) return u;
        for (int j = log - 1; j >= 0; --j) if (anc[j][u] != anc[j][v]) u = anc[j][u], v = anc[j][v];
        return anc[0][u];
    }

    void init(vector<pair<int, int>> _edges, vector<pair<int, int>> edges1)
    {
        edges = _edges;
        N = edges.size() + 1;
        log = __lg(N) + 1;
        G.resize(N + 1);
        anc.assign(log, vector<int>(N + 1, 0));
        dep.resize(N + 1);
        be.resize(N + 1);
        en.resize(N + 1);
        all.assign(N + 1, vector<pair<int, int>>(1, make_pair(N + 10, N)));
        dead.assign(N + 1, 0);
        cur_min.resize((N + 1) << 2);
        cur_time = 0;

        for (int i = 0; i < N - 1; ++i) {
            int u = edges[i].first, v = edges[i].second;
            G[u].push_back(v);
            G[v].push_back(u);
        }
        dep[1] = 0;
        dfs_init(1);

        // add queries
        vector<tuple<int, int, int, int>> queries(N - 1);
        for (int i = 0; i < N - 1; ++i) {
            int u = edges1[i].first, v = edges1[i].second;
            queries[i] = make_tuple(dep[get_lca(u, v)], u, v, i);
        }
        sort(queries.begin(), queries.end());
        reverse(queries.begin(), queries.end());

        for (auto &x : queries) {
            int h, u, v, id;
            tie(h, u, v, id) = x;
            // cerr << u << ' ' << v << ": " << id << endl;
            // cerr << be[u] << ' ' << be[v] << ": " << id << endl;
            all[be[u]].emplace_back(h, id);
            all[be[v]].emplace_back(h, id);
        }

        build_tree(1, 1, N);
    }

    vector<int> rem(vector<int> ids)
    {
        // cerr << "rem " << endl;
        vector<int> ans;
        for (int id : ids) {
            int u = edges[id].first, v = edges[id].second;
            if (u == anc[0][v]) swap(u, v);
            // cerr << "S" << u << ": " << endl;
            get_all(be[u], en[u], dep[u], ans, 1, 1, N);
        }
        sort(ans.begin(), ans.end());
        ans.erase(unique(ans.begin(), ans.end()), ans.end());
        return ans;
    }
} tree_blue, tree_red;

int main()
{
    int N;
    scanf("%d", &N);
    vector<pair<int, int>> edges_blue(N - 1), edges_red(N - 1);
    for (int i = 0; i < N - 1; ++i) {
        edges_blue[i].first = i + 2;
        scanf("%d", &edges_blue[i].second);
    }
    for (int i = 0; i < N - 1; ++i) {
        edges_red[i].first = i + 2;
        scanf("%d", &edges_red[i].second);
    }

    // cerr << "BLU" << endl;
    tree_blue.init(edges_blue, edges_red);
    // cerr << "RED" << endl;
    tree_red.init(edges_red, edges_blue);

    int idx; scanf("%d", &idx);
    vector<int> ids_blue(1, idx - 1), ids_red;
    tree_red.dead[idx - 1] = 1;
    while (true) {
        puts("Blue");
        for (int id : ids_blue) printf("%d ", id + 1);
        putchar('\n');
        ids_red = tree_blue.rem(ids_blue);
        if (ids_red.empty()) break;

        puts("Red");
        for (int id : ids_red) printf("%d ", id + 1);
        putchar('\n');
        ids_blue = tree_red.rem(ids_red);
        if (ids_blue.empty()) break;
    }
}