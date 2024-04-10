#include <bits/stdc++.h>

using namespace std;

#define int int64_t
#define all(x) begin(x), end(x)

const int mod = 998244353;
const int maxn = 2e5 + 42;

int col[maxn], par[maxn];
vector<int> st[maxn];

void clear(int n) {
    for(int i = 0; i < n; i++) {
        st[i] = {i};
        par[i] = i;
        col[i] = 0;
    }
}

bool join(int a, int b, int c) {
    int df = col[a] != col[b];
    a = par[a];
    b = par[b];
    if(a == b) {
        return df == c;
    } else {
        if(st[a].size() < st[b].size()) {
            swap(a, b);
        } // st[b] < st[a]
        for(auto it: st[b]) {
            par[it] = a;
            col[it] ^= df ^ c;
        }
        st[a].insert(end(st[a]), begin(st[b]), end(st[b]));
        st[b].clear();
        return true;
    }
}

void solve() {
    int n, m;
    cin >> n >> m;
    clear(n);
    int x[n - 1], y[n - 1], v[n - 1];
    bool fail = false;
    for(int i = 0; i < n - 1; i++) {
        cin >> x[i] >> y[i] >> v[i];
        x[i]--, y[i]--;
        if(v[i] != -1) {
            fail |= !join(x[i], y[i], __builtin_popcount(v[i]) % 2);
        }
    }
    for(int i = 0; i < m; i++) {
        int a, b, p;
        cin >> a >> b >> p;
        a--, b--;
        fail |= !join(a, b, p);
    }
    if(fail) {
        cout << "NO" << "\n";
    } else {
        cout << "YES" << "\n";
        for(int i = 0; i < n - 1; i++) {
            cout << x[i] + 1 << ' ' << y[i] + 1 << ' ';
            if(v[i] == -1) {
                cout << (col[x[i]] != col[y[i]]) << "\n";
            } else {
                cout << v[i] << "\n";
            }
        }
    }
}

signed main() {
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}