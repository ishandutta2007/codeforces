#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;

template <typename K, typename V = __gnu_pbds::null_type>
using tree = __gnu_pbds::tree<K, V, less<K>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;
using llong = long long;
auto isz = [](const auto& c) { return int(c.size());};

mt19937 rng((size_t) make_shared<char>().get());

int hibit(int n) {
    n |= (n >>  1);
    n |= (n >>  2);
    n |= (n >>  4);
    n |= (n >>  8);
    n |= (n >> 16);
    return n - (n >> 1);
}

int ls[555555];
int rs[555555];
int c[555555];
int ans[555555];

vector<int> a[555555];

void add(int x, vector<int>& v) {
    int i = 0;
    for (; i < isz(v) && x; i++) {
        int t = hibit(x) - hibit(v[i]);
        if (t < 0) {
            continue;
        }
        if (t > 0) {
            break;
        }
        x ^= v[i];
    }
    if (x) {
        v.insert(begin(v) + i, x);
    }
}

void go(int l, int r, vector<int>& ids) {
    int m = (l + r) >> 1;
    for (int i = m - 1; i >= l; i--) {
        a[i].clear();
        if (i + 1 < m) {
            a[i] = a[i + 1];
        }
        add(c[i], a[i]);
    }
    for (int i = m; i < r; i++) {
        a[i].clear();
        if (i > m) {
            a[i] = a[i - 1];
        }
        add(c[i], a[i]);
    }

    vector<int> gl, gr;
    for (int id : ids) {
        int l = ls[id];
        int r = rs[id];
        if (r < m) {
            gl.push_back(id);
        } else if (l > m) {
            gr.push_back(id);
        } else {
            vector<int> t;
            if (l < m) {
                for (int i : a[l]) {
                    add(i, t);
                }
            }
            if (r > m) {
                for (int i : a[r - 1]) {
                    add(i, t);
                }
            }
            int ca = 0;
            for (int i : t) {
                int h = hibit(i);
                if ((ca & h) == 0) {
                    ca ^= i;
                }
            }
            ans[id] = ca;
        }
    }

    if (isz(gl)) {
        go(l, m, gl);
    }
    if (isz(gr)) {
        go(m, r, gr);
    }
}

int main() {
#ifdef VSE
    freopen("input.txt", "r", stdin);
    rng.seed(0);
#endif
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> c[i];
    }

    int q;
    cin >> q;
    for (int iq = 0; iq < q; iq++) {
        cin >> ls[iq] >> rs[iq];
        ls[iq]--;
    }

    vector<int> ids(q);
    iota(begin(ids), end(ids), 0);

    go(0, n, ids);

    for (int i = 0; i < q; i++) {
        cout << ans[i] << "\n";
    }

    return 0;
}//ugfoag