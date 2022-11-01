#include <bits/stdc++.h> 

using namespace std;

const int N = 1e6 + 10;

int n, k, bit[N], u = 1;
long long now = 1LL;

void update (int p, int v) {
    while (p < N) bit[p] += v, p += (p & -p);
}

int prefix (int p) {
    int sum = 0;
    while (p > 0) sum += bit[p], p -= (p & -p);
    return sum;
}

int query (int l, int r) {
    if (l > r) return 0;
    return prefix(r) - prefix(l - 1);
}

int main (int argc, char const *argv[]) {
    scanf("%d %d", &n, &k);
    if (k + k > n) k = n - k;
    for (int i = 1; i <= n; ++i) {
        int v = u + k;
        if (v <= n) {
            now += query(u + 1, v - 1) + 1;
        } else {
            v -= n;
            now += query(u + 1, n) + query(1, v - 1) + 1;
        }
        update(u, 1), update(v, 1), u = v;
        printf("%lld ", now);
    } puts("");
    return 0;
}