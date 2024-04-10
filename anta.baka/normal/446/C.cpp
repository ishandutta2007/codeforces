#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int mod = 1e9 + 9;
const int Q = 276601605;
const int A = 691504013;
const int B = 308495997;

struct segTree {
    int n, q;
    struct node {
        int k, add, sum;
    };
    vector<node> t;
    vector<int> sums, elem;
    segTree(int n, int q) : n(n), q(q), t(4 * n, {0, 0, 0}), sums(n + 1), elem(n + 1) {
        elem[0] = 1;
        for(int i = 1; i < n + 1; i++) elem[i] = (ll)elem[i - 1] * q % mod;
        sums[0] = elem[0];
        for(int i = 1; i < n + 1; i++) sums[i] = (sums[i - 1] + elem[i]) % mod;
    }
    void push(int v, int l, int r) {
        int x = t[v].add;
        if(!x) return;
        t[v].add = 0;
        int m = (l + r) >> 1;
        t[v * 2 + 1].add = (t[v * 2 + 1].add + x) % mod;
        t[v * 2 + 1].k = (t[v * 2 + 1].k + x) % mod;
        t[v * 2 + 1].sum = (t[v * 2 + 1].sum + (ll)x * sums[m - l]) % mod;
        t[v * 2 + 2].add = (t[v * 2 + 2].add + (ll)x * elem[m - l + 1]) % mod;
        t[v * 2 + 2].k = (t[v * 2 + 2].k + (ll)x * elem[m - l + 1]) % mod;
        t[v * 2 + 2].sum = (t[v * 2 + 2].sum + (ll)x * elem[m - l + 1] % mod * sums[r - m - 1]) % mod;
    }
    void upd(int v, int l, int r, int l1, int r1, int x) {
        if(r < l1 || r1 < l) return;
        if(l1 <= l && r <= r1) {
            x += l - l1;
            t[v].add = (t[v].add + elem[x]) % mod;
            t[v].k = (t[v].k + elem[x]) % mod;
            t[v].sum = (t[v].sum + (ll)elem[x] * sums[r - l]) % mod;
            return;
        }
        push(v, l, r);
        int m = (l + r) >> 1;
        upd(v * 2 + 1, l, m, l1, r1, x);
        upd(v * 2 + 2, m + 1, r, l1, r1, x);
        t[v].sum = (t[v * 2 + 1].sum + t[v * 2 + 2].sum) % mod;
    }
    int get(int v, int l, int r, int l1, int r1) {
        if(r1 < l || r < l1) return 0;
        if(l1 <= l && r <= r1) return t[v].sum;
        push(v, l, r);
        int m = (l + r) >> 1;
        return (get(v * 2 + 1, l, m, l1, r1) + get(v * 2 + 2, m + 1, r, l1, r1)) % mod;
    }
};

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, q; cin >> n >> q;
    vector<int> a(n), p(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    p[0] = a[0];
    for(int i = 1; i < n; i++) p[i] = (p[i - 1] + a[i]) % mod;
    segTree t1(n, A), t2(n, B);
    while(q--) {
        int type, l, r; cin >> type >> l >> r; l--; r--;
        if(type == 1) {
            t1.upd(0, 0, n - 1, l, r, 1);
            t2.upd(0, 0, n - 1, l, r, 1);
        } else {
            cout << (p[r] - (l ? p[l - 1] : 0) + (ll)Q * (t1.get(0, 0, n - 1, l, r) - t2.get(0, 0, n - 1, l, r) + mod)) % mod << '\n';
        }
    }
}