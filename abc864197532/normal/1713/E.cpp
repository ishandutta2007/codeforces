#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define pii pair<int, int>
#define all(x) x.begin(), x.end()
void abc() {cout << endl;}
template <typename T, typename ...U> void abc(T i, U ...j) {
    cout << i << ' ', abc(j...);
}
template <typename T> void printv(T l, T r) {
    for (; l != r; ++l)
        cout << *l << " \n"[l + 1 == r];
}
#define test(x...) abc("[" + string(#x) + "]", x);
const int N = 100000;

struct Dsu {
    vector <int> rt, sz;
    int n, cc;
    Dsu () = default;
    Dsu (int _n) : n(_n), cc(_n) {
        rt.resize(n), iota(rt.begin(), rt.end(), 0);
        sz.assign(n, 1);
    }
    int Find(int v) {
        return rt[v] == v ? v : rt[v] = Find(rt[v]);
    }
    bool Union(int v, int u) {
        u = Find(u), v = Find(v);
        if (u == v)
            return false;
        if (sz[u] > sz[v])
            swap(u, v);
        rt[u] = v;
        sz[v] += sz[u];
        cc--;
        return true;
    }
    bool same(int u, int v) {
        return Find(u) == Find(v);
    }
};

void solve() {
    int n;
    cin >> n;
    vector <vector <int>> a(n, vector <int> (n));
    for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j)
        cin >> a[i][j];
    Dsu dsu(n * 2);
    for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) if (i < j) {
        if (a[i][j] > a[j][i]) {
            if (dsu.same(i * 2, j * 2)) {
                continue;
            }
            dsu.Union(i * 2, j * 2 + 1);
            dsu.Union(i * 2 + 1, j * 2);
        }
        if (a[i][j] < a[j][i]) {
            if (dsu.same(i * 2, j * 2 + 1)) {
                continue;
            }
            dsu.Union(i * 2, j * 2);
            dsu.Union(i * 2 + 1, j * 2 + 1);
        }
    }
    for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) if (i < j) {
        if (dsu.same(i * 2, j * 2 + 1))
            swap(a[i][j], a[j][i]);
    }
    for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) {
        cout << a[i][j] << " \n"[j == n - 1];
    }
}

int main () {
    ios::sync_with_stdio(false), cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}