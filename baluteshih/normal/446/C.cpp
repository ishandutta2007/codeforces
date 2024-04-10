#pragma GCC optimize("O3")
#include <iostream>
#include <utility>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define X first
#define Y second

const int MOD = 1e9 + 9;

void add(int &x, int v) {
    x += v;
    if (x >= MOD)
        x -= MOD;
}

struct Matrix {
    int n, m, M[2][2];
    Matrix(int _n = 0, int _m = 0): n(_n), m(_m) {
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                M[i][j] = 0;
    }
    Matrix operator*(const Matrix &a) const {
        Matrix rt(n, a.m);
        for (int i = 0; i < rt.n; ++i)
            for (int j = 0; j < rt.m; ++j)
                for (int k = 0; k < m; ++k)
                    add(rt.M[i][j], (ll)M[i][k] * a.M[k][j] % MOD);
        return rt;
    }
} tr[300005];

struct node {
    int sum;
    Matrix lazy;
    node(int v = 0): sum(v), lazy(Matrix(1, 2)){}
} seg[1200005];

int arr[300005], val[300005] = {0, 1};
pii prx[300005];

inline Matrix gen_mat(int a, int b) {
    Matrix rt(1, 2);
    rt.M[0][0] = a, rt.M[0][1] = b;
    return rt;
}

void up(int rt) {
    seg[rt].sum = (seg[rt << 1].sum + seg[rt << 1 | 1].sum) % MOD;
}

void build(int l, int r, int rt) {
    if (l == r)
        return seg[rt] = node(arr[l]), void();
    int mid = (l + r) >> 1;
    build(l, mid, rt << 1), build(mid + 1, r, rt << 1 | 1);
    up(rt);
}

void give_tag(int l, int r, int rt, const Matrix &mat) {
    add(seg[rt].lazy.M[0][0], mat.M[0][0]); 
    add(seg[rt].lazy.M[0][1], mat.M[0][1]);
    add(seg[rt].sum, ((ll)prx[r - l + 1].X * mat.M[0][0] + (ll)prx[r - l + 1].Y * mat.M[0][1]) % MOD);
}

void down(int l, int r, int rt) {
    if (seg[rt].lazy.M[0][0] == 0 && seg[rt].lazy.M[0][1] == 0)
        return;
    int mid = (l + r) >> 1;
    give_tag(l, mid, rt << 1, seg[rt].lazy);
    give_tag(mid + 1, r, rt << 1 | 1, seg[rt].lazy * tr[mid - l + 1]);
    seg[rt].lazy.M[0][0] = seg[rt].lazy.M[0][1] = 0;
}

void modify(int L, int R, int l, int r, int rt, int v) {
    if (L <= l && R >= r)
        return give_tag(l, r, rt, gen_mat(val[v + 1], val[v]));
    down(l, r, rt);
    int mid = (l + r) >> 1;
    if (L <= mid)
        modify(L, min(mid, R), l, mid, rt << 1, v);
    if (R > mid) {
        if (L <= mid)
            modify(mid + 1, R, mid + 1, r, rt << 1 | 1, v + mid - L + 1);
        else
            modify(L, R, mid + 1, r, rt << 1 | 1, v);
    }
    up(rt);
}

int query(int L, int R, int l, int r, int rt) {
    if (L <= l && R >= r)
        return seg[rt].sum;
    down(l, r, rt);
    int mid = (l + r) >> 1;
    if (R <= mid) 
        return query(L, R, l, mid, rt << 1);
    if (L > mid)
        return query(L, R, mid + 1, r, rt << 1 | 1);
    return (query(L, R, l, mid, rt << 1) + query(L, R, mid + 1, r, rt << 1 | 1)) % MOD;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n, q;
    cin >> n >> q;
    for (int i = 1; i <= n; ++i)
        cin >> arr[i];
    tr[0] = tr[1] = Matrix(2, 2);
    tr[0].M[0][0] = tr[0].M[1][1] = 1;
    tr[1].M[0][0] = tr[1].M[0][1] = tr[1].M[1][0] = 1;
    prx[1] = pii(0, 1), prx[2] = pii(1, 0), prx[3] = pii(1, 1);
    for (int i = 4; i <= n; ++i)
        prx[i] = pii((prx[i - 1].X + prx[i - 2].X) % MOD, (prx[i - 1].Y + prx[i - 2].Y) % MOD);
    for (int i = 2; i <= n; ++i) {
        tr[i] = tr[i - 1] * tr[1];
        val[i] = (val[i - 1] + val[i - 2]) % MOD;
        prx[i] = pii((prx[i - 1].X + prx[i].X) % MOD, (prx[i - 1].Y + prx[i].Y) % MOD);
    }
    build(1, n, 1);
    for (int i = 0; i < q; ++i) {
        int k, l, r;
        cin >> k >> l >> r;
        if (k == 1)
            modify(l, r, 1, n, 1, 1);
        else
            cout << query(l, r, 1, n, 1) << "\n";
    }
}