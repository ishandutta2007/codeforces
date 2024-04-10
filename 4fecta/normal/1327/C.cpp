#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

#define ll long long
#define ld long double
#define pii pair<int, int>
#define r first
#define c second
#define readl(_s) getline(cin, (_s));
#define boost() cin.tie(0); cin.sync_with_stdio(0)

const int MN = 205;

int n, m, k, moves, vis[MN];
pii a[MN], b[MN];
string ans;
vector<pii> d;

void move(int dr, int dc) {
    for (int i = 1; i <= k; i++) {
        a[i].r += dr;
        a[i].r = min(a[i].r, n);
        a[i].c = max(a[i].c, 1);
        a[i].c += dc;
        a[i].c = min(a[i].c, m);
        a[i].c = max(a[i].c, 1);
        if (a[i].r == b[i].r && a[i].c == b[i].c) vis[i] = 1;
    }
    moves += abs(dr) + abs(dc);
    if (moves <= 2 * m * n) {
        if (dr < 0) for (int i = 0; i < abs(dr); i++) ans += 'U';
        if (dr > 0) for (int i = 0; i < abs(dr); i++) ans += 'D';
        if (dc < 0) for (int i = 0; i < abs(dc); i++) ans += 'L';
        if (dc > 0) for (int i = 0; i < abs(dc); i++) ans += 'R';
    }
}

int main() {
    boost();

    cin >> n >> m >> k;
    for (int i = 1; i <= k; i++) cin >> a[i].r >> a[i].c;
    for (int i = 1; i <= k; i++) cin >> b[i].r >> b[i].c;
    /*d.clear();
    for (int i = 1; i <= k; i++) {
        if (vis[i]) continue;
        d.push_back({b[i].r - a[i].r, b[i].c - a[i].c});
    }
    sort(d.begin(), d.end());
    for (pii p : d) printf("%d %d\n", p.r, p.c);
    printf("\n");
    move(d[0].r, d[0].c);
    for (int t = 1; t <= k; t++) {
        d.clear();
        for (int i = 1; i <= k; i++) {
            if (vis[i]) continue;
            d.push_back({b[i].r - a[i].r, b[i].c - a[i].c});
        }
        if (d.empty()) break;
        sort(d.begin(), d.end());

    }
    if (moves <= 2 * m * n) printf("%d\n%s\n", moves, ans.c_str());
    else printf("-1\n");*/
    for (int i = 1; i < n; i++) ans += 'U', moves++;
    for (int i = 1; i < m; i++) ans += 'L', moves++;
    for (int i = 1; i <= n; i++) {
        if (i & 1) for (int j = 1; j < m; j++) ans += 'R', moves++;
        else for (int j = 1; j < m; j++) ans += 'L', moves++;
        ans += 'D'; moves++;
    }
    printf("%d\n%s\n", moves, ans.c_str());

    return 0;
}