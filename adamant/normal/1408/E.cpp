#include <bits/stdc++.h>

using namespace std;

#define int int64_t
const int maxn = 3e5 + 42;

int par[maxn];

int get(int v) {
    return v == par[v] ? v : par[v] = get(par[v]);
}
bool add_edge(int a, int b) {
    a = get(a);
    b = get(b);
    par[a] = b;
    return a != b;
}

void solve() {
    iota(par, par + maxn, 0);
    int m, n;
    cin >> m >> n;
    int a[m], b[n], s[m];
    vector<int> A[m];
    for(int i = 0; i < m; i++) {
        cin >> a[i];
    }
    for(int j = 0; j < n; j++) {
        cin >> b[j];
    }
    vector<tuple<int, int, int>> E;
    int total = 0;
    for(int i = 0; i < m; i++) {
        cin >> s[i];
        A[i].resize(s[i]);
        for(int j = 0; j < s[i]; j++) {
            cin >> A[i][j];
            int cost = a[i] + b[A[i][j] - 1];
            E.emplace_back(-cost, i, m + A[i][j] - 1);
            total += cost;
        }
    }
    sort(begin(E), end(E));
    for(auto it: E) {
        if(add_edge(get<1>(it), get<2>(it))) {
            total += get<0>(it);
        }
    }
    cout << total << "\n";
}

signed main() {
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    t = 1;//cin >> t;
    while(t--) {
        solve();
    }
}