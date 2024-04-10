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
    cout << setprecision(16) << fixed;
    cerr << setprecision(16) << fixed;
 
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

class Tree {
public:
    Tree() {}
    Tree(int n) : n(n) {
        arr.resize(4 * n);
        pr.resize(4 * n);
        build(0, 0, n);
    }

    void update(int lf, int rg, int val) {
        update(0, 0, n, lf, rg, val);
    }

    pii get() {
        pii res = get(0);
        res.second *= -1;
        return res;
    }
private:

    pii get(int v) {
        return {arr[v].first + pr[v], arr[v].second};
    }

    void push(int v) {
        pr[2 * v + 1] += pr[v];
        pr[2 * v + 2] += pr[v];
        arr[v].first += pr[v];
        pr[v] = 0;
    }

    void build(int v, int l, int r) {
        if (l + 1 == r) {
            arr[v] = {0, -l};
            return;
        }
        int m = (l + r) / 2;
        build(2 * v + 1, l, m);
        build(2 * v + 2, m, r);

        arr[v] = min(arr[2 * v + 1], arr[2 * v + 2]);
    }

    void update(int v, int l, int r, int lf, int rg, int val) {
        if (lf <= l && r <= rg) {
            pr[v] += val;
            return;
        }
        if (rg <= l || r <= lf) {
            return;
        }
        push(v);
        int m = (l + r) / 2;
        update(2 * v + 1, l, m, lf, rg, val);
        update(2 * v + 2, m, r, lf, rg, val);
        arr[v] = min(get(2 * v + 1), get(2 * v + 2));
    }

    int n;
    vector<pii> arr;
    vector<int> pr;
};

class BIT {
public:
    BIT(int n) {
        arr.resize(n);
    }
    
    void add(int pos, int val) {
        for (int i = pos; i < sz(arr); i |= i + 1) {
            arr[i] += val;
        }
    }

    int sum(int pos) {
        int res = 0;
        for (int i = pos; i >= 0; i = (i & (i + 1)) - 1) {
            res += arr[i];
        }
        return res;
    }

private:
    vector<int> arr;
};

struct Query {
    int x, y;
    int id;
};

void solve() {
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for (int &x : a) {
        cin >> x;
        --x;
    }

    int inf = 1e8;

    Tree tree(n);    
    for (int i = 0; i < n; ++i) {
        if (i - a[i] >= 0) {
            tree.update(i, i + 1, i - a[i]);
        } else {
            tree.update(i, i + 1, inf);
        }
    }

    vector<vector<int>> d(n);

    int minn = n;

    for (int i = 0; i < n; ++i) {
        auto [val, p] = tree.get();
        // cerr << p << " " << val << endl;
        if (val != 0) {
            break;
        }
        minn = min(minn, p);
        d[minn].push_back(p);

        tree.update(p + 1, n, -1);
        tree.update(p, p + 1, inf);
    }

    vector<vector<Query>> arr(n);

    for (int i = 0; i < q; ++i) {
        Query que;
        cin >> que.x >> que.y;
        que.id = i;

        arr[que.x].push_back(que);
    }

    vector<int> res(q);
    BIT bit(n);
    for (int i = n - 1; i >= 0; --i) {
        for (int x : d[i]) {
            bit.add(x, 1);
        }

        for (auto [x, y, id] : arr[i]) {
            res[id] = bit.sum(n - y - 1) - bit.sum(x - 1);
        }
    }

    for (int i = 0; i < q; ++i) {
        cout << res[i] << "\n";
    }
}