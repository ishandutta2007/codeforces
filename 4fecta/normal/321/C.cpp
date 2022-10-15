#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

#define ll long long
#define ld long double
#define pii pair<int, int>
#define f first
#define s second
#define readl(_s) getline(cin, (_s));
#define boost() cin.tie(0); cin.sync_with_stdio(0)

const int MN = 100005;

int n, u, v, sz[MN], vis[MN];
char ans[MN];
vector<int> a[MN];

int size_of(int cur, int pre) {
    sz[cur] = 1;
    for (int nxt : a[cur]) if (!vis[nxt] && nxt != pre) sz[cur] += size_of(nxt, cur);
    return sz[cur];
}

int get_centroid(int cur, int pre, int cnt) {
    for (int nxt : a[cur]) if (!vis[nxt] && nxt != pre && sz[nxt] > cnt) return get_centroid(nxt, cur, cnt);
    return cur;
}

void solve(int cur, char c) {
    cur = get_centroid(cur, 0, size_of(cur, 0) / 2);
    ans[cur] = c;
    vis[cur] = 1;
    for (int nxt : a[cur]) {
        if (vis[nxt]) continue;
        solve(nxt, c + 1);
    }
}

int main() {
    boost();

    cin >> n;
    for (int i = 1; i < n; i++) {
        cin >> u >> v;
        a[u].push_back(v);
        a[v].push_back(u);
    }
    solve(1, 'A');
    for (int i = 1; i <= n; i++) printf("%c ", ans[i]);

    return 0;
}