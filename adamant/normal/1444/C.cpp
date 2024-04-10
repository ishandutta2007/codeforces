#include <bits/stdc++.h>

using namespace std;

//#define int int64_t
#define all(x) begin(x), end(x)

const int maxn = 1e6 + 42;

int par[maxn], col[maxn];
int sz[maxn];
bool bip = true;

int get(int v) {
    return v == par[v] ? v : get(par[v]);
}
int getc(int v) {
    return v == par[v] ? col[v] : col[v] ^ getc(par[v]);
}

vector<tuple<int, int, int, int>> status;

void unbip(bool err) {
    status.emplace_back(0, bip, -1, -1);
    bip &= !err;
}

void hang(int a, int b, bool err) {
    status.emplace_back(1, a, b, col[b]);
    par[b] = a;
    sz[a] += sz[b];
    if(err) {
        col[b] ^= 1;
    }
}

void rollback() {
    int type = get<0>(status.back());
    if(type == 0) {
        bip = get<1>(status.back());
    } else {
        int a, b;
        b = get<2>(status.back());
        tie(type, a, b, col[b]) = status.back();
        sz[a] -= sz[b];
        par[b] = b;
    }
    status.pop_back();
}

bool bipartite() {
    return bip;
}

void uni(int a, int b) {
    int ca = getc(a);
    int cb = getc(b);
    a = get(a);
    b = get(b);
    if(sz[a] < sz[b]) {
        swap(a, b);
        swap(ca, cb);
    }
    if(a == b) {
        unbip(ca == cb);
    } else {
        hang(a, b, ca == cb);
    }
}


void solve() {
    iota(par, par + maxn, 0);
    fill(sz, sz + maxn, 1);
    int n, m, k;
    cin >> n >> m >> k;
    int c[n];
    for(int i = 0; i < n; i++) {
        cin >> c[i];
        c[i]--;
    }
    int a[m], b[m];
    map<int, map<int, vector<int>>> eds;
    for(int i = 0; i < m; i++) {
        cin >> a[i] >> b[i];
        a[i]--, b[i]--;
        eds[min(c[a[i]], c[b[i]])][max(c[a[i]], c[b[i]])].push_back(i);
    }
    int64_t ans = 1LL * k * (k - 1) / 2;
    set<int> bad;
    for(int i = 0; i < k; i++) {
        for(auto it: eds[i][i]) {
            uni(a[it], b[it]);
        }
        if(!bipartite()) {
            bad.insert(i);
            ans -= k - bad.size();
            for(auto it: eds[i][i]) {
                rollback();
            }
        }
    }
    for(int i = 0; i < k; i++) {
        if(!bad.count(i)) {
            bad.insert(i);
            for(auto it: eds[i]) {
                if(!bad.count(it.first)) {
                    for(auto jt: it.second) {
                        uni(a[jt], b[jt]);
                    }
                    if(!bipartite()) {
                        ans--;
                    }
                    for(auto jt: it.second) {
                        rollback();
                    }
                }
            }
        }
    }
    cout << ans << "\n";
}

signed main() {
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    t = 1; //cin >> t;
    while(t--) {
        solve();
    }
}