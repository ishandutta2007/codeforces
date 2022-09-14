#pragma GCC optimize("Ofast", "unroll-loops", "no-stack-protector")
 
#include <bits/stdc++.h>
 
using namespace std;

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()

using ll = long long;
using ld = long double; 
// using ld = __float128;
using pii = pair<int, int>;
using uint = unsigned int;
using ull = unsigned long long;

mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
default_random_engine generator;

void solve();

int main() {
#ifdef LOCAL
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);  
#endif 

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << setprecision(8) << fixed;
    cerr << setprecision(5) << fixed;

    int tests = 1;
    // cin >> tests;

    for (int test = 1; test <= tests; ++test) {
        // cout << "Case #" << test << ": ";
        solve();
    }

#ifdef LOCAL
    cerr << "Time: " << double(clock()) / CLOCKS_PER_SEC << endl;
#endif
}

// ----------------------------------------------------------------- 

class SegmentTree {
public:
    SegmentTree() {}
    SegmentTree(int n) : n(n) {
        arr.resize(4 * n);
        build(0, 0, n);
    }

    ll get(int lf, int rg) {
        return get(0, 0, n, lf, rg).sum;
    }

    void update(int pos) {
        update(0, 0, n, pos);
    }

private:
    struct Node {
        int lf, rg, len;
        ll sum; 
    };

    void build(int v, int l, int r) {
        arr[v].len = r - l;
        if (l + 1 == r) {
            return;
        }
        int m = (l + r) / 2;
        build(2 * v + 1, l, m);
        build(2 * v + 2, m, r);
    }

    Node merge(const Node &a, const Node &b) {
        Node c;
        c.lf = a.len == a.lf ? a.len + b.lf : a.lf;
        c.rg = b.len == b.rg ? b.len + a.rg : b.rg;
        c.len = a.len + b.len;
        c.sum = a.sum + b.sum + ll(a.rg) * b.lf;
        return c;
    }

    void update(int v, int l, int r, int pos) {
        if (l + 1 == r) {  
            arr[v] = {1, 1, 1, 1};
            return;
        }

        int m = (l + r) / 2;
        if (pos < m) {
            update(2 * v + 1, l, m, pos);
        } else {
            update(2 * v + 2, m, r, pos);
        }
        arr[v] = merge(arr[2 * v + 1], arr[2 * v + 2]);
    }

    Node get(int v, int l, int r, int lf, int rg) {
        if (lf <= l && r <= rg) {
            return arr[v];
        }
        if (rg <= l || r <= lf) {
            return Node{};
        }
        int m = (l + r) / 2;
        return merge(get(2 * v + 1, l, m, lf, rg), get(2 * v + 2, m, r, lf, rg));
    }


    int n;
    vector<Node> arr;
};


void solve() {    
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<int> len(n + 1);
    vector<vector<int>> pos(n + 1);
    for (int i = n - 1; i >= 0; --i) {
        len[i] = (s[i] == '0' ? 0 : len[i + 1] + 1);
        pos[len[i]].push_back(i);
    }

    ll res = 0;
    for (ll i = 0; i < n; ++i) {
        res += (i + 1) * (n - i);
    }

    SegmentTree tree(n);

    // for (int i = 0; i < n; ++i) {
    //     tree.update(i, 1);
    // }

    for (int i = 0; i < n; ++i) {
        for (int p : pos[i]) {
            tree.update(p);
        }
        // cerr << res << endl;
        res -= tree.get(0, n - i);
    }

    cout << res << endl;
}