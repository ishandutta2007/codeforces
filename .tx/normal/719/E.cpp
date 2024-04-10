#include <bits/stdc++.h>
using namespace std;

template<typename T>
void sci(T& t) {
    cin >> t;
}

template<typename T, typename... Ts>
void sci(T& t, Ts&... ts) {
    sci(t);
    sci(ts...);
};

#define scid(vars...) int vars; sci(vars)
#define scidl(vars...) lint vars; sci(vars)
#define scidd(vars...) double vars; sci(vars)
#define scids(vars...) string vars; sci(vars)

typedef long long lint;

const int M = 1e9 + 7;

int** create_matrix(int n, int m) {
    int* data = new int[n * m];
    memset(data, 0, sizeof(int) * n * m);
    int** matrix = new int*[n];
    for (int i = 0; i < n; i++) {
        matrix[i] = data + i * m;
    }
    return matrix;
}

void mcp(int** source, int** dest) {
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            dest[i][j] = source[i][j];
        }
    }
}

int** tmp = create_matrix(2, 2);
void mul(int** a, int** b, int** res) {
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            tmp[i][j] = 0;
            for (int k = 0; k < 2; k++) {
                tmp[i][j] = (tmp[i][j] + 1LL * a[i][k] * b[k][j]) % M;
            }
        }
    }
    mcp(tmp, res);
}

int** mpow_tmp = create_matrix(2, 2);
int** mpow(int** a, int p) {
    int** res = create_matrix(2, 2);
    res[0][0] = res[1][1] = 1;
    mcp(a, mpow_tmp);
    for (; p > 0; p >>= 1) {
        if (p & 1) {
            mul(res, mpow_tmp, res);
        }
        mul(mpow_tmp, mpow_tmp, mpow_tmp);
    }
    return res;
}

void add(int** a, int** b, int** res) {
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            tmp[i][j] = (a[i][j] + b[i][j]) % M;
        }
    }
    mcp(tmp, res);
}

int** fib1;

struct SegmentTree {
    int*** a;
    int*** b;

    SegmentTree(int n, int* init) {
        a = new int**[4 * n];
        b = new int**[4 * n];
        build(0, 0, n, init);
    }

    void build(int i, int l, int r, int* init) {
        b[i] = create_matrix(2, 2);
        b[i][0][0] = b[i][1][1] = 1;
        if (l + 1 == r) {
            a[i] = mpow(fib1, init[l] - 1);
        } else {
            int m = (l + r) >> 1;
            build(i * 2 + 1, l, m, init);
            build(i * 2 + 2, m, r, init);
            a[i] = create_matrix(2, 2);
            add(a[i * 2 + 1], a[i * 2 + 2], a[i]);
        }
    }

    void push(int i, int l, int r) {
        mul(a[i], b[i], a[i]);
        if (l + 1 < r) {
            mul(b[i * 2 + 1], b[i], b[i * 2 + 1]);
            mul(b[i * 2 + 2], b[i], b[i * 2 + 2]);
        }
        b[i][0][0] = b[i][1][1] = 1;
        b[i][0][1] = b[i][1][0] = 0;
    }

    void addx(int i, int l, int r, int ql, int qr, int** x) {
        push(i, l, r);
        if (r <= ql || qr <= l) {
            return;
        }
        if (ql <= l && r <= qr) {
            mul(b[i], x, b[i]);
            push(i, l, r);
            return;
        }
        int m = (l + r) >> 1;
        addx(i * 2 + 1, l, m, ql, qr, x);
        addx(i * 2 + 2, m, r, ql, qr, x);
        add(a[i * 2 + 1], a[i * 2 + 2], a[i]);
    }

    int get(int i, int l, int r, int ql, int qr) {
        push(i, l, r);
        if (r <= ql || qr <= l) {
            return 0;
        }
        if (ql <= l && r <= qr) {
            return a[i][0][0];
        }
        int m = (l + r) >> 1;
        return (get(i * 2 + 1, l, m, ql, qr) + get(i * 2 + 2, m, r, ql, qr)) % M;
    }
};

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    fib1 = create_matrix(2, 2);
    fib1[0][0] = fib1[0][1] = fib1[1][0] = 1;

    scid(n, m);
    int* a = new int[n];
    for (int i = 0; i < n; i++) {
        sci(a[i]);
    }
    SegmentTree st(n, a);
    for (int i = 0; i < m; i++) {
        scid(t, l, r);
        --l; --r;
        if (t == 1) {
            scid(x);
            st.addx(0, 0, n, l, r + 1, mpow(fib1, x));
        } else {
            cout << st.get(0, 0, n, l, r + 1) << "\n";
        }
    }

    return 0;
}