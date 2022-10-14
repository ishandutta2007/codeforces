#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define pb emplace_back
#define all(x) (x).begin(), (x).end()

const int INF = 1e9 + 1;

vector<int> p;
vector<int> r;
vector<int> mn;
vector<int> mx;

int get_parent(int v) {
    if (p[v] == v) {
        return v;
    }
    return p[v] = get_parent(p[v]);
}

void merge(int v, int u) {
    v = get_parent(v);
    u = get_parent(u);
    if (v == u) return;
    if (r[v] < r[u]) swap(v, u);
    p[u] = v;
    mn[v] = min(mn[v], mn[u]);
    mx[v] = max(mx[v], mx[u]);
    if (r[v] == r[u]) r[v]++;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    p.resize(n);
    r.resize(n);
    mn.resize(n);
    mx.resize(n);
    for (int i = 0; i < n; i++) {
        p[i] = i;
        mn[i] = i;
        mx[i] = i;
    }
    while (m--) {
        int a, b;
        cin >> a >> b;
        merge(a - 1, b - 1);
    }
    int cur = -1;
    int ans = 0;
    vector<int> usd(n);
    for (int i = 0; i < n; i++) {
        if (usd[get_parent(i)]) continue;
        usd[get_parent(i)] = 1;
        if (i == cur + 1) {
            cur = mx[get_parent(i)];
            continue;
        }
        ans++;
        cur = max(cur, mx[get_parent(i)]);
    }
    cout << ans;
    return 0;
}