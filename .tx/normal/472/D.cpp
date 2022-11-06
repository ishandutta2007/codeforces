#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int N = 2000;

int a[N][N];
int n;

struct Item {
    int i, j, v;

    Item(int i, int j, int v) : i(i), j(j), v(v) {
    }

    bool operator<(const Item &r) const {
        return v < r.v;
    }
};

struct Dsu {
    vector<int> a;

    void init(int n) {
        a.resize(n);
        for (int i = 0; i < n; i++) {
            a[i] = i;
        }
    }

    int get(int x) {
        return x == a[x] ? x : (a[x] = get(a[x]));
    }

    void unite(int x, int y) {
        x = get(x);
        y = get(y);
        if (rand() & 1) {
            a[x] = y;
        } else {
            a[y] = x;
        }
    }
};

bool dfs(int v, int p, int d, int i, vector<vector<int> > &g) {
    if (a[i][v] != d) {
        return false;
    }
    for (auto j : g[v]) {
        if (j != p) {
            if (!dfs(j, v, d + a[v][j], i, g)) {
                return false;
            }
        }
    }
    return true;
}

void solve() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }
    vector<Item> b;

    for (int i = 0; i < n; i++) {
        if (a[i][i] != 0) {
            cout << "NO";
            return;
        }
        for (int j = i + 1; j < n; j++) {
            if (a[i][j] != a[j][i] || a[i][j] == 0) {
                cout << "NO";
                return;
            }
            b.push_back(Item(i, j, a[i][j]));
        }
    }

    sort(b.begin(), b.end());
    Dsu a;
    a.init(n);
    vector<vector<int> > g(n, vector<int>());
    for (auto i : b) {
        if (a.get(i.i) != a.get(i.j)) {
            a.unite(i.i, i.j);
            g[i.i].push_back(i.j);
            g[i.j].push_back(i.i);
        }
    }

    for (int i = 0; i < n; i++) {
        if (!dfs(i, -1, 0, i, g)) {
            cout << "NO";
            return;
        }
    }
    cout << "YES";

}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}