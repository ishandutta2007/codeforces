#include <bits/stdc++.h>

using namespace std;

template <typename T>
class segtree {
   private:
    int n, sz, h;
    vector<T> node, lazy;
    void eval(int k) {
        if (lazy[k]) {
            node[k] += lazy[k];
            if (k < n) {
                lazy[k * 2] += lazy[k], lazy[k * 2 + 1] += lazy[k];
            }
            lazy[k] = 0;
        }
    }

   public:
    segtree(const vector<T>& v) : n(1), sz((int)v.size()), h(0) {
        while (n < sz) n *= 2, h++;
        node.resize(2 * n, numeric_limits<T>::max());
        lazy.resize(2 * n, 0);
        for (int i = 0; i < sz; i++) node[i + n] = v[i];
        for (int i = n - 1; i >= 1; i--)
            node[i] = min(node[2 * i], node[2 * i + 1]);
    }
    void range(int a, int b, T x, int k = 1, int l = 0, int r = -1) {
        if (r < 0) r = n;
        eval(k);
        if (b <= l || r <= a) {
            return;
        }
        if (a <= l && r <= b) {
            lazy[k] += x;
            eval(k);
        } else {
            range(a, b, x, 2 * k, l, (l + r) / 2);
            range(a, b, x, 2 * k + 1, (l + r) / 2, r);
            node[k] = min(node[2 * k], node[2 * k + 1]);
        }
    }
    T query(int a, int b) {
        a += n, b += n - 1;
        for (int i = h; i > 0; i--) eval(a >> i), eval(b >> i);
        b++;
        T res1 = numeric_limits<T>::max(), res2 = numeric_limits<T>::max();
        while (a < b) {
            if (a & 1) eval(a), res1 = min(res1, node[a++]);
            if (b & 1) eval(--b), res2 = min(res2, node[b]);
            a >>= 1, b >>= 1;
        }
        return min(res1, res2);
    }
    void print() {
        for (int i = 0; i < sz; i++) cout << query(i, i + 1) << " ";
        cout << endl;
    }
};
signed main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N, M;
    cin >> N >> M;
    vector<int> A(N);
    vector<int> B(M);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    for (int i = 0; i < M; i++) {
        cin >> B[i];
    }
    vector<int> X(1000010, 0);
    for (int i = 0; i < N; i++) {
        X[A[i]]--;
    }
    for (int i = 0; i < M; i++) {
        X[B[i]]++;
    }
    for (int i = X.size() - 2; i >= 0; i--) {
        X[i] += X[i + 1];
    }
    X[0] = -10000000;
    segtree<int> sg(X);
    int Q;
    cin >> Q;
    for (int i = 0; i < Q; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        b--;
        if (a == 1) {
            if (A[b] < c) {
                sg.range(A[b] + 1, c + 1, -1);
            } else if (A[b] > c) {
                sg.range(c + 1, A[b] + 1, 1);
            }
            A[b] = c;
        } else {
             if (B[b] < c) {
                sg.range(B[b] + 1, c + 1, 1);
            } else if (B[b] > c) {
                sg.range(c + 1, B[b] + 1, -1);
            }
            B[b] = c;
        }
        int ok = 0;
        int ng = 1000001;
        while(ng - ok > 1){
            int m = (ok + ng) / 2;
            if(sg.query(m, X.size()) < 0){
                ok = m;
            }else{
                ng = m;
            }
        }
        if(ok == 0)ok = -1;
        cout << ok << "\n";
    }
    return 0;
}