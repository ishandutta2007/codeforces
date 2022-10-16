#include <iostream>
#include <algorithm>

using namespace std;

const int MAXN = 100 * 1000 + 5, K = 48, MOD = 95542721;

struct Node {
    int sum[K], add;
};

int a[MAXN];
Node st[4 * MAXN];

int f(int x) {
    return (long long)x * x % MOD * x % MOD;
}

void buildst(int v, int tl, int tr) {
    if(tl == tr - 1) {
        st[v].sum[0] = a[tl] % MOD;
        for(int i = 1; i < K; i++)
            st[v].sum[i] = f(st[v].sum[i - 1]);
        st[v].add = 0;
        return;
    }
    int tm = (tl + tr) / 2;
    buildst(2 * v, tl, tm);
    buildst(2 * v + 1, tm, tr);
    for(int i = 0; i < K; i++) {
        st[v].sum[i] = st[2 * v].sum[i] + st[2 * v + 1].sum[i];
        if(st[v].sum[i] >= MOD)
            st[v].sum[i] -= MOD;
    }
}

void push(int v) {
    if(!st[v].add)
        return;
    rotate(st[2 * v].sum, st[2 * v].sum + st[v].add, st[2 * v].sum + K);
    st[2 * v].add += st[v].add;
    if(st[2 * v].add >= K)
        st[2 * v].add -= K;
    rotate(st[2 * v + 1].sum, st[2 * v + 1].sum + st[v].add, st[2 * v + 1].sum + K);
    st[2 * v + 1].add += st[v].add;
    if(st[2 * v + 1].add >= K)
        st[2 * v + 1].add -= K;
    st[v].add = 0;
}

void update(int v, int tl, int tr, int l, int r) {
    if(l == tl && r == tr) {
        rotate(st[v].sum, st[v].sum + 1, st[v].sum + K);
        st[v].add++;
        if(st[v].add >= K)
            st[v].add -= K;
        return;
    }
    push(v);
    int tm = (tl + tr) / 2;
    if(l < tm)
        update(2 * v, tl, tm, l, min(r, tm));
    if(r > tm)
        update(2 * v + 1, tm, tr, max(l, tm), r);
    for(int i = 0; i < K; i++) {
        st[v].sum[i] = st[2 * v].sum[i] + st[2 * v + 1].sum[i];
        if(st[v].sum[i] >= MOD)
            st[v].sum[i] -= MOD;
    }
}

int get(int v, int tl, int tr, int l, int r) {
    if(l == tl && r == tr)
        return st[v].sum[0];
    push(v);
    int tm = (tl + tr) / 2, res = 0;
    if(l < tm)
        res += get(2 * v, tl, tm, l, min(r, tm));
    if(r > tm)
        res += get(2 * v + 1, tm, tr, max(l, tm), r);
    if(res >= MOD)
        res -= MOD;
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> a[i];
    buildst(1, 0, n);
    int q;
    cin >> q;
    for(int i = 0; i < q; i++) {
        int t, l, r;
        cin >> t >> l >> r;
        l--;
        if(t == 1)
            cout << get(1, 0, n, l, r) << '\n';
        else
            update(1, 0, n, l, r);
    }
    return 0;
}