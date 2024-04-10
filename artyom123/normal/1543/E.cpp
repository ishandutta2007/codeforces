 #include <bits/stdc++.h>

using namespace std;

#define pb emplace_back
#define all(x) (x).begin(), (x).end()
#define fi first
#define se second
#define pii pair<int, int>
#define puu pair<unsigned, unsigned>
#define ll long long 
#define mp make_pair

const long long INFLL = 1e18;
const int INF = 1e9 + 1;

vector<int> p, cur_mask, col, kek;

int IT = 0;

void solve(int i, vector<int> &a, vector<vector<int>> &g) {
    IT++;
    for (auto &c : a) cur_mask[c] = IT;
    if ((int)a.size() == 1) {
        p[0] = a[0];
        kek[a[0]] = 0;
        return;
    }
    for (auto &v : a) col[v] = -1;
    vector<int> b1, b2;
    queue<int> q;
    b1.pb(a[0]);
    for (auto &v : g[a[0]]) {
        if (cur_mask[v] == cur_mask[a[0]]) {
            b2.pb(v);
            break;
        }
    }
    q.push(b1[0]);
    q.push(b2[0]);
    col[b1[0]] = 0;
    col[b2[0]] = 1;
    while (q.size()) {
        int v = q.front();
        q.pop();
        for (auto &to : g[v]) {
            if (cur_mask[to] != cur_mask[v]) continue;
            if (col[to] != -1) continue;
            col[to] = col[v];
            q.push(to);
            if (col[to] == 0) b1.pb(to);
            else b2.pb(to);
        }
    }
    vector<pii> lol;
    for (auto &v : a) {
        for (auto &to : g[v]) {
            if (cur_mask[to] == cur_mask[v] && col[v] == 0 && col[to] == 1) {
                lol.pb(v, to);
            }
        }
    }
    solve(i - 1, b1, g);
    for (auto &c : lol) {
        kek[c.se] = kek[c.fi] ^ (1 << i);
        p[kek[c.se]] = c.se;
    }
}

int main() {
    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #else
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
    #endif
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int N = (1 << n);
        vector<vector<int>> g(N);
        p.assign(N, -1);
        cur_mask.assign(N, 0);
        col.assign(N, -1);
        kek.assign(N, -1);
        for (int i = 0; i < n * (1 << (n - 1)); i++) {
            int v, u;
            cin >> v >> u;
            g[v].pb(u);
            g[u].pb(v);
        }
        vector<int> a(N);
        iota(all(a), 0);
        solve(n - 1, a, g);
        for (auto &c : p) cout << c << " ";
        cout << "\n";
        if (N % n != 0) {
            cout << -1 << "\n";
            continue;
        }
        vector<int> ans(N);
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < n; j++) {
                if (i & (1 << j)) ans[p[i]] ^= j;
            }
        }
        for (auto &c : ans) cout << c << " ";
        cout << "\n";
    }
    return 0;
}