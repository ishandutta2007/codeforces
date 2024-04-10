#ifdef VSE
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;

template <typename K, typename V = __gnu_pbds::null_type>
using tree = __gnu_pbds::tree<K, V, less<K>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;
using llong = long long;

int n, s;
int a[1111];
int b[1111];
bool used[1111];

void dfs(int v) {
    used[v] = true;
    for (int i = v + 1; i < n; i++) {
        if (!used[i] && a[i] == 1 && a[v] == 1) {
            dfs(i);
        }
    }
    for (int i = 0; i < v; i++) {
        if (!used[i] && b[i] == 1 && b[v] == 1) {
            dfs(i);
        }
    }
}

int main() {
#ifdef VSE
    freopen("input.txt", "r", stdin);
#endif
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    cin >> n >> s;
    --s;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }

    dfs(0);

    if (used[s]) {
        cout << "YES";
    } else {
        cout << "NO";
    }

    return 0;
}//jymgdp