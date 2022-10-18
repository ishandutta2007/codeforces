#include <bits/stdc++.h>

#define int long long

using namespace std;

template <class T> void fr(T &a, bool f = 0, char ch = getchar()) {
    for (a = 0; ch < '0' || ch > '9'; ch = getchar()) ch == '-' ? f = 1 : 0;
    for (; ch >= '0' && ch <= '9'; ch = getchar()) a = a * 10 + (ch - '0');
    a = f ? -a : a;
}
template <class T, class... Y> void fr(T &t, Y &... a) { fr(t), fr(a...); }
int fr() { int a; return fr(a), a; }

const int N = 3e3;

int n, k, ans, sz[N + 10], val[N + 10];
vector<int> f, a[N + 10];

void dc(int l, int r) {
    if (l == r) {
        int ret = 0;
        for (int i = 0; i < min(k, sz[l]); i++) ret += a[l][i], ans = max(ans, ret + f[k - i - 1]);
        return;
    }
    vector<int> g = f;
    int mid = (l + r) >> 1;
    for (int i = l; i <= mid; i++)
        for (int j = k; j >= sz[i]; j--) f[j] = max(f[j], f[j - sz[i]] + val[i]);
    dc(mid + 1, r), f = g;
    for (int i = mid + 1; i <= r; i++)
        for (int j = k; j >= sz[i]; j--) f[j] = max(f[j], f[j - sz[i]] + val[i]);
    dc(l, mid);
}

struct OI {
    int RP, score;
} FJOI2022;

signed main() {
    FJOI2022.RP++, FJOI2022.score++;
    fr(n, k), f.resize(k + 10);
    for (int i = 1; i <= n; i++) {
        fr(sz[i]);
        for (int j = 1, x; j <= sz[i]; j++) fr(x), a[i].push_back(x), val[i] += x;
    }
    dc(1, n), printf("%lld\n", ans);
    return 0;
}