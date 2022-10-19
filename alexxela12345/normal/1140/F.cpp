#include <bits/stdc++.h>
#define _ << " " <<

using namespace std;
#define int long long

const int MAXN = 3e5 + 10;

namespace DSURollBack {
    vector<int> parent, rank;
    vector<int> cnt1, cnt2;
    int n;
    vector<pair<int *, int>> backups;
    int ans = 0;

    void init(int n_) {
        n = n_;
        parent.resize(2 * n);
        rank.resize(2 * n);
        cnt1.resize(2 * n);
        cnt2.resize(2 * n);
        for (int i = 0; i < 2 * n;i++) {
            parent[i] = i;
            rank[i] = 1;
            if (i < n) {
                cnt1[i] = 1;
            } else {
                cnt2[i] = 1;
            }
        }
    }

    int get(int a) {
        while (parent[a] != a) {
            a = parent[a];
        }
        return a;
    }

    void unite(int a, int b) {
        a = get(a);
        b = get(b);
        if (a == b)
            return;
        if (rank[a] < rank[b]) {
            swap(a, b);
        }
        backups.emplace_back(&parent[b], parent[b]);
        parent[b] = a;
        int new_ans = ans;
        new_ans -= cnt1[a] * cnt2[a];
        new_ans -= cnt1[b] * cnt2[b];
        backups.emplace_back(&cnt1[a], cnt1[a]);
        cnt1[a] += cnt1[b];
        backups.emplace_back(&cnt2[a], cnt2[a]);
        cnt2[a] += cnt2[b];
        backups.emplace_back(&cnt1[b], cnt1[b]);
        cnt1[b] = 0;
        backups.emplace_back(&cnt2[b], cnt2[b]);
        cnt2[b] = 0;
        new_ans += cnt1[a] * cnt2[a];
        backups.emplace_back(&ans, ans);
        ans = new_ans;
        if (rank[a] == rank[b]) {
            backups.emplace_back(&rank[a], rank[a]);
            rank[a]++;
        }
    }

    void backup(int to) {
        while (backups.size() > to) {
            *backups.back().first = backups.back().second;
            backups.pop_back();
        }
    }
}

namespace DCPOffline {
    int n;
    vector<int> answers;
    vector<vector<pair<int, int>>> t;

    void add(int v, int l, int r, int ql, int qr, pair<int, int> val) {
        if (r <= ql || qr <= l) {
            return;
        }
        if (ql <= l && r <= qr) {
            t[v].push_back(val);
        } else {
            int m = l + (r - l) / 2;
            add(2 * v + 1, l, m, ql, qr, val);
            add(2 * v + 2, m, r, ql, qr, val);
        }
    }

    void traverse(int v, int l, int r) {
        int was_backup = DSURollBack::backups.size();
        for (auto x : t[v]) {
            DSURollBack::unite(x.first, x.second);
        }
        if (l + 1 == r) {
            answers[l] = DSURollBack::ans;
        } else {
            int m = l + (r - l) / 2;
            traverse(2 * v + 1, l, m);
            traverse(2 * v + 2, m, r);
        }
        DSURollBack::backup(was_backup);
    }

    void run() {
        DSURollBack::init(n);
        traverse(0, 0, n);
    }

    void init(int n_) {
        n = n_;
        answers.resize(n);
        t.resize(4 * n);
    }
}


signed main() {
#ifdef ONPC
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int q;
    cin >> q;
    DCPOffline::init(MAXN);
    set<pair<int, int>> edges;
    map<pair<int, int>, int> first_s;
    for (int i = 0; i < q; i++) {
        int x, y;
        cin >> x >> y;
        y += MAXN;
        if (edges.count({x, y})) {
            DCPOffline::add(0, 0, MAXN, first_s[pair<int, int> {x, y}], i, {x, y});
            edges.erase({x, y});
        } else {
            edges.insert({x, y});
        } 
        first_s[{x, y}] = i;
    }
    for (auto t : edges) {
        DCPOffline::add(0, 0, MAXN, first_s[t], q, t);
    }
    DCPOffline::run();
    for (int i = 0; i < q; i++) {
        cout << DCPOffline::answers[i] << " ";
    }
    cout << endl;
}