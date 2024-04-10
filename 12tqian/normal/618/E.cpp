#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")

#include <bits/stdc++.h>

using namespace std;

inline char gc() { // like getchar()
    static char buf[1 << 16];
    static size_t bc, be;
    if (bc >= be) {
        buf[0] = 0, bc = 0;
        be = fread(buf, 1, sizeof(buf), stdin);
    }
    return buf[bc++]; // returns 0 on EOF
}

int read_int() {
    int a, c;
    while ((a = gc()) < 40);
    if (a == '-') return -read_int();
    while ((c = gc()) >= 48) a = a * 10 + c - 480;
    return a - 48;
}

template <class T> struct LazySeg {
    const T ID = complex<double>(1, 0);
    std::vector<T> sum, lazy;
    int sz;

    void init(int sz_) {
        sz = 1;
        while (sz < sz_) sz *= 2;
        sum.assign(2 * sz, ID);
        lazy.assign(2 * sz, ID);
        build();
    }
    void push(int ind, int L, int R) {
        if (lazy[ind] == ID) return;
        sum[ind] *= lazy[ind];
        if (L != R) {
            lazy[2 * ind] *= lazy[ind];
            lazy[2 * ind + 1] *= lazy[ind];
        }
        lazy[ind] = {1, 0};
    }

    void pull(int ind) {
        sum[ind] = sum[2 * ind] + sum[2 * ind + 1];
    }

    void build() {
        for (int i = sz - 1; i >= 1; i--) {
            pull(i);
        }
    }

    void upd(int lo, int hi, T inc, int ind = 1, int L = 0, int R = -1) {
        if (R == -1) R += sz;
        push(ind, L, R);
        if (hi < L || R < lo) return;
        if (lo <= L && R <= hi) {
            lazy[ind] = inc;
            push(ind, L, R);
            return;
        }
        int M = (L + R) / 2;
        upd(lo, hi, inc, 2 * ind, L, M);
        upd(lo, hi, inc, 2 * ind + 1, M + 1, R);
        pull(ind);
    }

    T qsum(int lo, int hi, int ind = 1, int L = 0, int R = -1) {
        if (R == -1) R += sz;
        push(ind, L, R);
        if (lo > R || L > hi) return 0;
        if (lo <= L && R <= hi) return sum[ind];
        int M = (L + R) / 2;
        return qsum(lo, hi, 2 * ind, L, M) + qsum(lo, hi, 2 * ind + 1, M + 1, R);
    }
};

const int N = 3e5 + 5;
const int D = 360 + 5;
const double PI = acos((long double)-1);

int len[N];
complex<double> rot[D];

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cout << fixed << setprecision(10);

    int n = read_int();
    int m = read_int();

    LazySeg<complex<double>> seg;
    seg.init(n);

    for (int i = 0; i < n; i++)
        len[i] = 1;

    for (int i = 0; i < 361; i++) {
        double rad = 2 * PI - i * PI / 180;
        rot[i] = complex<double>(cos(rad), sin(rad));
    }

    for (int i = 0; i < m; i++) {
        int t = read_int();
        int y = read_int();
        int z = read_int();
        y--;

        if (t == 1) {
            seg.upd(y, y, ((double)z + len[y]) / len[y]);
            len[y] += z;
        } else {
            seg.upd(y, n - 1, rot[z]);
        }

        auto res = seg.qsum(0, n - 1);

        cout << res.real() << " " << res.imag() << '\n';
    }

    return 0;
}