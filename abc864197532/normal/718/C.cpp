#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7, x = 864197532, N = 587, logN = 17;

struct mat {
    long long num[2][2] = {{0, 0}, {0, 0}};
    mat operator * (const mat& o) {
        mat ans;
        for (int k = 0; k < 2; ++k) {
            for (int i = 0; i < 2; ++i) {
                for (int j = 0; j < 2; ++j) {
                    ans.num[i][j] = (ans.num[i][j] + num[i][k] * o.num[k][j]) % mod;
                }
            }
        }
        return ans;
    }
    mat operator + (const mat& o) {
        mat ans;
        for (int i = 0; i < 2; ++i) {
            for (int j = 0; j < 2; ++j) {
                ans.num[i][j] = (num[i][j] + o.num[i][j]) % mod;
            }
        }
        return ans;
    }
    void operator = (const mat& o) {
        for (int i = 0; i < 2; ++i) {
            for (int j = 0; j < 2; ++j) {
                num[i][j] = o.num[i][j];
            }
        }
    }
};

mat zero, one, fib;
vector <mat> fib2(30);

mat mat_pow(int b) {
    mat ans = one;
    for (int i = 0; i < 30; ++i) {
        if (b & (1 << i)) ans = ans * fib2[i];
    }
    return ans;
}

struct Seg {
    int l, r, m;
    mat M, lz;
    Seg* ch[2];
    Seg (int _l, int _r, vector <int> &a) : l(_l), r(_r), m(l + r >> 1) {
        if (r - l > 1) {
            ch[0] = new Seg(l, m, a);
            ch[1] = new Seg(m, r, a);
            pull();
        } else {
            M = mat_pow(a[l]);
        }
        lz = one;
    }
    void pull() {M = ch[0]->M + ch[1]->M;}
    void push() {
        if (r - l > 1) {
            ch[0]->M = ch[0]->M * lz;
            ch[0]->lz = ch[0]->lz * lz;
            ch[1]->M = ch[1]->M * lz;
            ch[1]->lz = ch[1]->lz * lz;
        }
        lz = one;
    }
    void add(int a, int b, int v) {
        if (a <= l && r <= b) {
            mat tmp = mat_pow(v);
            M = M * tmp;
            lz = lz * tmp;
        } else {
            push();
            if (a < m) ch[0]->add(a, b, v);
            if (m < b) ch[1]->add(a, b, v);
            pull();
        }
    }
    mat query(int a, int b) {
        if (a <= l && r <= b) return M;
        mat ans = zero;
        push();
        if (a < m) ans = ans + ch[0]->query(a, b);
        if (m < b) ans = ans + ch[1]->query(a, b);
        return ans;
    }
};

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, q, t, l, r, x;
    cin >> n >> q;
    fib.num[0][0] = fib.num[1][0] = fib.num[0][1] = 1;
    one.num[0][0] = one.num[1][1] = 1;
    fib2[0] = fib;
    for (int i = 1; i < 30; ++i) fib2[i] = fib2[i - 1] * fib2[i - 1];
    vector <int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i], a[i]--;
    Seg root(0, n, a);
    while (q--) {
        cin >> t >> l >> r, l--;
        if (t == 1) {
            cin >> x;
            root.add(l, r, x);
        } else {
            mat ans = root.query(l, r);
            cout << (ans.num[1][0] + ans.num[1][1]) % mod << endl;
        }
    }
}