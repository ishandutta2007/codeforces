#include<bits/stdc++.h>

using namespace std;

#define int long long

int const maxn = 1e5 + 5;
int r[maxn], g[maxn], b[maxn];
int inf = 5e18;

inline int get(int i, int j, int k) {
    return (r[i] - g[j]) * (r[i] - g[j]) + (r[i] - b[k]) * (r[i] - b[k]) + (b[k] - g[j]) * (b[k] - g[j]);
}

void solve() {
    int nr, ng, nb, ans = inf;
    cin >> nr >> ng >> nb;
    for (int i = 1; i <= nr; ++i) cin >> r[i];
    for (int i = 1; i <= ng; ++i) cin >> g[i];
    for (int i = 1; i <= nb; ++i) cin >> b[i];
    sort(r + 1, r + nr + 1);
    sort(g + 1, g + ng + 1);
    sort(b + 1, b + nb + 1);
    int ptr1 = 1, ptr2 = 1, f = 1;
    for (int i = 1; i <= nr; ++i) {
        while (ptr1 <= ng && g[ptr1] <= r[i]) ptr1++;
        while (ptr2 <= nb && b[ptr2] <= r[i]) ptr2++;
        for (int pos = max(f, ptr1 - 3); pos <= min(ng, ptr1 + 3); ++pos) {
            for (int go = max(f, ptr2 - 3); go <= min(nb, ptr2 + 3); ++go) {
                ans = min(ans, get(i, pos, go));
            }
        }
    }
    ptr1 = 1, ptr2 = 1;
    for (int i = 1; i <= ng; ++i) {
        while (ptr1 <= nr && r[ptr1] <= g[i]) ptr1++;
        while (ptr2 <= nb && b[ptr2] <= g[i]) ptr2++;
        for (int pos = max(f, ptr1 - 3); pos <= min(nr, ptr1 + 3); ++pos) {
            for (int go = max(f, ptr2 - 3); go <= min(nb, ptr2 + 3); ++go) {
                ans = min(ans, get(pos, i, go));
            }
        }
    }
    ptr1 = 1, ptr2 = 1;
    for (int i = 1; i <= nb; ++i) {
        while (ptr1 <= nr && r[ptr1] <= b[i]) ptr1++;
        while (ptr2 <= ng && g[ptr2] <= b[i]) ptr2++;
        for (int pos = max(f, ptr1 - 3); pos <= min(nr, ptr1 + 3); ++pos) {
            for (int go = max(f, ptr2 - 3); go <= min(ng, ptr2 + 3); ++go) {
                ans = min(ans, get(pos, go, i));
            }
        }
    }
    cout << ans << '\n';
}

main() {
#ifdef HOME
    freopen("input.txt", "r", stdin);
#endif // HOME
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}