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
    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);  
#endif 

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << setprecision(12) << fixed;
    cerr << setprecision(12) << fixed;

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

const int MAXN = 200200;
const int MAXS = 2000;

class SegmentTree {
public:
    SegmentTree(int n) : n(n) {
        sum.resize(4 * n);
        left.resize(4 * n);
        pr.resize(4 * n);
    }

    void update(int pos, int val) {
        int lf = fnd(0, 0, n, val);
        if (lf <= pos) {
            update(0, 0, n, lf, pos + 1, val);
        }
    }

    int solve(int pos, ll val) { 
        pos = max(pos, fnd(0, 0, n, val));
        // cerr << pos << endl;
        if (pos == n) {
            return 0;
        }
        int cur = get(0, 0, n, pos);
        int len = min(val / cur, ll(n) - pos);
        assert(len > 0);

        val -= get(0, 0, n, pos, pos + len);
        assert(val >= 0);

        return len + solve(pos + len, val);
    }

    int get(int pos) {
        return get(0, 0, n, pos);
    }

private:

    void push(int v, int l, int r) {
        if (pr[v] == 0) {
            return;
        }
        left[v] = pr[v];
        sum[v] = ll(r - l) * pr[v];
        if (l + 1 != r) {
            pr[2 * v + 1] = pr[v];
            pr[2 * v + 2] = pr[v];
        }
        pr[v] = 0;
    }

    ll get(int v, int l, int r, int lf, int rg) {
        push(v, l, r);
        if (r <= lf || rg <= l) {
            return 0;
        }
        if (lf <= l && r <= rg) {
            return sum[v];
        }
        int m = (l + r) / 2;
        return get(2 * v + 1, l, m, lf, rg) + get(2 * v + 2, m, r, lf, rg);
    }

    int fnd(int v, int l, int r, int val) {
        push(v, l, r);
        if (l + 1 == r) {
            return (left[v] <= val ? l : r) ;
        }
        int m = (l + r) / 2;
        push(2 * v + 2, m, r);
        if (left[2 * v + 2] < val) {
            return fnd(2 * v + 1, l, m, val);
        } else {
            return fnd(2 * v + 2, m, r, val);
        }
    }

    void update(int v, int l, int r, int lf, int rg, int val) {
        push(v, l, r);
        if (r <= lf || rg <= l) {
            return;
        }
        if (lf <= l && r <= rg) {
            pr[v] = val;
            push(v, l, r);
            return;
        }
        int m = (l + r) / 2;
        update(2 * v + 1, l, m, lf, rg, val);
        update(2 * v + 2, m, r, lf, rg, val);
        left[v] = left[2 * v + 1];
        sum[v] = sum[2 * v + 1] + sum[2 * v + 2];
    }

    int get(int v, int l, int r, int pos) {
        push(v, l, r);
        if (l + 1 == r) {
            return sum[v];
        }
        int m = (l + r) / 2;
        if (pos < m) {
            return get(2 * v + 1, l, m, pos);
        }
        return get(2 * v + 2, m, r, pos);
    }

    int n;
    vector<ll> sum;
    vector<ll> pr;
    vector<int> left;
};

void solve() {  

    int n, m;
    cin >> n >> m;

    SegmentTree tree(n);

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        tree.update(i, a[i]);
    }
    // return;

    for (int i = 0; i < m; ++i) {
        int type, x, y;
        cin >> type >> x >> y;
        --x;

        if (type == 1) {    
            tree.update(x, y);
        } else {
            cout << tree.solve(x, y) << endl;
        }

        // for (int i = 0; i < n; ++i) {
        //     cout << tree.get(i) << " ";
        // }
        // cout << endl;
    }
}