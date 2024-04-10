#include <iostream>
#include <cstring>

using namespace std;

const int MOD = 1000000009;
const int NMAX = 300005;


class Matrix {
public:
    int mat[3][3];

    Matrix(int c = 0) {
        memset(mat, 0, sizeof mat);

        for (int i = 0; i < 3; ++ i)
            mat[i][i] = c;
    }

    Matrix operator*(const Matrix &arg) const {
        Matrix res;
        for (int i = 0; i < 3; ++ i)
            for (int j = 0; j < 3; ++ j)
                for (int k = 0; k < 3; ++ k)
                    res.mat[i][j] = (res.mat[i][j] + 1LL * mat[i][k] * arg.mat[k][j]) % MOD;

        return res;
    }
} T[NMAX];

void compute_T(int n) {
    T[0] = Matrix(1);
    T[1] = Matrix(1);

    T[1].mat[0][0] = 0;
    T[1].mat[0][1] = 1;
    T[1].mat[1][0] = 1;
    T[1].mat[2][1] = 1;

    for (int i = 2; i <= n; ++ i)
        T[i] = T[i - 1] * T[1];
}

int get_fibo(int f0, int f1, int n) {
    return (1LL * T[n].mat[0][0] * f0 + 1LL * T[n].mat[0][1] * f1 + 1LL * T[n].mat[0][2] * f0) % MOD;
}

int get_fibo_sum(int f0, int f1, int n) {
    return (1LL * T[n].mat[2][0] * f0 + 1LL * T[n].mat[2][1] * f1 + 1LL * T[n].mat[2][2] * f0) % MOD;
}

void add_val(int &where, int val) {
    where += val;
    if (where >= MOD)
        where -= MOD;
}

struct Node {
    int st, dr;
    int sum;

    int lazy0, lazy1;

    void make_lazy(int f0, int f1) {
        add_val(lazy0, f0);
        add_val(lazy1, f1);
        add_val(sum, get_fibo_sum(f0, f1, dr - st));
    }
} tree[4 * NMAX];

void propagate(int node) {
    if (tree[node].st < tree[node].dr) {
        int mid = (tree[node].st + tree[node].dr) >> 1;

        tree[node << 1].make_lazy(tree[node].lazy0, tree[node].lazy1);
        tree[(node << 1) + 1].make_lazy(get_fibo(tree[node].lazy0, tree[node].lazy1, mid + 1 - tree[node].st),
                                        get_fibo(tree[node].lazy0, tree[node].lazy1, mid + 1 - tree[node].st + 1));
    }

    tree[node].lazy0 = 0;
    tree[node].lazy1 = 0;
}

int a[NMAX];
void build(int st, int dr, int node) {
    tree[node].st = st, tree[node].dr = dr;

    if (st == dr) {
        tree[node].sum = a[st];
        return ;
    }

    int mid = (st + dr) >> 1;
    build(st, mid, node << 1);
    build(mid + 1, dr, (node << 1) + 1);

    tree[node].sum = tree[node << 1].sum + tree[(node << 1) + 1].sum;
    if (tree[node].sum >= MOD)
        tree[node].sum -= MOD;
}

void update(int st, int dr, int f0, int f1, int node) {
    if (tree[node].st == st && tree[node].dr == dr) {
        tree[node].make_lazy(f0, f1);
        return ;
    }
    propagate(node);

    int mid = (tree[node].st + tree[node].dr) >> 1;
    if (dr <= mid)
        update(st, dr, f0, f1, node << 1);
    else if (st > mid)
        update(st, dr, f0, f1, (node << 1) + 1);
    else {
        update(st, mid, f0, f1, node << 1);
        update(mid + 1, dr, get_fibo(f0, f1, mid + 1 - st), get_fibo(f0, f1, mid + 1 - st + 1), (node << 1) + 1);
    }

    tree[node].sum = tree[node << 1].sum + tree[(node << 1) + 1].sum;
    if (tree[node].sum >= MOD)
        tree[node].sum -= MOD;
}

int query(int st, int dr, int node) {
    if (tree[node].st == st && tree[node].dr == dr)
        return tree[node].sum;
    propagate(node);

    int mid = (tree[node].st + tree[node].dr) >> 1;

    int res;
    if (dr <= mid)
        res = query(st, dr, node << 1);
    else if (st > mid)
        res = query(st, dr, (node << 1) + 1);
    else {
        res = query(st, mid, node << 1) + query(mid + 1, dr, (node << 1) + 1);
        if (res >= MOD)
            res -= MOD;
    }

    return res;
}

int main()
{
    ios_base :: sync_with_stdio(false);

    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= n; ++ i)
        cin >> a[i];
    build(1, n, 1);

    compute_T(n);

    int type, l, r;
    while (m --) {
        cin >> type >> l >> r;
        if (type == 1)
            update(l, r, 1, 1, 1);
        else
            cout << query(l, r, 1) << '\n';
    }

    return 0;
}