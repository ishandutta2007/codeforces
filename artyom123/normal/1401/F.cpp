#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define pb emplace_back
#define ll long long
#define pii pair<int, int>
#define ld long double

const int INF = 2e9 + 1;
const int mod = 1e9 + 7;
const int MAXC = 1e6 + 10;

int xo = 0, L = 0;

struct segment_tree{
    vector<ll> t;

    void build(int v, int vl, int vr, vector<int> &a) {
        if (vr - vl == 1) {
            t[v] = a[vl];
            return;
        }
        int vm = (vl + vr) / 2;
        build(2 * v + 1, vl, vm, a);
        build(2 * v + 2, vm, vr, a);
        t[v] = t[2 * v + 1] + t[2 * v + 2];
    }

    segment_tree(){}

    segment_tree(vector<int> &a) {
        int n = a.size();
        t.resize(4 * n);
        build(0, 0, n, a);
    }

    void mod(int v, int vl, int vr, int ind, int val) {
        if (vr - vl == 1) {
            t[v] = val;
            return;
        }
        int vm = (vl + vr) / 2;
        if (ind < vm) mod(2 * v + 1, vl, vm, ind, val);
        else mod(2 * v + 2, vm, vr, ind, val);
        t[v] = t[2 * v + 1] + t[2 * v + 2];
    }

    ll get(int v, int vl, int vr, int l, int r, int depth) {
        if (vr <= l || vl >= r) return 0;
        if (vl >= l && vr <= r) {
            return t[v];
        }
        int vm = (vl + vr) / 2;
        bool is_swapped = (xo & (1 << (L - depth - 1)));
        if (!is_swapped) return get(2 * v + 1, vl, vm, l, r, depth + 1) + get(2 * v + 2, vm, vr, l, r, depth + 1);
        else return get(2 * v + 1, vm, vr, l, r, depth + 1) + get(2 * v + 2, vl, vm, l, r, depth + 1);
    }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int q;
    cin >> L >> q;
    int n = (1 << L);
    vector<int> a(n);
    for (auto &c : a) cin >> c;
    segment_tree t(a);
    while (q--) {
        int ty;
        cin >> ty;
        if (ty == 2) {
            int k;
            cin >> k;
            xo ^= (1 << k) - 1;
        }
        if (ty == 3) {
            int k;
            cin >> k;
            xo ^= (1 << k);
        }
        if (ty == 1) {
            int i, val;
            cin >> i >> val;
            i = (i - 1) ^ xo;
            t.mod(0, 0, n, i, val);
        }
        if (ty == 4) {
            int l, r;
            cin >> l >> r;
            cout << t.get(0, 0, n, l - 1, r, 0) << "\n";
        }
    }
    return 0;
}