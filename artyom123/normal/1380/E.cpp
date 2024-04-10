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

vector<int> p;

int get_par(int v) {
    if (v == p[v]) return v;
    return p[v] = get_par(p[v]);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    p.resize(m);
    vector<vector<int>> kek(m);
    vector<int> tower(n);
    iota(all(p), 0);
    int ans = n - 1;
    for (int i = 0; i < n; i++) {
        cin >> tower[i];
        tower[i]--;
        ans -= (i > 0 && tower[i] == tower[i - 1]);
        kek[tower[i]].pb(i);
    }
    cout << ans << "\n";
    for (int i = 0; i < m - 1; i++) {
        int a, b;
        cin >> a >> b; a--; b--;
        a = get_par(a); b = get_par(b);
        if (kek[a].size() < kek[b].size()) swap(a, b);
        for (auto &c : kek[b]) {
            if (c > 0) ans -= tower[c - 1] == a;
            if (c < n - 1) ans -= tower[c + 1] == a;
        }
        for (auto &c : kek[b]) {
            kek[a].pb(c);
            tower[c] = a;
        }
        p[b] = a;
        cout << ans << "\n";
    }
    return 0;
}