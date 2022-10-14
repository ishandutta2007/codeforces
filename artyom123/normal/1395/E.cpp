#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define pb emplace_back
#define ll long long
#define pii pair<int, int>
#define ld long double

const int INF = 2e9 + 1;
const int mod = 1e9 + 7;

mt19937 gen(time(0));

int k;

int hashes[10][10];

int ans = 0, need = 0;

void gener(int x, int now) {
    if (x == k + 1) {
        //cout << now << " " << need << "\n";
        ans += (need == now);
        return;
    }
    for (int y = 1; y <= x; y++) {
        gener(x + 1, (now + hashes[x][y]) % mod);
    }
}

void solve() {
    int n, m;
    cin >> n >> m >> k;
    vector<vector<set<int>>> S(k + 1, vector<set<int>>(k + 1));
    vector<vector<pii>> g(n);
    for (int i = 0; i < m; i++) {
        int v, u, w;
        cin >> v >> u >> w; v--; u--;
        g[v].pb(w, u);
    }
    for (int i = 0; i < n; i++) {
        int deg = g[i].size();
        sort(all(g[i]));
        for (int j = 1; j <= deg; j++) {
            S[deg][j].insert(g[i][j - 1].se);
        }
    }
    vector<int> val(n);
    for (auto &c : val) {
        c = gen() % mod;
    }
    for (int x = 1; x <= k; x++) {
        for (int y = 1; y <= x; y++) {
            for (auto &c : S[x][y]) {
                hashes[x][y] += val[c];
                hashes[x][y] %= mod;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        need += val[i];
        need %= mod;
    }
    gener(1, 0);
    cout << ans;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    while (t--) {
        solve();
    }
    return 0;
}