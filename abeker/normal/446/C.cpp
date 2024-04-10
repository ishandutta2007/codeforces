#include <cstdio>
#include <cstring>
using namespace std;

const int MAXN = 300005;
const int MOD = 1000000009;

const int INV = 276601605;
const int ALPHA = 691504013;
const int BETA = 308495997;

inline int add(int x, int y) {
    x += y;
    if (x >= MOD) x -= MOD;
    else if (x < 0) x += MOD;
    return x;
}

inline int mul(int x, int y) {
    return (long long)x * y % MOD;
}

int pow(int x, int y) {
    int res = 1;
    for (; y; y >>= 1) {
        if (y & 1) res = mul(res, x);
        x = mul(x, x);
    }
    return res;
}

inline int inv(int x) {
    return pow(x, MOD - 2);
}

struct fenwick {
    int f[MAXN];
    fenwick() {
        memset(f, 0, sizeof f);
    }
    void update(int x, int val) {
        for (++x; x < MAXN; x += x & -x)
            f[x] = add(f[x], val);
    }
    void update(int lo, int hi, int val) {
        update(lo, val);
        update(hi + 1, -val);
    }
    int get(int x) {
        int ret = 0;
        for (++x; x; x -= x & -x)
            ret = add(ret, f[x]);
        return ret;
    }
};

int N, M;
int a[MAXN];
int pow_alpha[MAXN], pow_beta[MAXN];
int inv_alpha[MAXN], inv_beta[MAXN];
fenwick Ax, Ay, Az, Bx, By, Bz;

void load() {
    scanf("%d%d", &N, &M);
    for (int i = 1; i <= N; i++)
        scanf("%d", a + i);
}

int sum(int x) {
    int sum_alpha = add(mul(ALPHA + 1, add(mul(pow_alpha[x], Ax.get(x)), Ay.get(x))), Az.get(x));
    int sum_beta = add(mul(BETA + 1, add(mul(pow_beta[x], Bx.get(x)), By.get(x))), Bz.get(x));    
    return mul(INV, add(sum_alpha, -sum_beta));
}

int query(int lo, int hi) {
    return add(add(a[hi], -a[lo - 1]), add(sum(hi), -sum(lo - 1)));
}

void solve() {
    for (int i = 1; i <= N; i++)
        a[i] = add(a[i], a[i - 1]);
    
    pow_alpha[0] = pow_beta[0] = 1;
    inv_alpha[0] = inv_beta[0] = 1;
    for (int i = 1; i <= N; i++) {
        pow_alpha[i] = mul(pow_alpha[i - 1], ALPHA);
        pow_beta[i] = mul(pow_beta[i - 1], BETA);
        inv_alpha[i] = inv(pow_alpha[i]);
        inv_beta[i] = inv(pow_beta[i]);
    }
    
    while (M--) {
        int t, l, r;
        scanf("%d%d%d", &t, &l, &r);
        if (t == 1) {
            Ax.update(l, r, inv_alpha[l - 1]);
            Ay.update(l, r, -1);
            Az.update(r + 1, N, mul(ALPHA + 1, add(pow_alpha[r - l + 1], -1)));
            Bx.update(l, r, inv_beta[l - 1]);
            By.update(l, r, -1);
            Bz.update(r + 1, N, mul(BETA + 1, add(pow_beta[r - l + 1], -1)));
        }
        else printf("%d\n", query(l, r));
    }
}

int main() {
    load();
    solve();
    return 0;
}