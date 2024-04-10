#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long long ull;
const int maxn = (int)1e6 + 100;
const ll inf = (1ll<<60);
const int mod = (int)998244353;
const int mod2 = (int)1e9 + 7;
int n, m;
int a[maxn];
int prv[maxn];
int d[maxn];
int b[maxn];

struct bl {
    int L, R;
    vector < pair<int, int> > A;
    vector < pair<int, int> > B;
    int C;
    void update(int l, int r, int x) {
        for(int i = l; i <= r; i++) {
            a[i] -= x;
            if(a[i] < 0) a[i] = 0;
        }
        for(int i = 0; i < B.size(); i++) {
            if(l <= B[i].first && B[i].first <= r) {
                B[i].second -= x;
                prv[B[i].first] -= x;
            }
        }

        recalc();
    }
    void updateAll(int x) {

        for(int i = 0; i < B.size(); i++) {
            prv[B[i].first] -= x;
            B[i].second -= x;
        }
        C = min(C + x, R);
        recalc();
    }
    void recalc() {
        for(int i = 0; i < B.size(); i++) {
            if(B[i].second < L) {
                d[B[i].first] = 1;
                B.erase(B.begin() + i);
                i--;
                continue;
            }
        }
        for(int i = 0; i < B.size(); i++) {
            if(d[B[i].second]) {
                b[B[i].first] = B[i].first;
            } else {
                b[B[i].first] = b[B[i].second];
            }
        }
    }
} B[555];
int bl_size = 555;

int get_lca(int u, int v) {
    //cout << u << " " << v << "\n";
    
    if(u > v) swap(u, v);
    if(u <= 1) return 1;
    if(u == v) return u;

    if(!d[v]) {
        if(u/bl_size != v/bl_size) {
            return get_lca(u, prv[b[v]]);
        }
        if(d[u]) {
            return get_lca(u, prv[b[v]]);
        }
        if(b[v] == b[u]) {
            return get_lca(u, prv[v]);
        }
        return get_lca(u, prv[b[v]]);
    }
    return get_lca(u, a[v] - B[v/bl_size].C);
}
void solve() {
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        if(i == 1) {
            a[i] = 0;
        } else {
            cin >> a[i];
            prv[i] = a[i];
        }
        B[i/bl_size].B.push_back(make_pair(i, a[i]));
    }
    for(int i = n; i >= 1; i--) {
        B[i/bl_size].L = i;
    }
    for(int i = 1; i <= n; i++) {
        B[i/bl_size].R = i;
    }
    for(int i = 0; i * bl_size <= n; i++) {
        B[i].recalc();
    }
    for(int i = 0; i < m; i++) {
        int t;
        cin >> t;
        if(t == 1) {
            int l, r, x;
            cin >> l >> r >> x;
            int bl = l/bl_size;
            int br = r/bl_size;
            if(bl == br) {
                B[bl].update(l, r, x);
            } else {
                B[bl].update(l, bl * bl_size + bl_size - 1, x);
                for(int j = bl+1; j < br; j++) {
                    B[j].updateAll(x);
                }
                B[br].update(br * bl_size, r, x);
            }
        } else {
            int u, v;
            cin >> u >> v;
            cout << get_lca(u, v) << "\n";
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    //cin >> t;
    for(int i = 1; i <= t; i++) {
        solve();
    }
    return 0;
}