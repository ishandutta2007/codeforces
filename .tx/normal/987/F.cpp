#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;

template <typename K, typename V = __gnu_pbds::null_type>
using tree = __gnu_pbds::tree<K, V, less<K>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;
using llong = long long;

const int N = 22;

bool has[1 << N];
bool used[1 << N];
bool used2[1 << N];

void dfs2(int v);

void dfs(int v) {
    if (used[v]) {
        return;
    }
    used[v] = true;
    dfs2(((1 << N) - 1) ^ v);
}

void dfs2(int v) {
    if (used2[v]) {
        return;
    }
    used2[v] = true;
    if (has[v]) {
        dfs(v);
    }
    for (int i = 0; i < N; i++) {
        if ((v >> i) & 1) {
            dfs2(v ^ (1 << i));
        }
    }
}

int main() {
#ifdef G13
    freopen("input.txt", "r", stdin);
#endif
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int x;
        cin >> x;
        has[x] = true;
    }

    int ans = 0;
    for (int i = 0; i < (1 << N); i++) {
        if (has[i] && !used[i]) {
            ans++;
            dfs(i);
        }
    }

    cout << ans;

    return 0;
}