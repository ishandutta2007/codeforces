#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int ll
#define ld long double
#define pii pair<int, int>
#define f first
#define s second
#define boost() cin.tie(0), cin.sync_with_stdio(0)

const int MN = 200005;

int n, q, m, u, v, t, in[MN], ans;
set<int> a[MN];

void inc(int i) {
    if (!in[i]) ans++;
    in[i]++;
}

void dec(int i) {
    in[i]--;
    if (!in[i]) ans--;
}

int32_t main() {
    boost();

    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        cin >> u >> v;
        if (u > v) swap(u, v);
        inc(u);
    }
    cin >> q;
    while (q--) {
        cin >> t;
        if (t == 1) {
            cin >> u >> v;
            if (u > v) swap(u, v);
            inc(u);
        } else if (t == 2) {
            cin >> u >> v;
            if (u > v) swap(u, v);
            dec(u);
        } else printf("%lld\n", n - ans);
    }

    return 0;
}