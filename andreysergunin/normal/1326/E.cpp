#pragma GCC optimize("Ofast", "unroll-loops", "no-stack-protector")
 
#include <bits/stdc++.h>

using namespace std;

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()

using ll = long long;
using ld = long double;
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
    cout << setprecision(14) << fixed;
    cerr << setprecision(14) << fixed;

    int tests = 1;
    // cin >> tests;

    while (tests--) {
       solve();
    }

#ifdef LOCAL
    cerr << "Time: " << double(clock()) / CLOCKS_PER_SEC << endl;
#endif
}

// ----------------------------------------------------------------- 

const int INF = 1e9;

class SegmentTree {
public:
    SegmentTree() {}
    SegmentTree(int n) : n(n) {
        arr.resize(4 * n);
        sum.resize(4 * n);
        maxx.resize(4 * n);
    }

    void build(vector<int> &a) {
        build(0, 0, n, a);
    }

    void update(int pos, int val1, int val2) {
        update(0, 0, n, pos, val1, val2);
    }

    int get() {
        return get(0, 0, n);
    }

    pii get(int l, int r) {
        return get(0, 0, n, l, r);
    }

private:
    void build(int v, int lf, int rg, vector<int> &a) {
        if (lf + 1 == rg) {
            maxx[v] = {a[lf], lf};
            return;
        }
        int mid = (lf + rg) / 2;
        build(2 * v + 1, lf, mid, a);
        build(2 * v + 2, mid, rg, a);
        maxx[v] = max(maxx[2 * v + 1], maxx[2 * v + 2]);
    }

    void update(int v, int lf, int rg, int pos, int val1, int val2) {
        if (lf + 1 == rg) {
            sum[v] += val1;
            arr[v] += val1;
            maxx[v].first += val2;
            return;
        }
        int mid = (lf + rg) / 2;
        if (pos < mid) {
            update(2 * v + 1, lf, mid, pos, val1, val2);
        } else {
            update(2 * v + 2, mid, rg, pos, val1, val2);
        }

        maxx[v] = max(maxx[2 * v + 1], maxx[2 * v + 2]);
        
        arr[v] = min(arr[2 * v + 1], sum[2 * v + 1] + arr[2 * v + 2]);
        sum[v] = sum[2 * v + 1] + sum[2 * v + 2];
    }

    int get(int v, int lf, int rg, int s = 0) {
        if (s + arr[v] >= 0) {
            return -1;
        }
        if (lf + 1 == rg) {
            return lf;
        }
        int mid = (lf + rg) / 2;
        int res = get(2 * v + 1, lf, mid, s);
        if (res == -1) {
            return get(2 * v + 2, mid, rg, s + sum[2 * v + 1]);
        } 
        return res;
    }

    pii get(int v, int lf, int rg, int l, int r) {
        if (l <= lf && rg <= r) {
            return maxx[v];
        }
        if (rg <= l || r <= lf) {
            return {-INF, 0};
        }
        int mid = (lf + rg) / 2;
        pii p = get(2 * v + 1, lf, mid, l, r);
        pii q = get(2 * v + 2, mid, rg, l, r);
        return max(p, q);
    }

    int n;
    vector<int> arr;
    vector<int> sum;
    vector<pii> maxx;
};

void solve() {      
    int n;  
    cin >> n;
    vector<int> p(n);
    for (int i = 0; i < n; ++i) {
        cin >> p[i];
        --p[i];
    }
    vector<int> q(n);
    for (int i = 0; i < n; ++i) {
        cin >> q[i];
        --q[i];
    }

    SegmentTree tree(n);
    tree.build(p);

    vector<int> res(n);
    res[0] = n;

    set<int> setik;
    for (int i = 0; i < n; ++i) {
        setik.insert(i);
    }

    for (int i = 0; i < n - 1; ++i) {
        tree.update(q[i], -1, 0);
        int pos = tree.get();
        // cerr << pos << endl;
        pii pr = tree.get(0, pos + 1);
        // cerr << pr.first << " " << pr.second << endl;
        tree.update(pr.second, 1, -INF);
        setik.erase(pr.first);
        res[i + 1] = *setik.rbegin() + 1;
    }

    for (int x : res) {
        cout << x << " ";
    }
    cout << "\n";
}