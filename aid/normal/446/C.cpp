#include <iostream>

using namespace std;

struct Node {
    int sum, a, b;
};

const int MAXN = 300 * 1000 + 5, MOD = 1000 * 1000 * 1000 + 9;
int ar[MAXN], fib[MAXN];
Node st[4 * MAXN];

void buildst(int v, int tl, int tr) {
    if(tl + 1 == tr) {
        st[v].sum = ar[tl];
        return;
    }
    int tm = (tl + tr) / 2;
    buildst(2 * v, tl, tm);
    buildst(2 * v + 1, tm, tr);
    st[v].sum = (st[2 * v].sum + st[2 * v + 1].sum) % MOD;
}

void push(int v, int tl, int tm, int tr) {
    if(!st[v].a && !st[v].b)
        return;
    st[2 * v].a = (st[2 * v].a + st[v].a) % MOD;
    st[2 * v].b = (st[2 * v].b + st[v].b) % MOD;
    st[2 * v].sum = (st[2 * v].sum +
                     (long long)(fib[tm - tl + 2] - 1) * st[v].a +
                     (long long)(fib[tm - tl + 1] - 1) * st[v].b) % MOD;
    int ra = ((long long)fib[tm - tl + 1] * st[v].a +
              (long long)fib[tm - tl] * st[v].b) % MOD,
        rb = ((((long long)fib[tm - tl + 2] * st[v].a +
                (long long)fib[tm - tl + 1] * st[v].b) % MOD) - ra + MOD) % MOD;
    st[2 * v + 1].a = (st[2 * v + 1].a + ra) % MOD;
    st[2 * v + 1].b = (st[2 * v + 1].b + rb) % MOD;
    st[2 * v + 1].sum = (st[2 * v + 1].sum +
                     (long long)(fib[tr - tm + 2] - 1) * ra +
                     (long long)(fib[tr - tm + 1] - 1) * rb) % MOD;
    st[v].a = 0;
    st[v].b = 0;
}

void update(int v, int tl, int tr, int l, int r, int a, int b) {
    if(l == tl && r == tr) {
        st[v].a = (st[v].a + a) % MOD;
        st[v].b = (st[v].b + b) % MOD;
        st[v].sum = (st[v].sum + (long long)(fib[tr - tl + 2] - 1) * a +
                     (long long)(fib[tr - tl + 1] - 1) * b) % MOD;
        return;
    }
    int tm = (tl + tr) / 2;
    push(v, tl, tm, tr);
    if(l < tm) {
        update(2 * v, tl, tm, l, min(r, tm), a, b);
        if(r > tm) {
            int ra = ((long long)fib[tm - l + 1] * a +
                      (long long)fib[tm - l] * b) % MOD,
                rb = ((((long long)fib[tm - l + 2] * a +
                       (long long)fib[tm - l + 1] * b) % MOD) - ra + MOD) % MOD;
            update(2 * v + 1, tm, tr, tm, r, ra, rb);
        }
    }
    else
        update(2 * v + 1, tm, tr, l, r, a, b);
    st[v].sum = (st[2 * v].sum + st[2 * v + 1].sum) % MOD;
}

int get(int v, int tl, int tr, int l, int r) {
    if(l == tl && r == tr)
        return st[v].sum;
    int tm = (tl + tr) / 2;
    push(v, tl, tm, tr);
    int res = 0;
    if(l < tm)
        res += get(2 * v, tl, tm, l, min(r, tm));
    if(r > tm)
        res += get(2 * v + 1, tm, tr, max(l, tm), r);
    return res % MOD;
}

int main() {
    ios_base::sync_with_stdio(false);
    fib[1] = 1;
    for(int i = 2; i < MAXN; i++)
        fib[i] = (fib[i - 1] + fib[i - 2]) % MOD;;
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < n; i++)
        cin >> ar[i];
    buildst(1, 0, n);
    for(int i = 0; i < m; i++) {
        int q, l, r;
        cin >> q >> l >> r;
        l--;
        if(q == 1)
            update(1, 0, n, l, r, 1, 0);
        else
            cout << get(1, 0, n, l, r) << '\n';
    }
    return 0;
}