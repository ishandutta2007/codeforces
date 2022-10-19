#include <bits/stdc++.h>

using namespace std;

const int N = 300005;

int n, m;
vector<pair<int, int>> segs[N];
int dp[N], pre[N];

int it[8 * N], lazy[8 * N];

void down(int k) {
    int id = lazy[k];
    if (id == 0) return;
    it[2 * k] = id;
    it[2 * k + 1] = id;
    lazy[2 * k] = id;
    lazy[2 * k + 1] = id;
    lazy[k] = 0;
}

void update(int k, int l, int r, int u, int v, int id) {
    if (l > v || r < u) return;
    if (l >= u && r <= v) {
        it[k] = id;
        lazy[k] = id;
        return;
    }
    down(k);
    int mid = (l + r) / 2;
    update(2 * k, l, mid, u, v, id);
    update(2 * k + 1, mid + 1, r, u, v, id);
    if (dp[it[2 * k]] > dp[it[2 * k + 1]]) it[k] = it[2 * k];
    else it[k] = it[2 * k + 1];
}

int get(int k, int l, int r, int u, int v) {
    if (l > v || r < u) return 0;
    if (l >= u && r <= v) return it[k];
    down(k);
    int mid = (l + r) / 2;
    int id1 = get(2 * k, l, mid, u, v);
    int id2 = get(2 * k + 1, mid + 1, r, u, v);
    return (dp[id1] > dp[id2] ? id1 : id2);
}

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(0);

    cin >> n >> m;
    set<int> s;
    for (int i = 1; i <= m; i++) {
        int id, l, r;
        cin >> id >> l >> r;
        s.insert(l);
        s.insert(r);
        segs[id].push_back(make_pair(l, r));
    }

    map<int, int> comp;
    int curr = 1;
    for (int e : s) {
        comp[e] = curr++;
    }
    for (int i = 1; i <= n; i++) {
        for (auto &e : segs[i]) {
            int u = comp[e.first];
            int v = comp[e.second];
            e = make_pair(u, v);
        }
    }

    for (int i = 1; i <= n; i++) {
        if (segs[i].size() == 0) continue;
        int mx = 0;
        int id = 0;
        for (auto e : segs[i]) {
            int idd = get(1, 1, 2 * m, e.first, e.second);
            if (mx < dp[idd]) {
                mx = dp[idd];
                id = idd;
            }
        }
        dp[i] = mx + 1;
        pre[i] = id;
        for (auto e : segs[i]) {
            update(1, 1, 2 * m, e.first, e.second, i);
        }
    }

    int id = 0;
    int mx = 0;
    for (int i = 1; i <= n; i++) {
        if (dp[i] > mx) {
            mx = dp[i];
            id = i;
        }
    }

    vector<bool> check(n + 1);
    while (id != 0) {
        check[id] = true;
        id = pre[id];
    }

    vector<int> res;
    for (int i = 1; i <= n; i++) {
        if (!check[i]) res.push_back(i);
    }
    assert(res.size() + mx == n);
    cout << res.size() << '\n';
    for (int e : res)
        cout << e << ' ';
    cout << '\n';

    return 0;
}