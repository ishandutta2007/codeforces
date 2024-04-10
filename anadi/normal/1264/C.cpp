#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const int N = 200'007;
const int T = 1 << 18;

const int MOD = 998'244'353;
const ll INF = 1LL * MOD * MOD;

int n, q;
pair <int, int> tree[T + T];

int result = 0;
set <int> active;

int fast(int a, int b)
{
    int ret = 1;
    while (b) {
        if (b & 1) {
            ret = 1LL * ret * a % MOD;
        }

        b >>= 1;
        a = 1LL * a * a % MOD;
    }

    return ret;
}

pair <int, int> merge(pair <int, int> l, pair <int, int> r)
{
    int s = (l.first + 1LL * r.first * l.second) % MOD;
    int p = 1LL * l.second * r.second % MOD;
    return {s, p};
}

pair <int, int> ask(int from, int to, int s = 0, int e = T - 1, int cur = 1)
{
    if (from <= s && e <= to) {
        return tree[cur];
    }

    int mid = (s + e) / 2;
    if (to <= mid) {
        return ask(from, to, s, mid, cur + cur);
    }

    if (mid < from) {
        return ask(from, to, mid + 1, e, cur + cur + 1);
    }

    const auto l = ask(from, to, s, mid, cur + cur);
    const auto r = ask(from, to, mid + 1, e, cur + cur + 1);
    return merge(l, r);
}

int query(int from, int to)
{
    auto [s, p] = ask(from, to);
    return 1LL * s * fast(p, MOD - 2) % MOD;
}

int main()
{
    const int P = fast(100, MOD - 2);

    scanf("%d %d", &n, &q);
    for (int i = 1; i <= n; ++i) {
        int v;
        scanf("%d", &v);

        v = 1LL * v * P % MOD;
        tree[T + i] = {1, v};
    }

    for (int i = T - 1; i >= 1; --i) {
        tree[i] = merge(tree[i + i], tree[i + i + 1]);
    }

    active.insert(1);
    active.insert(n + 1);

    result = query(1, n);

    while (q--) {
        int v;
        scanf("%d", &v);

        if (active.count(v)) {
            active.erase(v);

            auto it = active.upper_bound(v);
            int nxt = *it;
            int prv = *--it;

            result = (result + MOD - query(v, nxt - 1)) % MOD;
            result = (result + MOD - query(prv, v - 1)) % MOD;
            result = (result + query(prv, nxt - 1)) % MOD;
        } else {
            auto it = active.upper_bound(v);
            int nxt = *it;
            int prv = *--it;

            active.insert(v);

            result = (result + MOD - query(prv, nxt - 1)) % MOD;
            result = (result + query(v, nxt - 1)) % MOD;
            result = (result + query(prv, v - 1)) % MOD;
        }

        printf("%d\n", result);
    }

    return 0;
}