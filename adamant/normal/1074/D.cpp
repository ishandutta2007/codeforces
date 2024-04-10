#include <bits/stdc++.h>

using namespace std;
#define all(x) begin(x), end(x)
#define rall(x) (x).rbegin(), (x).rend()
#define int int64_t

const int maxn = 2e5 + 42;
const int inf = 1e9;

void solve() {
    int n;
    cin >> n;
    vector<int> g[n];
    for(int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        g[a - 1].push_back(b - 1);
        g[b - 1].push_back(a - 1);
    }
    int k1, k2;
    cin >> k1;
    int x[k1];
    for(int i = 0; i < k1; i++) {
        cin >> x[i];
    }
    cin >> k2;
    int y[k2];
    for(int i = 0; i < k2; i++) {
        cin >> y[i];
    }
    
}

map<int, vector<int>> elems;
map<int, int> xr, par, sz;

int get(int v) {
    if(!par.count(v)) {
        elems[v] = {v};
        sz[v] = 1;
        return par[v] = v;
    } else if(v == par[v]) {
        return v;
    } else {
        return par[v] = get(par[v]);
    }
}



void upd(int l, int r, int x) {
    r++;
    int L = get(l);
    int R = get(r);
    if(L != R) {
        if(elems[L].size() > elems[R].size()) {
            swap(L, R);
        }
        par[L] = R;
        int to_xor = xr[l] ^ x ^ xr[r];
        for(auto it: elems[L]) {
            elems[R].push_back(it);
            xr[it] ^= to_xor;
        }
        elems[L].clear();
    }
}

int get(int l, int r) {
    r++;
    if(get(l) == get(r)) {
        return xr[l] ^ xr[r];
    } else {
        return -1;
    }
}


signed main() {
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int q;
    cin >> q;
    int last = 0;
    while(q--) {
        int t;
        cin >> t;
        if(t == 1) {
            int l, r, x;
            cin >> l >> r >> x;
            l ^= last;
            r ^= last;
            x ^= last;
            if(l > r) {
                swap(l, r);
            }
            upd(l, r, x);
        } else {
            int l, r;
            cin >> l >> r;
            l ^= last;
            r ^= last;
            if(l > r) {
                swap(l, r);
            }
            last = get(l, r);
            cout << last << "\n";
            last = abs(last);
        }
    }
    /*
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
    * */
    return 0;
}