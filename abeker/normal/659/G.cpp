#include <cstdio>
#include <algorithm>
using namespace std;

const int MAXN = 1000005;
const int offset = 1 << 20;
const int MOD = 1000000007;

struct node {
    int sol, prod, pref, suff;
    node(int sol, int prod, int pref, int suff) :
        sol(sol), prod(prod), pref(pref), suff(suff) {}
    node() : sol(0), prod(1), pref(0), suff(0) {}
};

int N;
int a[MAXN];
node t[2 * offset];

void load() {
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%d", a + i);
        a[i]--;
    }
}

inline int add(int x, int y) {
    x += y;
    if (x >= MOD) x -= MOD;
    return x;
}

inline int mul(int x, int y) {
    return (long long)x * y % MOD;
}

node merge(node L, node R) {
    node res;
    res.sol = add(add(L.sol, R.sol), mul(L.suff, R.pref));
    res.prod = mul(L.prod, R.prod);
    res.pref = add(L.pref, mul(L.prod, R.pref));
    res.suff = add(R.suff, mul(R.prod, L.suff));
    return res;
}

node query(int x, int lo, int hi, int from, int to) {
    if (lo >= to || hi <= from) return node();
    if (lo >= from && hi <= to) return t[x];
    int mid = (lo + hi) / 2;
    node l = query(2 * x, lo, mid, from, to);
    node r = query(2 * x + 1, mid, hi, from, to);
    return merge(l, r);
}

int solve() {
    for (int i = 0; i < N; i++) {
        int l = a[i];
        int r = a[i];
        if (i > 0) l = min(l, a[i - 1]);
        if (i < N - 1) r = min(r, a[i + 1]);
        t[i + offset] = node(a[i], min(l, r), l, r);
    }
    
    for (int i = offset - 1; i >= 0; i--)
        t[i] = merge(t[2 * i], t[2 * i + 1]);
            
    return query(1, 0, offset, 0, N).sol;
}

int brute() {
    int sol = 0;
    for (int i = 0; i < N; i++)
        for (int j = i; j < N; j++) {
            int l = a[j];
            int r = a[i];
            if (j > 0) l = min(l, a[j - 1]);
            if (i < N - 1) r = min(r, a[i + 1]);
            int tmp = mul(l, r);  
            for (int k = i + 1; k < j; k++)
                tmp = mul(tmp, min(a[k], min(a[k - 1], a[k + 1])));
            if (i == j) tmp = a[i];
            sol = add(sol, tmp);
        }
    return sol;
}

int main() {
    load();
    printf("%d\n", solve());
    return 0;
}