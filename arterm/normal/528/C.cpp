#include <bits/stdc++.h>

using namespace std;

const int M = 100100;

pair<int, int> operator +(const pair<int, int> &x, const pair<int, int> &y) {
    return make_pair(x.first ^ y.first, x.second ^ y.second);
}

pair<int, int> ZERO(0, 0), ONE(1, 1), ZO(0, 1), OZ(1, 0);

int n;
pair<int, int> a[M];
vector<pair<int, int>> e;
vector<int> g[M];
bool used[M];

void flipEdge(int no) {
    int x = e[no].first, y = e[no].second;
    a[x] = a[x] + ONE;
    a[y] = a[y] + ONE;
    swap(e[no].first, e[no].second);
}

void addEdge(int x, int y) {
    e.emplace_back(x, y);
    a[x].first ^= 1;
    a[y].second ^= 1;
}

void read() {
    int m;
    cin >> n >> m;
    for (int i = 0, x, y; i < m; ++i) {
        cin >> x >> y;
        addEdge(x, y);
    }
}

void pre() {
    vector<int> bad;
    for (int i = 1; i <= n; ++i)
        if (a[i] == ZO || a[i] == OZ)
            bad.push_back(i);

    assert(bad.size() % 2 == 0);
    for (int i = 0; i < (int) bad.size(); i += 2) {
        addEdge(bad[i], bad[i + 1]);
    }

    vector<int> one;
    for (int i = 1; i <= n; ++i)
        if (a[i] == ONE)
            one.push_back(i);

    if (one.size() % 2 == 1) {
        addEdge(one[0], one[0]);
    }
}

void build() {
    for (int i = 0; i < (int) e.size(); ++i) {
        g[e[i].first].push_back(i);
        g[e[i].second].push_back(i);
    }
}

void dfs(int v, int from = -1) {
    used[v] = true;

    for (auto no : g[v]) {
        int to = e[no].first ^ e[no].second ^ v;
        if (used[to])
            continue;
        if (v != e[no].first)
            flipEdge(no);

        dfs(to, no);
        assert(a[to] == ZERO);
    }

    if (a[v] == ONE)
        flipEdge(from);
}

void finish() {
    cout << e.size() << "\n";
    for (auto d : e) {
        cout << d.first << " " << d.second << "\n";
    }
}

void print() {
    for (int i = 1; i <= n; ++i) {
        cerr << i << ": (" << a[i].first << ", " << a[i].second << ")\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    read();
    pre();
    build();
    //print();
    dfs(1);
    //print();
    finish();
    return 0;
}