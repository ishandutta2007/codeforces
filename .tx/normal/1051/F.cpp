#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;

template <typename K, typename V = __gnu_pbds::null_type>
using tree = __gnu_pbds::tree<K, V, less<K>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;
using llong = long long;
auto isz = [](const auto& c) { return int(c.size());};

mt19937 rng((size_t) make_shared<char>().get());

vector<pair<int, int>> g[111111];
int up[111111][22];
llong sm[111111][22];
int tin[111111];
int tout[111111];
int timer = 0;

void dfs(int v, int p, int w) {
    tin[v] = timer++;
    up[v][0] = p;
    sm[v][0] = w;
    for (int i = 0; up[v][i] != -1; i++) {
        up[v][i + 1] = up[up[v][i]][i];
        sm[v][i + 1] = sm[v][i] + sm[up[v][i]][i];
    }

    for (auto [to, w] : g[v]) {
        if (to == p) {
            continue;
        }
        dfs(to, v, w);
    }

    tout[v] = timer++;
}

bool is_anc(int a, int c) {
    return tin[a] <= tin[c] && tout[a] >= tout[c];
}

int lca(int a, int b) {
    for (int i = 21; i >= 0; i--) {
        int x = up[a][i];
        if (x != -1 && !is_anc(x, b)) {
            a = x;
        }
    }
    if (!is_anc(a, b)) {
        a = up[a][0];
    }
    return a;
}

llong sum(int a, int c) {
    llong res = 0;
    for (int i = 21; i >= 0; i--) {
        int x = up[a][i];
        if (x != -1 && !is_anc(x, c)) {
            res += sm[a][i];
            a = x;
        }
    }
    if (!is_anc(a, c)) {
        res += sm[a][0];
    }
    return res;
}

llong dist(int a, int b) {
    int c = lca(a, b);
    return sum(a, c) + sum(b, c);
}

struct Dsu {
    vector<int> a;
    vector<int> r;

    Dsu(int n) {
        a.resize(n);
        r.resize(n);
        iota(begin(a), end(a), 0);
        fill(begin(r), end(r), 1);
    }

    int get(int x) {
        return x == a[x] ? x : a[x] = get(a[x]);
    }

    void unite(int x, int y) {
        x = get(x);
        y = get(y);
        if (x == y) {
            return;
        }
        if (r[x] < r[y]) {
            a[x] = y;
        } else {
            a[y] = x;
            if (r[x] == r[y]) {
                r[x]++;
            }
        }
    }
};

llong d[44][44];

int main(int argc, char** argv) {
#ifdef VSE
    if (argc > 1) freopen(argv[1], "r", stdin);
    rng.seed(0);
#endif
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int n, m;
    cin >> n >> m;
    Dsu dsu(n);
    map<int, int> nums;
    vector<int> by_num;
    for (int i = 0; i < 44; i++) {
        for (int j = 0; j < 44; j++) {
            if (i != j) {
                d[i][j] = 1e18;
            }
        }
    }

    for (int i = 0; i < m; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        --x; --y;
        if (dsu.get(x) == dsu.get(y)) {
            if (nums.find(x) == end(nums)) {
                nums[x] = isz(nums);
                by_num.push_back(x);
            }
            if (nums.find(y) == end(nums)) {
                nums[y] = isz(nums);
                by_num.push_back(y);
            }
            x = nums[x];
            y = nums[y];
            d[x][y] = d[y][x] = min(d[x][y], (llong) z);
        } else {
            dsu.unite(x, y);
            g[x].emplace_back(y, z);
            g[y].emplace_back(x, z);
        }
    }

    memset(up, -1, sizeof(int) * 111111 * 22);
    dfs(0, -1, 0);

    int t = isz(nums);
    for (int i = 0; i < t; i++) {
        for (int j = 0; j < t; j++) {
            int x = by_num[i];
            int y = by_num[j];
            d[i][j] = d[j][i] = min(d[i][j], dist(x, y));
        }
    }

    for (int k = 0; k < t; k++) {
        for (int i = 0; i < t; i++) {
            for (int j = 0; j < t; j++) {
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }

    int q;
    cin >> q;
    for (int iq = 0; iq < q; iq++) {
        int x, y;
        cin >> x >> y;
        --x; --y;
        llong ans = dist(x, y);
        vector<llong> d1(t), d2(t);
        for (int i = 0; i < t; i++) {
            d1[i] = dist(x, by_num[i]);
            d2[i] = dist(by_num[i], y);
        }

        for (int i = 0; i < t; i++) {
            for (int j = 0; j < t; j++) {
                llong cd = d1[i] + d[i][j] + d2[j];
                ans = min(ans, cd);
            }
        }

        cout << ans << "\n";
    }

    return 0;
}//fbepxq