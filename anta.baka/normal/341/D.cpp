#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define sz(a) (int)((a).size())
#define all(a) (a).begin(), (a).end()

struct fenwick {
    int n, m;
    vector<vector<ll>> t;
    fenwick(int n, int m) : n(n), m(m), t(n, vector<ll>(m, 0)) {}
    void upd(int ii, int jj, ll x) {
        for(int i = ii; i < n; i |= i + 1)
            for(int j = jj; j < m; j |= j + 1)
                t[i][j] ^= x;
    }
    ll get(int ii, int jj) {
        ll x = 0;
        for(int i = ii; i >= 0; i = (i & (i + 1)) - 1)
            for(int j = jj; j >= 0; j = (j & (j + 1)) - 1)
                x ^= t[i][j];
        return x;
    }
};

ll get(int i, int j, vector<vector<fenwick>> &t) {
    if(i == -1 || j == -1) return 0;
    return t[i & 1][j & 1].get(i, j);
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    //freopen("in.txt", "r", stdin);
    int n, q; cin >> n >> q;
    vector<vector<fenwick>> t(2, vector<fenwick>(2, fenwick(n, n)));
    while(q--) {
        int type, i1, j1, i2, j2;
        cin >> type >> i1 >> j1 >> i2 >> j2;
        i1--; j1--; i2--; j2--;
        if(type == 1) {
            cout << (get(i2, j2, t) ^ get(i1 - 1, j2, t) ^ get(i2, j1 - 1, t) ^ get(i1 - 1, j1 - 1, t)) << '\n';
        } else {
            ll x; cin >> x;
            t[i1 & 1][j1 & 1].upd(i1, j1, x);
            t[(i2 + 1) & 1][j1 & 1].upd(i2 + 1, j1, x);
            t[i1 & 1][(j2 + 1) & 1].upd(i1, j2 + 1, x);
            t[(i2 + 1) & 1][(j2 + 1) & 1].upd(i2 + 1, j2 + 1, x);
        }
    }
}