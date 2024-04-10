#include <bits/stdc++.h>

using namespace std;

const int N = 200'007;

int n, T;
int in[N];
int place[N];
int tree[3 * N];

void add(int p, int v)
{
    p += T;
    while (p) {
        tree[p] += v;
        p >>= 1;
    }
}

int query(int l, int r)
{
    int ret = 0;
    l += T, r += T;

    while (l <= r) {
        if (l & 1) {
            ret += tree[l];
        }

        if (!(r & 1)) {
            ret += tree[r];
        }

        l = (l + 1) >> 1;
        r = (r - 1) >> 1;
    }

    return ret;
}

int ask(int l, int r)
{
    if (l < r) {
        return query(l, r - 1);
    }

    return query(l, n) + query(1, r - 1);
}

void solve()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &in[i]);
        place[in[i]] = i;
    }

    T = 1;
    while (T <= n) {
        T *= 2;
    }

    for (int i = 1; i <= 2 * T; ++i) {
        tree[i] = 0;
    }

    long long ans = 0;
    for (int i = n; i >= 1; --i) {
        if (i < n) {
            ans += 1LL * i * ask(place[i], place[i + 1]);
        }

        add(place[i], 1);
    }

    printf("%lld\n", ans);
}

int main()
{
    int cases;
    scanf("%d", &cases);

    while (cases--) {
        solve();
    }

    return 0;
}